%{
/*
 * 识别double 加减乘除 括号 
 */
#define YYSTYPE double 
#include "float.tab.h"
%}

%%

[0-9]+[.][0-9]+  {yylval = atof(yytext); return T_NUM; }
[0-9]+           {yylval = atof(yytext); return T_NUM; }
[-/+*()\n]      { return yytext[0]; }

%%

int yywrap(){
    return 1;
}