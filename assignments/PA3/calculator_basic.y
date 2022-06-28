%{
#include <stdio.h>
int regs[26];
void yyerror(char *s);
int yylex();
%}

%token LETTER DIGIT

%right '='
%left '-'
%left '*'

%%
S   :   S E '\n'        { printf("ans = %d\n", $2); }
    |   /* empty */     { /* empty */ }
    ;

E   :   E '-' E         { $$ = $1 - $3; }
    |   E '*' E         { $$ = $1 * $3; }
    |   DIGIT           { $$ = $1; }
    |   LETTER          { $$ = regs[$1]; }
    |   '(' E ')'       { $$ = $2; }
    |   LETTER '=' E    { regs[$1] = $3; $$ = $3; }
    ;

%%


int yylex() { /*  lexical  analysis  routine  */
    int c;
    do{
        c = getchar();
    }while(c==' ');

    if(c>='a'&&c<='z'){
        yylval=c-'a';return LETTER;
    }else if(c>='A'&&c<='Z'){
        yylval=c-'A';return LETTER;
    }else if(c>='0'&&c<='9'){
        yylval=c-'0';return DIGIT;
    }

    return c;
}

void yyerror(char *s)
{
    fprintf(stderr,"%s\n",s);
}

int main() {
    yyparse();
    return 0;
}
