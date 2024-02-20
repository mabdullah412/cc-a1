%{
#include "minilang.h"
%}
%option nounput yylineno

%%

"int"																return DATATYPE;
"bool"															return DATATYPE;

"if"																return KEYWORD;
"else"															return KEYWORD;
"print"															return KEYWORD;
"true"															return KEYWORD;
"false"															return KEYWORD;

[*]																	return OPERATOR;
[+]																	return OPERATOR;
[-]																	return OPERATOR;
[/]																	return OPERATOR;
"="																	return OPERATOR;
"==="																return OPERATOR;
"!="																return OPERATOR;

[a-zA-Z_][_]*[a-zA-Z0-9_]*					return IDENTIFIER;

[0-9]+															return INT_LITERAL;
"true"															return BOOL_LITERAL;
"false"															return BOOL_LITERAL;

"//"																return COMMENT;

[(){}]															return PARENTHESIS;

['"][A-Z a-z_]*['"]									;
[ \t\n]															;
[;]																	;
.																		printf("[ERROR: UNEXPECTED CHARACTER]\n");

%%

int yywrap(void)
{
	return 1;
}
