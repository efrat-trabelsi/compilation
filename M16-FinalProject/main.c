#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern int yyparse();
extern void yyerror(const char *s);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Cannot open file: %s\n", argv[1]);
        return 1;
    }
    
    printf("Starting to parse...\n");
    int result = yyparse();
    
    if (result == 0) {
        printf("Parsing completed successfully!\n");
    } else {
        printf("Parsing failed with errors.\n");
    }
    
    fclose(yyin);
    return result;
}

void yyerror(const char *s) {
    extern int line;
    fprintf(stderr, "line %d: %s\n", line, s);
}
