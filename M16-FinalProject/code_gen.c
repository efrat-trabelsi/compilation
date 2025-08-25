#include <stdio.h>
#include "code_gen.h"
#include "symbol_table.h"

static int temp_counter = 1;

char* last_expression_result = NULL;
char* prev_temp = NULL;

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

void emit_logical_or(char* left_operand, char* right_operand) {
	char* result_temp = generate_temp_var();
	
    // OR: result = left || right
	printf("IADD %s %s %s\n", result_temp, left_operand, right_operand);
	printf("IGRT %s %s 0\n", result_temp, result_temp);
	fprintf(output_file, "IADD %s %s %s\n", result_temp, left_operand, right_operand);
	fprintf(output_file, "IGRT %s %s 0\n", result_temp, result_temp);
	
	last_expression_result = result_temp;
}

void emit_logical_and(char* left_operand, char* right_operand) {
	char* result_temp = generate_temp_var();
	
	// AND: result = (left != 0) && (right != 0)
	printf("IMLT %s %s %s\n", result_temp, left_operand, right_operand);
	printf("IGRT %s %s 0\n", result_temp, result_temp);
	fprintf(output_file, "IMLT %s %s %s\n", result_temp, left_operand, right_operand);
	fprintf(output_file, "IGRT %s %s 0\n", result_temp, result_temp);
	
	last_expression_result = result_temp;
}

void emit_logical_not(char* operand) {
    char* result_temp = generate_temp_var();
    
    // NOT: result = (expr == 0) ? 1 : 0
    printf("IEQL %s %s 0\n", result_temp, operand);
    fprintf(output_file, "IEQL %s %s 0\n", result_temp, operand);
    
    last_expression_result = result_temp;
}

void emit_relational_op(enum operator op, int left_type, int right_type, char* left_operand, char* right_operand) {
	char* result_temp = generate_temp_var();
	char* opcode;
    
    if (left_type == INT_TYPE && right_type == INT_TYPE) {
        if (op == EQ) opcode = "IEQL";
        else if (op == NE) opcode = "INQL";
        else if (op == LT) opcode = "ILSS";
        else if (op == GT) opcode = "IGRT";
        else if (op == LE) {
            // left <= right === !(left > right)
            printf("IGRT %s %s %s\n", result_temp, left_operand, right_operand);
            printf("IEQL %s %s 0\n", result_temp, result_temp);
            fprintf(output_file, "IGRT %s %s %s\n", result_temp, left_operand, right_operand);
            fprintf(output_file, "IEQL %s %s 0\n", result_temp, result_temp);
            last_expression_result = result_temp;
            return;
        }
        else if (op == GE) {
            // left >= right === !(left < right)
            printf("ILSS %s %s %s\n", result_temp, left_operand, right_operand);
            printf("IEQL %s %s 0\n", result_temp, result_temp);
            fprintf(output_file, "ILSS %s %s %s\n", result_temp, left_operand, right_operand);
            fprintf(output_file, "IEQL %s %s 0\n", result_temp, result_temp);
            last_expression_result = result_temp;
            return;
        }
    } else {
        // at least one of the operands is float
        if (op == EQ) opcode = "REQL";
        else if (op == NE) opcode = "RNQL";
        else if (op == LT) opcode = "RLSS";
        else if (op == GT) opcode = "RGRT";
        else if (op == LE) {
            printf("RGRT %s %s %s\n", result_temp, left_operand, right_operand);
            printf("IEQL %s %s 0\n", result_temp, result_temp);
            fprintf(output_file, "RGRT %s %s %s\n", result_temp, left_operand, right_operand);
            fprintf(output_file, "IEQL %s %s 0\n", result_temp, result_temp);
            last_expression_result = result_temp;
            return;
        }
        else if (op == GE) {
            printf("RLSS %s %s %s\n", result_temp, left_operand, right_operand);
            printf("IEQL %s %s 0\n", result_temp, result_temp);
            fprintf(output_file, "RLSS %s %s %s\n", result_temp, left_operand, right_operand);
            fprintf(output_file, "IEQL %s %s 0\n", result_temp, result_temp);
            last_expression_result = result_temp;
            return;
        }
    }
    
    printf("%s %s %s %s\n", opcode, result_temp, left_operand, right_operand);
    fprintf(output_file, "%s %s %s %s\n", opcode, result_temp, left_operand, right_operand);
    
    last_expression_result = result_temp;
}

void emit_binary_op(enum operator op, int result_type) {
    char* left_operand = prev_temp;      // The result of the left expression / term
    char* right_operand = last_expression_result;  // The result of the right term / factor
    char* result_temp = generate_temp_var();
    
    // Opcode selection by type and operator
	char* opcode;
	if (result_type == INT_TYPE) {
		if (op == PLUS) opcode = "IADD";
		else if (op == MINUS) opcode = "ISUB";
		else if (op == MUL) opcode = "IMLT";
		else if (op == DIV) opcode = "IDIV";
	} else {
		if (op == PLUS) opcode = "RADD";
		else if (op == MINUS) opcode = "RSUB";
		else if (op == MUL) opcode = "RMLT";
		else if (op == DIV) opcode = "RDIV";
	}
    
    // TODO: Add type conversions if required
    
    printf("%s %s %s %s\n", opcode, result_temp, left_operand, right_operand);
    fprintf(output_file, "%s %s %s %s\n", opcode, result_temp, left_operand, right_operand);
    
    last_expression_result = result_temp;  // Update to new result
}

void emit_cast(int from_type, int to_type) {
    char* result_temp = generate_temp_var();
    
    if (from_type == INT_TYPE && to_type == FLOAT_TYPE) {
        printf("ITOR %s %s\n", result_temp, last_expression_result);
        fprintf(output_file, "ITOR %s %s\n", result_temp, last_expression_result);
    } else if (from_type == FLOAT_TYPE && to_type == INT_TYPE) {
        printf("RTOI %s %s\n", result_temp, last_expression_result);
        fprintf(output_file, "RTOI %s %s\n", result_temp, last_expression_result);
    } else {
        // The types are the same - no need to convert
        return;
    }
    
    last_expression_result = result_temp;
}

void emit_load_var(char* var_name) {
    last_expression_result = var_name;
}

void emit_load_constant_int(int value, int type) {
    char* temp = generate_temp_var();
    printf("IASN %s %d\n", temp, value);
    fprintf(output_file, "IASN %s %d\n", temp, value);
    last_expression_result = temp;
}

void emit_load_constant_float(float value, int type) {
    char* temp = generate_temp_var();
    printf("RASN %s %f\n", temp, value);
    fprintf(output_file, "RASN %s %f\n", temp, value);
    last_expression_result = temp;
}

char* generate_temp_var() {
    static char temp_name[20];
    sprintf(temp_name, "temp%d", temp_counter);
    temp_counter++;
    return temp_name;
}
