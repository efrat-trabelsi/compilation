#!/usr/bin/env python3
import os
import subprocess
import sys
import re
from pathlib import Path

def extract_expected_output(test_file):
    """Extract expected QUAD output from test file comments"""
    with open(test_file, 'r') as f:
        content = f.read()
    
    # Find the expected output in comments
    match = re.search(r'/\*\s*Expected.*?:\s*(.*?)\*/', content, re.DOTALL)
    if match:
        lines = match.group(1).strip().split('\n')
        # Filter out empty lines and "Expected" lines, but keep signature comments
        expected = []
        for line in lines:
            line = line.strip()
            if line and not line.startswith('Expected'):
                expected.append(line)
        return '\n'.join(expected) + '\n'
    return ""

def run_test(test_name):
    """Run a single test and compare output"""
    test_file = f"tests/{test_name}.ou"
    output_file = f"tests/{test_name}.qud"
    
    if not os.path.exists(test_file):
        print(f"❌ Test file {test_file} not found")
        return False
    
    # Remove existing output file if it exists
    if os.path.exists(output_file):
        os.remove(output_file)
    
    # Run compiler
    result = subprocess.run(['./cpq', test_file], 
                          capture_output=True, text=True)
    
    # Extract expected output
    expected_output = extract_expected_output(test_file)
    expected_stderr = ""
    
    # Check if this is an error test (contains error comments)
    with open(test_file, 'r') as f:
        content = f.read()
        if "Error:" in content:
            # Extract expected error messages
            error_lines = re.findall(r'/\*.*?Error: (.*?)\*/', content)
            expected_stderr = '\n'.join([f"line {i+1}: {err}" for i, err in enumerate(error_lines, 1)])
            expected_output = ""  # No output file expected for error cases
    
    # Check results
    success = True
    
    if expected_stderr:
        # Error test case
        if result.returncode == 0:
            print(f"❌ {test_name}: Expected errors but compilation succeeded")
            success = False
        elif expected_stderr.strip() not in result.stderr.strip():
            print(f"❌ {test_name}: STDERR mismatch")
            print(f"Expected: {expected_stderr.strip()}")
            print(f"Got: {result.stderr.strip()}")
            success = False
        else:
            print(f"✅ {test_name}: Error handling correct")
    else:
        # Success test case
        if result.returncode != 0:
            print(f"❌ {test_name}: Compilation failed")
            print(f"STDERR: {result.stderr}")
            success = False
        elif not os.path.exists(output_file):
            print(f"❌ {test_name}: Output file not created")
            success = False
        else:
            with open(output_file, 'r') as f:
                actual_output = f.read()
            
            if actual_output.strip() != expected_output.strip():
                print(f"❌ {test_name}: Output mismatch")
                print(f"Expected:\n{expected_output}")
                print(f"Got:\n{actual_output}")
                success = False
            else:
                print(f"✅ {test_name}: Passed")
    
    return success

def main():
    if not os.path.exists('./cpq'):
        print("❌ Compiler 'cpq' not found. Run 'make' first.")
        return 1
    
    if len(sys.argv) == 2:
        # Run specific test
        test_name = sys.argv[1]
        if test_name.endswith('.ou'):
            test_name = test_name[:-3]
        return 0 if run_test(test_name) else 1
    else:
        # Run all tests
        test_files = list(Path('tests').glob('test*.ou'))
        if not test_files:
            print("❌ No test files found in tests/ directory")
            return 1
        
        passed = 0
        total = len(test_files)
        
        for test_file in sorted(test_files):
            test_name = test_file.stem
            if run_test(test_name):
                passed += 1
        
        print(f"\nResults: {passed}/{total} tests passed")
        return 0 if passed == total else 1

if __name__ == "__main__":
    sys.exit(main())
