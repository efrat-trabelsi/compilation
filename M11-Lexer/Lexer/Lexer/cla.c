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

#pragma region TokenDescription

typedef struct td {
	char* token;
	char* lexeme;
	char* attribute;
	struct td* next;
} token_description;

token_description* create_token(const char* token, const char* lexeme, const char* attribute) {
	token_description* newToken = (token_description*)malloc(sizeof(token_description));
	if (!newToken) {
		perror("Memory allocation failed");
		exit(1);
	}

	newToken->token = strdup(token);
	newToken->lexeme = strdup(lexeme);
	newToken->attribute = strdup(attribute);
	newToken->next = NULL;
	return newToken;
}

void append_token(token_description** head, const char* token, const char* lexeme, const char* attribute) {
	token_description* newToken = create_token(token, lexeme, attribute);
	if (*head == NULL) {
		*head = newToken;
		return;
	}

	token_description* temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newToken;
}

void free_tokens(token_description* head) {
	token_description* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp->token);
		free(temp->lexeme);
		free(temp->attribute);
		free(temp);
	}
}

void process_token_list(token_description* head) {
	token_description* temp = head;
	while (temp != NULL) {
		printf("Token: %s, Lexeme: %s, Attribute: %s\n",
			temp->token, temp->lexeme, temp->attribute);
		temp = temp->next;
	}
}

#pragma endregion

#pragma region FileHandler

void get_filename_without_extension(const char* filepath, char* output) {
	// Step 1: Extract the file name (remove directories)
	const char* filename = strrchr(filepath, '/'); // Look for last '/'
	if (!filename) {
		filename = strrchr(filepath, '\\'); // Handle Windows paths
	}
	filename = (filename) ? filename + 1 : filepath; // Move past '/' or use full path

	// Step 2: Remove the extension
	char* dot = strrchr(filename, '.'); // Find the last '.'
	size_t len = (dot) ? (size_t)(dot - filename) : strlen(filename); // Get length without extension

	// Copy the filename (without extension) to output
	strncpy(output, filename, len);
	output[len] = '\0';
}

void create_output_file(token_description* head, const char* filename)
{
	strcat(filename, ".tok");

	FILE* file = fopen(filename, "w");
	if (!file) {
		perror("Error opening file for writing");
		exit(1);
	}

	fprintf(file, "%s", "Efrat Trabelsi\n211211211\n\n");
	fprintf(file, "%s", "token\t\tlexeme\t\tattribute\n");
	fprintf(file, "%s", "-----\t\t------\t\t---------\n");
	token_description* temp = head;
	while (temp != NULL)
	{
		fprintf(file, "%s\t\t\t%s\t\t\t%s\n", temp->token, temp->lexeme, temp->attribute);
		temp = temp->next;
	}
	fclose(file);

	printf("Output written to %s\n", filename);
}

#pragma endregion


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

#pragma region list example
	token_description* tokens = create_token("ID", "foo", "foo");
	append_token(&tokens, "NUM", "=", "");
	append_token(&tokens, "ID", "bar", "bar");
	append_token(&tokens, "NUM", ";", "");
#pragma endregion


	create_output_file(tokens, filename);


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