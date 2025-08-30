#ifndef CODE_GEN_H
#define CODE_GEN_H

#include "cpl.tab.h"

#define MAX_INSTRUCTIONS 10000
#define MAX_CASES 100

// struct for backpatching
typedef struct {
    char instruction[256];  // The instruction with placeholder
    int needs_patch;        // Is fix needed
    int patch_value;        // The value for fix
} quad_instruction_t;

typedef struct {
    int case_value;
    int jump_instruction_index;
    int next_case_location;
} case_entry_t;


extern FILE* output_file;
extern char output_filename[256];

extern char* last_expression_result;
extern char* prev_temp;  // Save the left expression result

extern quad_instruction_t instruction_buffer[MAX_INSTRUCTIONS];
extern int instruction_count;

extern case_entry_t case_table[MAX_CASES];
extern int case_count;

void emit_and_add(const char* format, ...);
void emit_signature();

void create_output_file();
void write_all_instructions();
void add_instruction(char* instruction_str);

void emit_halt();
void emit_assignment(char* var_name, int var_type, int expr_type);
void emit_input(char* var_name, int var_type);
void emit_output(int expr_type);
void emit_logical_or(char* left_operand, char* right_operand);
void emit_logical_and(char* left_operand, char* right_operand);
void emit_logical_not(char* operand);
void emit_relational_op(enum operator op, int left_type, int right_type, char* left_operand, char* right_operand);
void emit_binary_op(enum operator op, int result_type);
void emit_cast(int from_type, int to_type);
void emit_load_var(char* var_name);
void emit_load_constant_int(int value, int type);
void emit_load_constant_float(float value, int type);

int emit_jump_placeholder();
int emit_jump_if_zero_placeholder(char* condition_var);
void emit_unconditional_jump(int target);
void patch_instruction(int instruction_index, int target);
int get_current_instruction();

// switch statement management
void emit_switch_start(char* switch_var);
int emit_case_jump_placeholder(int case_value, char* switch_var);
void reset_case_table();

// break statement management
void add_break_jump(int instruction_index);
void patch_all_breaks(int target);

char* generate_temp_var();

#endif
