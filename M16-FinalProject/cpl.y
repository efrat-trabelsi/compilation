%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex (void);
void yyerror (const char *s);

%}

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

%token RELOP
%token ADDOP
%token MULOP
%token OR
%token AND
%token NOT
%token CAST

%code requires {
   enum operator {PLUS, MINUS, MUL, DIV, EQ, NE, LT, GT, GE, LE };
}

%union {
  struct {
    union {
      int ival;
      float fval;
    };
    int type;  // INT or FLOAT
  } num_val;
  char name[30];
  enum operator op;
  int cast_type;
};

%%

program: declarations stmt_block
		{ printf("Parsed program successfully!\n"); }
		;
declarations: declarations declaration
			| %empty
			;
declaration: idlist ':' type ';'
			;
type: INT
	| FLOAT
	;
idlist: idlist ',' ID
	  | ID
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
			if ($3.type != INT) {
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
	    if ($1.type == INT) {
			printf("Int: %d\n", $1.ival);
		} else {
			printf("Float: %f\n", $1.fval);
        }
	  }
	  ;

%%
