#include <stdio.h>
#include <stdlib.h>
#include "list_functions.h"

extern int yyparse(void);
extern FILE *yyin;
extern int line;

void yyerror(const char *s) {
    printf("ERROR: line %d: %s\n", line, s);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input-file-name>\n", argv[0]);
        return 1;
    }
    
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("failed to open %s\n", argv[1]);
        return 2;
    }
    
    yyparse();
    
    fclose(yyin);
    return 0;
}