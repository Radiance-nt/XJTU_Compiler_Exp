%{
// 加减乘除括号 多位数  a-z符号 存在空格问题 需要使用lex解决
#include <stdio.h>
int regs[26];
void yyerror(char *s);
int yylex();
%}

%token DIGIT ID

%left '+' '-'
%left '*' '/'
%right uminus

%%
S   :   S STAT '\n'        { printf("ans = %d\n", $2); }
    |   /* empty */     { /* empty */ }
    ;

STAT:   ID '=' E    { regs[$1] = $3; $$ = $3; }
    |   E               { $$ = $1;}
    ;

E   :   E '+' E             { $$ = $1 + $3;}
    |   E '-' E             { $$ = $1 - $3; }
    |   E '*' E             { $$ = $1 * $3; }
    |   E '/' E             { $$ = $1 / $3; }
    |   ID                  { $$ = regs[$1]; }
    |   '-' E %prec uminus  { $$ = -$2; }
    |   number              { $$ = $1;}
    |   '(' E ')'           { $$ = $2; }
    |   error               { yyerror("expr: error"); }  
    ;

number
    :   DIGIT           { $$ = $1; }
    |   number DIGIT    { $$ = $1*10 + $2;}

%%

int yylex() { /*  lexical  analysis  routine  */
    int c;
    int t;
    do{
        c = getchar();
    }while(c==' ');

    if(c>='a'&&c<='z'){
        yylval = c - 'a';return ID;
    }else if(c>='A'&&c<='Z'){
        yylval = c -'A';return ID;
    }else if(c>='0'&&c<='9'){
        yylval = c-'0';
        return DIGIT;
    }
    // 必须加
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
