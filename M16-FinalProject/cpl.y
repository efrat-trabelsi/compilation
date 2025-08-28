%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "code_gen.h"

extern char* last_expression_result;
extern char* prev_temp;

int in_loop = 0;
int in_switch = 0;

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
  struct {
    int type;
    char temp_name[30];
  } expr_val;
  int type_val;
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

%type<type_val> type
%type<expr_val> expression term factor boolexpr boolterm boolfactor

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
				emit_signature();
			}
		}
		;
declarations: declarations declaration
			| %empty
			;
declaration: idlist ':' type ';'
			{
				printf("Declaration: type %s\n", $3==0? "INT": "FLOAT");
				update_idlist_types($3);
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
				add_symbol($3, -1);
				mark_pending_symbol($3);
			}
		}
		| ID {
			if (lookup_symbol($1) != -1) {
				fprintf(stderr, "line %d: variable '%s' already declared\n", line, $1);
				has_errors = 1;
			} else {
				add_symbol($1, -1);
				mark_pending_symbol($1);
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
				{
					int var_index = lookup_symbol($1);
					if (var_index == -1) {
						fprintf(stderr, "line %d: variable '%s' not declared\n", line, $1);
						has_errors = 1;
					} else {
						int var_type = get_symbol_type($1);
						int expr_type = $3.type;
						
						if (var_type == expr_type || 
							(var_type == FLOAT_TYPE && expr_type == INT_TYPE)) {
							printf("Assignment to %s (type compatible)\n", $1);
							last_expression_result = $3.temp_name;
							emit_assignment($1, var_type, expr_type);
						} else {
							fprintf(stderr, "line %d: type mismatch in assignment to '%s'\n", line, $1);
							has_errors = 1;
						}
					} 
				}
				;
input_stmt: INPUT '(' ID ')' ';'
			{
				int var_index = lookup_symbol($3);
				if (var_index == -1) {
					fprintf(stderr, "line %d: variable '%s' not declared\n", line, $3);
					has_errors = 1;
				} else {
					int var_type = get_symbol_type($3);
					printf("Input to %s (type: %s)\n", $3, 
						   var_type == INT_TYPE ? "int" : "float");
					emit_input($3, var_type);
				}
			}
			;
output_stmt: OUTPUT '(' expression ')' ';'
			{
				int expr_type = $3.type;
				printf("Output statement (type: %s)\n", 
					   expr_type == INT_TYPE ? "int" : "float");
				last_expression_result = $3.temp_name;
				emit_output(expr_type);
			}
			;
if_stmt: IF '(' boolexpr ')'
		{
			// שמור את התווית לקפיצה אחרי ELSE
			$<type_val>$ = emit_jump_if_zero_placeholder($3.temp_name);
		}
		stmt ELSE
		{
			$<type_val>7 = emit_jump_placeholder();
			patch_instruction($<type_val>5, instruction_count + 1);
		}
		stmt
		{
			patch_instruction($<type_val>7, instruction_count + 1);
			printf("If-Else statement completed\n");
		}
		;
while_stmt: WHILE
			{
				in_loop++;
				$<type_val>$ = instruction_count + 1;
			}
			'(' boolexpr ')'
			{
				$<type_val>$ = emit_jump_if_zero_placeholder($4.temp_name);
			}
			stmt
			{
				emit_unconditional_jump($<type_val>2);
				patch_instruction($<type_val>6, instruction_count + 1);
				patch_all_breaks(instruction_count + 1);
				in_loop--;
				printf("While statement completed\n");
			}
			;
switch_stmt: SWITCH '(' expression ')' '{'
			{
				if ($3.type != INT_TYPE) {
					fprintf(stderr, "line %d: switch expression must be integer\n", line);
					has_errors = 1;
				}
				in_switch++;
				emit_switch_start($3.temp_name);
				strcpy($<expr_val>$.temp_name, $3.temp_name);
			}
			caselist DEFAULT ':' stmtlist '}'
			{
				patch_case_jumps(get_current_instruction());
				patch_all_breaks(instruction_count + 1);
				in_switch--;
				reset_case_table();
				printf("Switch statement completed\n");
			}
			;
caselist: caselist CASE NUM ':'
		{
			if ($3.type != INT_TYPE) {
				fprintf(stderr, "line %d: case value must be integer\n", line);
				has_errors = 1;
			} else {
				emit_case_jump_placeholder($3.ival, $<expr_val>0.temp_name);
				printf("Case %d\n", $3.ival);
             }
		}
		stmtlist
		| %empty
		;
break_stmt: BREAK ';'
			{
				if (in_loop == 0 && in_switch == 0) {
					fprintf(stderr, "line %d: break statement not within loop or switch\n", line);
					has_errors = 1;
				} else {
					int break_jump = emit_jump_placeholder();
					add_break_jump(break_jump);
					printf("Break statement\n");
				}
			}
			;
stmt_block: '{' stmtlist '}'
			{ 
				printf("Statement block\n"); 
			}
			;
stmtlist: stmtlist stmt
		| %empty
		;
boolexpr: boolexpr OR boolterm
		{
			printf("Boolean OR\n");
			emit_logical_or($1.temp_name, $3.temp_name);
			$$.type = INT_TYPE;
			strcpy($$.temp_name, last_expression_result);		
		}
		| boolterm
		{
			$$.type = $1.type;
			strcpy($$.temp_name, $1.temp_name);
		}
		;
boolterm: boolterm AND boolfactor
		{
			printf("Boolean AND\n");
			emit_logical_and($1.temp_name, $3.temp_name);
			$$.type = INT_TYPE;
			strcpy($$.temp_name, last_expression_result);
		}
		| boolfactor
		{
			$$.type = $1.type;
			strcpy($$.temp_name, $1.temp_name);
		}
		;
boolfactor: NOT '(' boolexpr ')'
		  {
			printf("Boolean NOT\n");
			emit_logical_not($3.temp_name);
			$$.type = INT_TYPE;
			strcpy($$.temp_name, last_expression_result);
		  }
		  | expression RELOP expression
		  {
			printf("Relational operation\n");
			emit_relational_op($2, $1.type, $3.type, $1.temp_name, $3.temp_name);
			$$.type = INT_TYPE;
			strcpy($$.temp_name, last_expression_result);
		  }
		  ;
expression: expression ADDOP term
		  {
			int left_type = $1.type;
			int right_type = $3.type;
			int result_type = (left_type == FLOAT_TYPE || right_type == FLOAT_TYPE) 
								? FLOAT_TYPE : INT_TYPE;
			prev_temp = $1.temp_name;
			last_expression_result = $3.temp_name;
			emit_binary_op($2, result_type);
			
			$$.type = result_type;
			strcpy($$.temp_name, last_expression_result);
			
            printf("Addition/Subtraction (result type: %s)\n", 
                   result_type == INT_TYPE ? "int" : "float");
          }
          | term
		  {
			$$.type = $1.type;
			strcpy($$.temp_name, $1.temp_name);
		  }
		  ;

term: term MULOP factor
    {
	  int left_type = $1.type;
	  int right_type = $3.type;
	  int result_type = (left_type == FLOAT_TYPE || right_type == FLOAT_TYPE) 
	  					? FLOAT_TYPE : INT_TYPE;
	  prev_temp = $1.temp_name;
	  last_expression_result = $3.temp_name;
	  emit_binary_op($2, result_type);
	  $$.type = result_type;
	  strcpy($$.temp_name, last_expression_result);
	  
	  printf("Multiplication/Division (result type: %s)\n", 
			 result_type == INT_TYPE ? "int" : "float");
	}
	| factor
	{
	  $$.type = $1.type;
	  strcpy($$.temp_name, $1.temp_name);
	}
	;

factor: '(' expression ')'
	  {
		printf("Parenthesized expression\n");
		$$.type = $2.type;
		strcpy($$.temp_name, $2.temp_name);
	  }
	  | CAST '(' expression ')'
	  {
		printf("Cast expression to %s\n", $1 == INT_TYPE ? "int" : "float");
		last_expression_result = $3.temp_name;
		emit_cast($3.type, $1);
		
		$$.type = $1;
		strcpy($$.temp_name, last_expression_result);
	  }
	  | ID
	  {
		int var_type = get_symbol_type($1);
		if (var_type == -1) {
		  fprintf(stderr, "line %d: variable '%s' not declared\n", line, $1);
		  has_errors = 1;
		  $$.type = INT_TYPE;
		  strcpy($$.temp_name, "error_var");
		} else {
		  printf("Identifier: %s (type: %s)\n", $1, var_type == INT_TYPE ? "int" : "float");
		  emit_load_var($1);
		  
		  $$.type = var_type;
		  strcpy($$.temp_name, last_expression_result);
		}
	  }
	  | NUM
	  {
		if ($1.type == INT_TYPE) {
		  printf("Int: %d\n", $1.ival);
		  emit_load_constant_int($1.ival, $1.type);
		} else {
		  printf("Float: %f\n", $1.fval);
		  emit_load_constant_float($1.fval, $1.type);
		}
		
		$$.type = $1.type;
		strcpy($$.temp_name, last_expression_result);
	  }
	  ;

%%
