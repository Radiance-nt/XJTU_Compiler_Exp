tree:

    .
    ├── Lex1.l  统计行数，列数和字数
    ├── Lex2.l  统计行数，列数和字数
    ├── Lex3.l  magic多入口
    ├── Lex4.l  统计if个数
    ├── makefile
    ├── text
    └── text_magic


Usage:

Lex2:

    make Lex2
    ./Lex2 text

Else:

    make <name>
    ./<name>