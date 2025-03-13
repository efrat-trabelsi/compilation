%{
%}

%token NUMBER
%token EQUAL
%token SUM
%token APPEND
%token TAIL
%token DIVIDE
…
… (Define all terminals in the grammar.
Symbols such as +, –, (, ) don’t need to be
defined).

%%

//זה בעצם סכימת תרגום?
// need to add here the attributes (synthesized and inherited)
S:	ITEM	{ print(ITEM.val)}
	;
L:	[ ITEMLIST ]	{ L.list = ITEMLIST.list }
	;
L:	TAIL ( L1 )		{ L.list = tail(L1.list) }
	;
L:	APPEND ( ITEM , L1 )	{ L.list = append(ITEM.val, L1.list) }
	;
L:	DIVIDE ( ITEM , L1 )	{ L.list = divide(ITEM.val, L1.list) }
	;
ITEMLIST:	ITEMLIST1 , ITEM	{ ITEMLIST.list = append(ITEM.val, ITEMLIST1.list) }
	;
ITEMLIST:	ITEM	{ ITEMLIST.list = makelist(ITEM.val) }
	;
ITEM:	SUM ( L )	{ ITEM.val = sum(L.list) }
	;
ITEM:	EQUAL ( L )	{ ITEM.val = equal(L.list) }
	;
ITEM:	NUMBER		{ ITEM.val = NUMBER.val }
	;

%%
