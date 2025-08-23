#include <stdio.h>
#include "code_gen.h"
#include "symbol_table.h"

static int temp_counter = 1;

char* last_expression_result = NULL;

void emit_signature() {
    fprintf(output_file, "// Efrat Trabelsi\n");
}

void emit_halt()
{
	printf("HALT\n");
	fprintf(output_file, "HALT\n");
}

void emit_assignment(char* var_name, int var_type, int expr_type) {
    if (var_type == INT_TYPE && expr_type == INT_TYPE) {
        printf("IASN %s %s\n", var_name, last_expression_result);
        fprintf(output_file, "IASN %s %s\n", var_name, last_expression_result);
    } else if (var_type == FLOAT_TYPE && expr_type == FLOAT_TYPE) {
        printf("RASN %s %s\n", var_name, last_expression_result);
        fprintf(output_file, "RASN %s %s\n", var_name, last_expression_result);
    } else if (var_type == FLOAT_TYPE && expr_type == INT_TYPE) {
        char* temp_float = generate_temp_var();
        printf("ITOR %s %s\n", temp_float, last_expression_result);
        printf("RASN %s %s\n", var_name, temp_float);
        fprintf(output_file, "ITOR %s %s\n", temp_float, last_expression_result);
        fprintf(output_file, "RASN %s %s\n", var_name, temp_float);
    }
}

char* generate_temp_var() {
    static char temp_name[20];
    sprintf(temp_name, "temp%d", temp_counter);
    temp_counter++;
    return temp_name;
}
