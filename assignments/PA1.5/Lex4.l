%{
/*
 * 统计if个数
 */
#include <stdio.h>
int nif=0;
%}

%%

[ \t\n]*if[ \t\n]+ {nif++;}
[^ \t\n]+[ \t\n]+ {}

%%

int main(int argc, char **argv){
    if(argc > 1) {
        if(!(yyin=fopen(argv[1],"r"))) {
            perror(argv[1]);
            return 1;
        }
    }
    printf("Press CTRL+d to quit.\nInput any text:\n");
    yylex();             /* 调用词法分析器，直到输入结束  */
    printf("nif=%d\n", nif);
    return 0;
}