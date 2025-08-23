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

void emit_input(char* var_name, int var_type) {
    if (var_type == INT_TYPE) {
        printf("IINP %s\n", var_name);
        fprintf(output_file, "IINP %s\n", var_name);
    } else if (var_type == FLOAT_TYPE) {
        printf("RINP %s\n", var_name);
        fprintf(output_file, "RINP %s\n", var_name);
    }
}

void emit_output(int expr_type) {
    if (expr_type == INT_TYPE) {
        printf("IPRT %s\n", last_expression_result);
        fprintf(output_file, "IPRT %s\n", last_expression_result);
    } else if (expr_type == FLOAT_TYPE) {
        printf("RPRT %s\n", last_expression_result);
        fprintf(output_file, "RPRT %s\n", last_expression_result);
    }
}

char* generate_temp_var() {
    static char temp_name[20];
    sprintf(temp_name, "temp%d", temp_counter);
    temp_counter++;
    return temp_name;
}
