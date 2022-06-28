%{
#include <stdio.h>
void yyerror(const char* str){
};
%}
%token T_FALSE T_TRUE T_AND T_OR T_NOT

%right uminus

%%
S   :   S E '\n'        { if($2==1){printf("ans = true\n");}else{printf("ans = false\n");}}
    |   /* empty */     { /* empty */ }
    ;

E   :   E T_AND E         { $$ = $1 * $3;}
    |   E T_OR E         { $$ = ($1 + $3>0)?1:0; }
    |   T_NOT E %prec uminus { $$ = $2 ^ 1; }
    |   T_FALSE           { $$ = 0;}
    |   T_TRUE           { $$ = 1;}
    |   '(' E ')'       { $$ = $2; }
    ;

%%
int main() {
    return yyparse();
}
