%{

#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "code_gen.h"

extern int yylex (void);
extern int line;

int has_errors = 0;

%}

%code requires {
   enum operator {PLUS, MINUS, MUL, DIV, EQ, NE, LT, GT, GE, LE };
}

%union {
  struct {
    union {
      int ival;
      float fval;
    };
    int type;  // INT_TYPE or FLOAT_TYPE
  } num_val;
  char name[30];
  enum operator op;
  int cast_type;
};

%token<name> ID
%token<num_val> NUM

%token BREAK
%token CASE
%token DEFAULT
%token ELSE
%token FLOAT
%token IF
%token INPUT
%token INT
%token OUTPUT
%token SWITCH
%token WHILE

%token<op> RELOP
%token<op> ADDOP
%token<op> MULOP
%token OR
%token AND
%token NOT
%token<cast_type> CAST

%type<cast_type> type

%left OR
%left AND
%left RELOP
%left ADDOP
%left MULOP
%right NOT

%%

program: declarations stmt_block
		{
			if (!has_errors) {
				emit_halt();
			}
		}
		;
declarations: declarations declaration
			| %empty
			;
declaration: idlist ':' type ';'
			{
				printf("Declaration: type %d\n", $3);
				current_type = $3;
			}
			;
type: INT
	{ $$ = INT_TYPE; }
	| FLOAT
	{ $$ = FLOAT_TYPE; }
	;
idlist: idlist ',' ID
		{
		  if (lookup_symbol($3) != -1) {
			fprintf(stderr, "line %d: variable '%s' already declared\n", line, $3);
			has_errors = 1;
			} else {
				add_symbol($3, current_type);
			}
		}
		| ID {
			if (lookup_symbol($1) != -1) {
				fprintf(stderr, "line %d: variable '%s' already declared\n", line, $1);
				has_errors = 1;
			} else {
				add_symbol($1, current_type);
				current_type = INT_TYPE; // Reset for next declaration
			}
		}
	  ;
stmt: assignment_stmt
	| input_stmt
	| output_stmt
	| if_stmt
	| while_stmt
	| switch_stmt
	| break_stmt
	| stmt_block
	;
assignment_stmt: ID '=' expression ';'
				{ printf("Assignment to %s\n", $1); }
				;
input_stmt: INPUT '(' ID ')' ';'
			{ printf("Input to %s\n", $3); }
			;
output_stmt: OUTPUT '(' expression ')' ';'
			{ printf("Output statement\n"); }
			;
if_stmt: IF '(' boolexpr ')' stmt ELSE stmt
		{ printf("If-Else statement\n"); }
		;
while_stmt: WHILE '(' boolexpr ')' stmt
			{ printf("While statement\n"); }
			;
switch_stmt: SWITCH '(' expression ')' '{' caselist DEFAULT ':' stmtlist '}'
			{ printf("Switch statement\n"); }
			;
caselist: caselist CASE NUM ':' stmtlist
		{ 
			if ($3.type != INT_TYPE) {
				yyerror("Case value must be integer");
			} else {
				printf("Case %d\n", $3.ival);
			}
		}
		| %empty
		;
break_stmt: BREAK ';'
			{ printf("Break statement\n"); }
			;
stmt_block: '{' stmtlist '}'
			{ printf("Statement block\n"); }
			;
stmtlist: stmtlist stmt
		| %empty
		;
boolexpr: boolexpr OR boolterm
		{ printf("Boolean OR\n"); }
		| boolterm
		;
boolterm: boolterm AND boolfactor
		{ printf("Boolean AND\n"); }
		| boolfactor
		;
boolfactor: NOT '(' boolexpr ')'
		  { printf("Boolean NOT\n"); }
		  | expression RELOP expression
		  { printf("Relational operation\n"); }
		  ;
expression: expression ADDOP term
		  { printf("Addition/Subtraction\n"); }
		  | term
		  ;
term: term MULOP factor
	{ printf("Multiplication/Division\n"); }
	| factor
	;
factor: '(' expression ')'
	  { printf("Parenthesized expression\n"); }
	  | CAST '(' expression ')'
	  { printf("Cast expression\n"); }
	  | ID
	  { printf("Identifier: %s\n", $1); }
	  | NUM
	  {
	    if ($1.type == INT_TYPE) {
			printf("Int: %d\n", $1.ival);
		} else {
			printf("Float: %f\n", $1.fval);
        }
	  }
	  ;

%%
