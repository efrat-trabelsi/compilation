#include <stdio.h>
#include <string.h>
#include "code_gen.h"
#include "symbol_table.h"

static int temp_counter = 1;

quad_instruction_t instruction_buffer[MAX_INSTRUCTIONS];
int instruction_count = 0;

char* last_expression_result = NULL;
char* prev_temp = NULL;

// switch management
case_entry_t case_table[MAX_CASES];
int case_count = 0;

// break management
static int break_jumps[MAX_INSTRUCTIONS];
static int break_count = 0;

void add_instruction(char* instruction_str) {
    strcpy(instruction_buffer[instruction_count].instruction, instruction_str);
    instruction_buffer[instruction_count].needs_patch = 0;
    instruction_count++;
}

void emit_signature() {
    fprintf(output_file, "// Efrat Trabelsi\n");
}

void emit_halt()
{
	char instruction[256];
	sprintf(instruction, "HALT\n");
	add_instruction(instruction);
	printf("HALT\n");
	write_all_instructions();
}

void emit_assignment(char* var_name, int var_type, int expr_type) {
	char instruction[256];
	
	if (var_type == INT_TYPE && expr_type == INT_TYPE) {
		printf("IASN %s %s\n", var_name, last_expression_result);
		sprintf(instruction, "IASN %s %s\n", var_name, last_expression_result);
		add_instruction(instruction);
	} else if (var_type == FLOAT_TYPE && expr_type == FLOAT_TYPE) {
		printf("RASN %s %s\n", var_name, last_expression_result);
	sprintf(instruction, "RASN %s %s\n", var_name, last_expression_result);
		add_instruction(instruction);
	} else if (var_type == FLOAT_TYPE && expr_type == INT_TYPE) {
		char* temp_float = generate_temp_var();
		printf("ITOR %s %s\n", temp_float, last_expression_result);
		printf("RASN %s %s\n", var_name, temp_float);
		sprintf(instruction, "ITOR %s %s\n", temp_float, last_expression_result);
		add_instruction(instruction);
		sprintf(instruction, "RASN %s %s\n", var_name, temp_float);
		add_instruction(instruction);
	}
}

void emit_input(char* var_name, int var_type) {
	char instruction[256];
	
	if (var_type == INT_TYPE) {
		printf("IINP %s\n", var_name);
		sprintf(instruction, "IINP %s\n", var_name);
		add_instruction(instruction);
	} else if (var_type == FLOAT_TYPE) {
		printf("RINP %s\n", var_name);
		sprintf(instruction, "RINP %s\n", var_name);
		add_instruction(instruction);
	}
}

void emit_output(int expr_type) {
	char instruction[256];
	
	if (expr_type == INT_TYPE) {
		printf("IPRT %s\n", last_expression_result);
		sprintf(instruction, "IPRT %s\n", last_expression_result);
		add_instruction(instruction);
	} else if (expr_type == FLOAT_TYPE) {
		printf("RPRT %s\n", last_expression_result);
		sprintf(instruction, "RPRT %s\n", last_expression_result);
		add_instruction(instruction);
	}
}

void emit_logical_or(char* left_operand, char* right_operand) {
	char* result_temp = generate_temp_var();
	char instruction[256];
	
	printf("IADD %s %s %s\n", result_temp, left_operand, right_operand);
	printf("IGRT %s %s 0\n", result_temp, result_temp);
	
	sprintf(instruction, "IADD %s %s %s\n", result_temp, left_operand, right_operand);
	add_instruction(instruction);
	sprintf(instruction, "IGRT %s %s 0\n", result_temp, result_temp);
	add_instruction(instruction);
	
	last_expression_result = result_temp;
}

void emit_logical_and(char* left_operand, char* right_operand) {
    char* result_temp = generate_temp_var();
    char instruction[256];
    
    printf("IMLT %s %s %s\n", result_temp, left_operand, right_operand);
    printf("IGRT %s %s 0\n", result_temp, result_temp);
    
    sprintf(instruction, "IMLT %s %s %s\n", result_temp, left_operand, right_operand);
    add_instruction(instruction);
    sprintf(instruction, "IGRT %s %s 0\n", result_temp, result_temp);
    add_instruction(instruction);
    
    last_expression_result = result_temp;
}

