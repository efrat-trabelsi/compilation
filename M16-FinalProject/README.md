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
├── src/                    # Source code
│   ├── main.c             # Main program
│   ├── cpl.y              # Grammar rules (Bison)
│   ├── cla.lex.txt        # Lexical rules (Flex)
│   ├── symbol_table.c/h   # Symbol table management
│   └── code_gen.c/h       # Code generation
├── tests/                 # Test files
├── Makefile              # Build configuration
└── README.md
```

## Cleaning

```bash
make clean      # Remove generated files
make rebuild    # Clean and rebuild
```

## Error Handling

The compiler performs lexical, syntactic, and semantic analysis. Errors are reported to stderr with line numbers. If errors are found, no output file is generated.
