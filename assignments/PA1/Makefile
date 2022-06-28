#######################################
# 编辑这里
# 把CLASSDIR设置成cool文件的位置
# 以便让Makefile通过 ${CLASSDIR}/bin 可以找到coolc
# 下面是我的电脑上cool文件夹的位置
CLASSDIR=/home/radiance/compiler_exp
#######################################

ASSN = 1
CLASS= cs-compiler
SRC= stack.cl utils.cl README.SKEL 
LSRC= Makefile

CC=gcc
CFLAGS=-g

default: source compile test

.c.o:
	${CC} ${CFLAGS} -c $<

source : lsource
	${CLASSDIR}/etc/copy-skel ${ASSN} ${SRC}

lsource:
	${CLASSDIR}/etc/link-shared ${ASSN} ${LSRC}

compile: demo

demo: demo.cl
	@echo create demo.s
	${CLASSDIR}/bin/coolc demo.cl 

test:	compile
	@echo test demo.s
	${CLASSDIR}/bin/spim -trap_file ${CLASSDIR}/lib/trap.handler -file demo.s

run:	compile
	@echo run demo.s
	${CLASSDIR}/bin/spim -trap_file ${CLASSDIR}/lib/trap.handler -file demo.s

clean :
	rm -f *.s core *~

main: 
	@echo compile and run $(file).cl
	${CLASSDIR}/bin/coolc $(file).cl
	${CLASSDIR}/bin/spim -trap_file ${CLASSDIR}/lib/trap.handler -file $(file).s

# lex
lex:
	@echo run flex $(file).l
	flex $(file).l
	cc -o $(file).out lex.yy.c -lfl
	rm lex.yy.c