void emit_logical_not(char* operand) {
    char* result_temp = generate_temp_var();
    char instruction[256];
    
    printf("IEQL %s %s 0\n", result_temp, operand);
    sprintf(instruction, "IEQL %s %s 0\n", result_temp, operand);
    add_instruction(instruction);
    
    last_expression_result = result_temp;
}

void emit_relational_op(enum operator op, int left_type, int right_type, char* left_operand, char* right_operand) {
    char* result_temp = generate_temp_var();
    char* opcode;
    char instruction[256];
    
    if (left_type == INT_TYPE && right_type == INT_TYPE) {
        if (op == EQ) opcode = "IEQL";
        else if (op == NE) opcode = "INQL";
        else if (op == LT) opcode = "ILSS";
        else if (op == GT) opcode = "IGRT";
        else if (op == LE) {
            // left <= right === !(left > right)
            printf("IGRT %s %s %s\n", result_temp, left_operand, right_operand);
            printf("IEQL %s %s 0\n", result_temp, result_temp);
            sprintf(instruction, "IGRT %s %s %s\n", result_temp, left_operand, right_operand);
            add_instruction(instruction);
            sprintf(instruction, "IEQL %s %s 0\n", result_temp, result_temp);
            add_instruction(instruction);
            last_expression_result = result_temp;
            return;
        }
        else if (op == GE) {
            // left >= right === !(left < right)
            printf("ILSS %s %s %s\n", result_temp, left_operand, right_operand);
            printf("IEQL %s %s 0\n", result_temp, result_temp);
            sprintf(instruction, "ILSS %s %s %s\n", result_temp, left_operand, right_operand);
            add_instruction(instruction);
            sprintf(instruction, "IEQL %s %s 0\n", result_temp, result_temp);
            add_instruction(instruction);
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
            sprintf(instruction, "RGRT %s %s %s\n", result_temp, left_operand, right_operand);
            add_instruction(instruction);
            sprintf(instruction, "IEQL %s %s 0\n", result_temp, result_temp);
            add_instruction(instruction);
            last_expression_result = result_temp;
            return;
        }
        else if (op == GE) {
            printf("RLSS %s %s %s\n", result_temp, left_operand, right_operand);
            printf("IEQL %s %s 0\n", result_temp, result_temp);
            sprintf(instruction, "RLSS %s %s %s\n", result_temp, left_operand, right_operand);
            add_instruction(instruction);
            sprintf(instruction, "IEQL %s %s 0\n", result_temp, result_temp);
            add_instruction(instruction);
            last_expression_result = result_temp;
            return;
        }
    }
    
    printf("%s %s %s %s\n", opcode, result_temp, left_operand, right_operand);
    sprintf(instruction, "%s %s %s %s\n", opcode, result_temp, left_operand, right_operand);
    add_instruction(instruction);
    
    last_expression_result = result_temp;
}

void emit_binary_op(enum operator op, int result_type) {
    char* left_operand = prev_temp;
    char* right_operand = last_expression_result;
    char* result_temp = generate_temp_var();
    char instruction[256];
    
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
    
    printf("%s %s %s %s\n", opcode, result_temp, left_operand, right_operand);
    sprintf(instruction, "%s %s %s %s\n", opcode, result_temp, left_operand, right_operand);
    add_instruction(instruction);
    
    last_expression_result = result_temp;
}

