#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

symbol_t symbol_table[MAX_SYMBOLS];
int symbol_count = 0;
int current_type = INT_TYPE;

int lookup_symbol(char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_symbol(char* name, int type) {
	if (lookup_symbol(name) != -1) {
        yyerror("Variable already declared");
        return;
    }
	strcpy(symbol_table[symbol_count].name, name);
	symbol_table[symbol_count].type = type;
	symbol_table[symbol_count].is_declared = 1;
	symbol_count++;
}

int get_symbol_type(char* name) {
	int index = lookup_symbol(name);
	if (index == -1) {
        yyerror("Variable is not declared");
        return -1;
    }
	return symbol_table[index].type;
}
