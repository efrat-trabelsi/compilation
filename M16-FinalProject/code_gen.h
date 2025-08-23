#ifndef CODE_GEN_H
#define CODE_GEN_H

extern FILE* output_file;
extern char* last_expression_result;

void emit_signature();

void emit_quad(char* opcode, char* arg1, char* arg2, char* arg3);

void emit_halt();
void emit_assignment(char* var_name, int var_type, int expr_type);

char* generate_temp_var();

#endif
