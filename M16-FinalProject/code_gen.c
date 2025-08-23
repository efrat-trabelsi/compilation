#include <stdio.h>
#include "code_gen.h"

void emit_signature() {
    fprintf(output_file, "// Efrat Trabelsi\n");
}

void emit_halt()
{
	printf("HALT\n");
	fprintf(output_file, "HALT\n");
}