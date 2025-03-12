#pragma warning (disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM 300
#define ID 301

union {
	int ival;
	char name[30];
} yylval;

int demo_lexer()
{
	// lexer reads input from file == yyin
	return NUM;
	return ID;
}

int main(int argc, char** argv)
{
	/*extern*/ FILE* yyin;
	int token;

	if (argc != 2) {
		printf("Usage: %s <input file name>\n", argv[0]);
		exit(1);
	}

	printf("Input file path: %s\n", argv[1]);
	char filename[256];
	get_filename_without_extension(argv[1], filename);
	printf("Extracted file name: %s\n", filename);
	yyin = fopen(argv[1], "r");

	create_output_file("Efrat Trabelsi\n211211211", filename);


	exit(0);

	while (token = demo_lexer() != 0)
	{
		printf("TOKEN  : %s\n", yylval.name);
		switch (token) {
		case NUM:
			printf("NUMBER: %d\n", yylval.ival);
			break;
		case ID:
			printf("ID: %s\n", yylval.name);
			break;
		default:
			fprintf(stderr, "unrecognized character\n");
			exit(1);
		}
	}
	fclose(yyin);
	exit(0);
}