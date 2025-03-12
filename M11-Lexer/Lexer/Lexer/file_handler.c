#pragma warning (disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void create_output_file(const char* str, const char* filename)
{
	strcat(filename, ".tok");

	FILE* file = fopen(filename, "w");
	if (!file) {
		perror("Error opening file for writing");
		exit(1);
	}

	fprintf(file, "%s", str);
	fclose(file);

	printf("Output written to %s\n", filename);
}