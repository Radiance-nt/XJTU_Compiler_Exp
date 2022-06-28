#######################################
# 编辑这里
# 把CLASSDIR设置成cool文件的位置
# 以便让Makefile通过 ${CLASSDIR}/bin 可以找到coolc
# 下面是我的电脑上cool文件夹的位置
CLASSDIR=/home/radiance/compiler_exp
#######################################

CLASS= cs-compiler
SRC= hello_world
LSRC= Makefile

CC=gcc
CFLAGS=-g

default: compile 

compile:
	${CLASSDIR}/bin/coolc ${SRC}.cl 
	${CLASSDIR}/bin/spim -trap_file ${CLASSDIR}/lib/trap.handler -file ${SRC}.s


clean :
	rm -f *.s core *~
