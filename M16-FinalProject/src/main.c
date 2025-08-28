#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
extern int yyparse();
extern void yyerror(const char *s);

FILE* output_file = NULL;

int main(int argc, char **argv) {
	// Create output filename
	char output_filename[256];
	strcpy(output_filename, argv[1]);
	int len = strlen(argv[1]);
	strcpy(output_filename + len - 3, ".qud");

	// Open output file
	output_file = fopen(output_filename, "w");
	if (!output_file) {
		fprintf(stderr, "Cannot create output file: %s\n", output_filename);
		fclose(yyin);
		return 1;
	}
	
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
    
	fclose(output_file);
    fclose(yyin);
    return result;
}

void yyerror(const char *s) {
    extern int line;
    fprintf(stderr, "line %d: %s\n", line, s);
}
