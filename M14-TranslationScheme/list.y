%{
%}

%token NUMBER
%token EQUAL
%token SUM
%token APPEND
%token TAIL
%token DIVIDE

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
