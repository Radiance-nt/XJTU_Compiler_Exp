#######################################
#   from the simplist start
#   以便Makefile可以找到cool/bin所在的位置
CLASSDIR= /home/radiance/compiler_exp
#######################################
ASSN = 1.5
LIB= ${CLASSDIR}/lib
SRC=Lex1 Lex2 Lex3 Lex4

#make需要的源文件列表
CSRC= lextest.cc utilities.cc stringtab.cc handle_flags.cc
#一个shell脚本程序
TSRC= mycoolc
HSRC=
#需要生成的文件
CGEN= cool-lex.cc
#一个完整的编译过程
LIBS= parser semant cgen
CFIL= ${CSRC} ${CGEN}          
LSRC= Makefile
#OBJS表示所有的.o目标
OBJS= ${CFIL:.cc=.o}
#执行make test.output命令的时候，会将记号输出到test.out文件中
OUTPUT= test.output
LSRC= Makefile
CC=gcc
CFLAGS=-g
#default: source compile test
${SRC}:
	flex ${CLASSDIR}/assignments/PA${ASSN}/$@.l
	gcc -o $@ ${CLASSDIR}/assignments/PA${ASSN}/lex.yy.c  -ll
	
default: ${SRC} 

clean: 
	@rm *.o *.d *.~ lex.yy.c ${SRC}


