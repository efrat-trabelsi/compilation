#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

extern FILE *yyin;
extern int yyparse();
extern void yyerror(const char *s);

FILE* output_file = NULL;
char output_filename[256];

int main(int argc, char **argv) {
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>.ou\n", argv[0]);
        return 1;
    }

    // Check input file extension
    char* filename = argv[1];
    int len = strlen(filename);
    if (len < 4 || strcmp(filename + len - 3, ".ou") != 0) {
        fprintf(stderr, "Error: Input file must have .ou extension\n");
        return 1;
    }

    // Create output filename
    strcpy(output_filename, argv[1]);
    strcpy(output_filename + len - 3, ".qud");
    
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

    // Print signature in stderr
    fprintf(stderr, "// Efrat Trabelsi\n");

    fclose(yyin);
    return result;
}

void yyerror(const char *s) {
    extern int line;
    fprintf(stderr, "Line %d: %s\n", line, s);
}

void yyerror_format(const char* format, ...) {
    va_list args;
    char buffer[1024];

    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    yyerror(buffer);
}
