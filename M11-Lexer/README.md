# CPL Lexical Analyzer (CLA)

Lexical analyzer for CPL (Compiler Project Language).

## System Requirements
- flex (GNU Flex lexical analyzer generator)
- gcc (GNU Compiler Collection)
- Linux WSL

## Running the Compiler

### Build and Run:
```bash
# Generate C file from flex file
flex cla.lex.txt

# Compile the program
gcc -o cla lex.yy.c

# Run the lexical analyzer
./cla <filename>.ou
```

### Example:
```bash
flex cla.lex.txt
gcc -o cla lex.yy.c
./cla cpl-test.ou
```

## Files

### Source Files:
- `cla.lex.txt` - Rules file for flex

### Test Files:
- `cpl-test.ou` - Example of valid input

## Output Format

Output is saved to a file with `.tok` extension:
```
token        lexeme        attribute
-----        ------        ---------
ID           a             a
,	         ,
ID           b             b
:	         :
...
```

## Supported Tokens
- **Reserved Words:** `break`, `case`, `default`, `else`, `float`, `if`, `input`, `int`, `output`, `switch`, `while`
- **Operators:** `+`, `-`, `*`, `/`, `==`, `!=`, `<`, `>`, `>=`, `<=`, `||`, `&&`, `!`
- **Casts:** `cast<int>`, `cast<float>`
- **Identifiers:** Letters and numbers starting with a letter
- **Numbers:** Integers and floats
- **Symbols:** `()`, `{}`, `,`, `:`, `;`, `=`
- **Comments:** `/* ... */` (no nesting)

## Clean Files
```bash
rm lex.yy.c cla *.tok
```

Author: Efrat Trabelsi
