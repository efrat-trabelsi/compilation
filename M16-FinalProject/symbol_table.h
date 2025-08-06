#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_SYMBOLS 1000
#define MAX_NAME_LEN 32

#define INT_TYPE 0
#define FLOAT_TYPE 1

typedef struct {
    char name[MAX_NAME_LEN];
    int type;
    int is_declared;
} symbol_t;

extern int current_type;
extern symbol_t symbol_table[MAX_SYMBOLS];
extern int symbol_count;

int lookup_symbol(char* name);
void add_symbol(char* name, int type);
int get_symbol_type(char* name);

extern void yyerror (const char *s);

#endif
