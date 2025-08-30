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
    match = re.search(r'/\*\s*Expected.*?translation to QUAD:(.*?)\*/', content, re.DOTALL | re.IGNORECASE)
    if match:
        lines = match.group(1).strip().split('\n')
        expected = []
        for line in lines:
            line = line.strip()
            if line and not line.startswith('Expected'):
                expected.append(line)
        return '\n'.join(expected) + '\n'
    return ""

def extract_expected_stderr(test_file):
    """Extract expected STDERR from test file comments"""
    with open(test_file, 'r') as f:
        content = f.read()
    
    # Find the expected STDERR in comments
    match = re.search(r'/\*\s*Expected.*?STDERR:(.*?)\*/', content, re.DOTALL | re.IGNORECASE)
    if match:
        lines = match.group(1).strip().split('\n')
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
    
    # Extract expected outputs
    expected_output = extract_expected_output(test_file)
    expected_stderr = extract_expected_stderr(test_file)
    
    success = True
    
    if expected_stderr:
        # Error test case - check STDERR
        if expected_stderr.strip() != result.stderr.strip():
            print(f"❌ {test_name}: STDERR mismatch")
            print(f"Expected:\n{expected_stderr.strip()}")
            print(f"Got:\n{result.stderr.strip()}")
            success = False
        
        # Should not create output file on errors
        if os.path.exists(output_file):
            print(f"❌ {test_name}: Output file created despite errors")
            success = False
        
        if success:
            print(f"✅ {test_name}: Error handling correct")
    else:
        # Success test case - check output file
        if result.returncode != 0:
            print(f"❌ {test_name}: Compilation failed")
            print(f"STDERR:\n{result.stderr}")
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
