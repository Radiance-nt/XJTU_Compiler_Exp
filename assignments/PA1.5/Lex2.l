%{
/*
 * 统计行数，列数和字数 文件/直接输入
 */
#include <stdio.h>
int nline,ncolumn,nnword,column; /* 分别记录行数，列数和字数 */
%}

%%

[ \t] {column++;}
[^ \t\n]+ {
    nnword++;
    column+=yyleng;
}
\n {
    ncolumn=(ncolumn>column)?ncolumn:column;
    ++nline;
    column=0;
}

%%

int main(int argc, char **argv){
    if(argc > 1) {
        char * fn=argv[1];
        if(!(yyin=fopen(fn,"r"))) {
            perror(argv[1]);
            return 1;
        }
    }
    yylex();             /* 调用词法分析器，直到输入结束  */
    printf("nline=%d, ncolumn=%d, nnword=%d\n", nline, ncolumn, nnword);
    return 0;
}