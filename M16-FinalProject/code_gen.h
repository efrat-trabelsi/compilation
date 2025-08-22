#ifndef CODE_GEN_H
#define CODE_GEN_H

void emit_quad(char* opcode, char* arg1, char* arg2, char* arg3);

void emit_halt();

char* generate_temp_var();

#endif
