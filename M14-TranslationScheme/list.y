%code {

#include <stdio.h>

extern int yylex (void);
void yyerror (const char *s);

void* tail(void* list) { return list; }
void* append(int n, void* list) { return list; }
void* divide(int n, void* list) { return list; }
void* makelist(int n) { return NULL; }
int sum(void* list) { return 0; }
int equal(void* list) { return 1; }

}

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
	';'
L:	'[' ITEMLIST ']'	{ $$ = $2; }
	';'
L:	TAIL '(' L ')'		{ $$ = tail($3); }
	';'
L:	APPEND '(' ITEM ',' L ')'	{ $$ = append($3, $5); }
	';'
L:	DIVIDE '(' ITEM ',' L ')'	{ $$ = divide($3, $5); }
	';'
ITEMLIST:	ITEMLIST ',' ITEM	{ $$ = append($3, $1); }
	';'
ITEMLIST:	ITEM	{ $$ = makelist($1); }
	';'
ITEM:	SUM '(' L ')'	{ $$ = sum($3); }
	';'
ITEM:	EQUAL '(' L ')'	{ $$ = equal($3); }
	';'
ITEM:	NUMBER	{ $$ = $1; }
	';'

%%

int main (int argc, char **argv)
{
  extern FILE *yyin;
  if (argc != 2) {
     printf("Usage: %s <input-file-name>\n", argv[0]);
	 return 1;
  }
  yyin = fopen (argv [1], "r");
  if (yyin == NULL) {
       printf("failed to open %s\n", argv[1]);
	   return 2;
  }
  
  yyparse ();
  
  fclose (yyin);
  return 0;
}

void yyerror (const char *s)
{
  extern int line;
  printf("ERROR: line %d: %s\n", line, s);
}
