%{

#include <stdio.h>
#include <stdlib.h>
#include "list_functions.h"

extern int yylex (void);
void yyerror (const char *s);

%}

%union {
    int ival;
    void* lst;
}

%token<ival> NUMBER
%token EQUAL
%token SUM
%token APPEND
%token TAIL
%token DIVIDE

%type <ival> ITEM
%type <lst> L ITEMLIST

%%

S:	ITEM	{ printf("%d\n", $1); }
	;
L:	'[' ITEMLIST ']'	{ $$ = $2; }
	;
L:	TAIL '(' L ')'		{ $$ = tail($3); }
	;
L:	APPEND '(' ITEM ',' L ')'	{ $$ = append($3, $5); }
	;
L:	DIVIDE '(' ITEM ',' L ')'	{ $$ = divide($3, $5); }
	;
ITEMLIST:	ITEMLIST ',' ITEM	{ $$ = append($3, $1); }
	;
ITEMLIST:	ITEM	{ $$ = makelist($1); }
	;
ITEM:	SUM '(' L ')'	{ $$ = sum($3); }
	;
ITEM:	EQUAL '(' L ')'	{ $$ = equal($3); }
	;
ITEM:	NUMBER	{ $$ = $1; }
	;

%%
