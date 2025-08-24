#ifndef CODE_GEN_H
#define CODE_GEN_H

#include "cpl.tab.h"

extern FILE* output_file;
extern char* last_expression_result;
extern char* prev_temp;  // Save the left expression result

void emit_signature();

void emit_quad(char* opcode, char* arg1, char* arg2, char* arg3);

void emit_halt();
void emit_assignment(char* var_name, int var_type, int expr_type);
void emit_input(char* var_name, int var_type);
void emit_output(int expr_type);
void emit_binary_op(enum operator op, int result_type);
void emit_cast(int from_type, int to_type);
void emit_load_var(char* var_name);
void emit_load_constant_int(int value, int type);
void emit_load_constant_float(float value, int type);

char* generate_temp_var();

#endif
