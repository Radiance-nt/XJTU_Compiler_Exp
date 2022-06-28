%{
/*
 * 统计单词数、行数、字符数
 * 用gcc生成可执行程序：
 *  flex -o ex1.c lexsamp1.l
 *  gcc  -o ex1 ex1.c
   之后运行./ex1 即可运行
 */
#include <stdio.h>
int nchar, nword, nline; /* 分别记录字符个数、字数和行数 */
%}
%option yylineno
%%
[ \t]                  /* 匹配到一个空格或Tab键就“吃”掉它们 */
\n          {/*adding your code*/;
               nline++;
            }  /* 匹配到一个换行符，行数加1 */
[^ \t\n]+  {
             /* 匹配到一个不包括空格、Tab键和换行符的字，
                字数加1，字符数加yyleng(字符长度) */
             /*adding your code*/;
             ++nword; nchar+=yyleng;
            }

%%
int main()
{ 
   printf("Press CTRL+d to quit.\nInput any text:\n");
   yylex();             /* 调用词法分析器，直到输入结束  */
   printf("nchar=%d, nword=%d, nline=%d\n", nchar, nword, nline);
   return 0;
}

/* 函数yywrap是LEX提供的一个库函数
 * 若生成可执行程序时没有链接LEX库，则必须手工定义
 * 反之，生成可执行程序时必须如此：
 * cc -o a.out lex.yy.c -ll    # for LEX
 * cc -o a.out lex.yy.c -lfl   # for FLEX
 * 其中-ll表示连接函数库libl.a(in UNIX)
 */
// int yywrap(){ return 1; }
