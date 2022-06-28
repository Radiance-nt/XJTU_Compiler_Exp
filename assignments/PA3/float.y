%{
#define YYSTYPE double 
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
void yyerror(const char* str){};
%}
%token T_NUM

%left '+' '-'
%left '*' '/'
%right uminus

%%
S   :   S E '\n'        { printf ("ans = %f\n", $2); }
    |   /* empty */     { /* empty */ }
    ;

E   :   E '+' E         { $$ = $1 + $3;}
    |   E '-' E         { $$ = $1 - $3; }
    |   E '*' E         { $$ = $1 * $3; }
    |   E '/' E         { $$ = $1 / $3; }
    |   '-' E %prec uminus { $$ = -$2; }
    |   T_NUM           { $$ = $1;}
    |   '(' E ')'       { $$ = $2; }
    ;

%%
int main() {
    return yyparse();
}
