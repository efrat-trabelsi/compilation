# CPL Compiler

A compiler that translates CPL (Compiler Project Language) programs to Quad intermediate language.

## Building the Compiler

### Prerequisites
- `gcc` compiler
- `flex` lexical analyzer generator  
- `bison` parser generator

### Build Instructions
```bash
make
```

This will generate the `cpq` executable.

## Usage

```bash
./cpq <input_file>.ou
```

The compiler expects input files with `.ou` extension and generates output files with `.qud` extension containing the Quad code.

**Example:**
```bash
./cpq tests/test1.ou
```
This creates `tests/test1.qud`.

## Project Structure

```
project_root/
├── src/                   # Source code
│   ├── cpq.c              # Main program
│   ├── cpl.y              # Grammar rules (Bison)
│   ├── cla.lex.txt        # Lexical rules (Flex)
│   ├── symbol_table.c/h   # Symbol table management
│   └── code_gen.c/h       # Code generation
├── tests/                 # Test files
│   ├── test1.ou
│   ├── test2.ou
│   ├── test3.ou
│   ├── test4.ou
│   ├── test5.ou
│   ├── test6.ou
│   ├── test7.ou
│   ├── test8.ou
│   └── test9.ou
├── Makefile              # Build configuration
├── test_runner.py        # Test runner script
└── README.md
```

## Testing

Run all tests:
```bash
make test
```

Run a specific test:
```bash
python3 test_runner.py test1
```

Clean test output files:
```bash
make test-clean
```

## Cleaning

```bash
make clean      # Remove generated files
make clean-all  # Remove all generated files including test outputs
make rebuild    # Clean and rebuild
```

## Error Handling

The compiler performs lexical, syntactic, and semantic analysis. Errors are reported to stderr with line numbers. If errors are found, no output file is generated.