void emit_cast(int from_type, int to_type) {
    char* result_temp = generate_temp_var();
    char instruction[256];
    
    if (from_type == INT_TYPE && to_type == FLOAT_TYPE) {
        printf("ITOR %s %s\n", result_temp, last_expression_result);
        sprintf(instruction, "ITOR %s %s\n", result_temp, last_expression_result);
        add_instruction(instruction);
    } else if (from_type == FLOAT_TYPE && to_type == INT_TYPE) {
        printf("RTOI %s %s\n", result_temp, last_expression_result);
        sprintf(instruction, "RTOI %s %s\n", result_temp, last_expression_result);
        add_instruction(instruction);
    } else {
        return; // Same types - no conversion needed
    }
    
    last_expression_result = result_temp;
}

void emit_load_var(char* var_name) {
    last_expression_result = var_name;
}


void emit_load_constant_int(int value, int type) {
    char* temp = generate_temp_var();
    char instruction[256];
    
    printf("IASN %s %d\n", temp, value);
    sprintf(instruction, "IASN %s %d\n", temp, value);
    add_instruction(instruction);
    
    last_expression_result = temp;
}

void emit_load_constant_float(float value, int type) {
    char* temp = generate_temp_var();
    char instruction[256];
    
    printf("RASN %s %f\n", temp, value);
    sprintf(instruction, "RASN %s %f\n", temp, value);
    add_instruction(instruction);
    
    last_expression_result = temp;
}


char* generate_temp_var() {
    static char temp_name[20];
    sprintf(temp_name, "temp%d", temp_counter);
    temp_counter++;
    return temp_name;
}

int emit_jump_placeholder() {
    sprintf(instruction_buffer[instruction_count].instruction, "JUMP %%d\n");
    instruction_buffer[instruction_count].needs_patch = 1;
    instruction_buffer[instruction_count].patch_value = -1;
    
    printf("JUMP <to be patched>\n");
    return instruction_count++;
}

int emit_jump_if_zero_placeholder(char* condition_var) {
    sprintf(instruction_buffer[instruction_count].instruction, "JMPZ %%d %s\n", condition_var);
    instruction_buffer[instruction_count].needs_patch = 1;
    instruction_buffer[instruction_count].patch_value = -1;
    
    printf("JMPZ <to be patched> %s\n", condition_var);
    return instruction_count++;
}

void emit_unconditional_jump(int target) {
    char instruction[256];
    sprintf(instruction, "JUMP %d\n", target);
    add_instruction(instruction);
    printf("JUMP %d\n", target);
}

void write_all_instructions() {
    for (int i = 0; i < instruction_count; i++) {
        if (instruction_buffer[i].needs_patch) {
            fprintf(output_file, instruction_buffer[i].instruction, 
                   instruction_buffer[i].patch_value);
        } else {
            fprintf(output_file, "%s", instruction_buffer[i].instruction);
        }
    }
}

void patch_instruction(int instruction_index, int target) {
    instruction_buffer[instruction_index].patch_value = target;
}

int get_current_instruction() {
    return instruction_count + 1; // start from 1
}

void emit_switch_start(char* switch_var) {
    // init cases count
    case_count = 0;
}

int emit_case_jump_placeholder(int case_value, char* switch_var) {
    char* temp = generate_temp_var();
    char instruction[256];
    
    // compare to case
    sprintf(instruction, "IEQL %s %s %d\n", temp, switch_var, case_value);
    add_instruction(instruction);
    printf("IEQL %s %s %d\n", temp, switch_var, case_value);
    
    // jump if equal
    int jump_index = emit_jump_if_zero_placeholder(temp);
    
    case_table[case_count].case_value = case_value;
    case_table[case_count].jump_instruction_index = jump_index;
    case_count++;
    
    return jump_index;
}

void patch_case_jumps(int end_label) {
    for (int i = 0; i < case_count; i++) {
        patch_instruction(case_table[i].jump_instruction_index, end_label);
    }
}

void reset_case_table() {
    case_count = 0;
}

void add_break_jump(int instruction_index) {
    if (break_count < MAX_INSTRUCTIONS) {
        break_jumps[break_count] = instruction_index;
        break_count++;
    }
}

void patch_all_breaks(int target) {
    for (int i = 0; i < break_count; i++) {
        patch_instruction(break_jumps[i], target);
    }
    break_count = 0;
}
