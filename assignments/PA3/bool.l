%{
/*
 * 识别布尔识别
 */
#include "bool.tab.h"
%}

%%

true  {  return T_TRUE; }
false  {return T_FALSE; }
"||"  { return T_OR; }
"&&"  { return T_AND; }
"!" {return T_NOT;}
[()\n]      { return yytext[0]; }
[ ]         {/* 忽略空格 */}
%%

int yywrap(){
    return 1;
}