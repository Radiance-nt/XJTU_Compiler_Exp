#######################################
# 编辑这里
# 将CLASSDIR设置成你电脑上cool项目所在的位置
CLASSDIR= /home/radiance/compiler_exp

#######################################

#作业序号，第三次作业
ASSN = 3
#没有用
CLASS= xjtucompiler
#链接库，暂时不用管
LIB= -L/usr/local/lib

ANALYZER=cool.y
# ANALYZER=cool.y

TARGET_MULTI=cal bool float
TARGET_SINGLE=calculator_basic calculator_advanced calculator_ultimate
#Makefile依赖的文件列表
SRC= ${ANALYZER} cool-tree.handcode.h good.cl bad.cl README
#生成parser依赖的源文件列表
CSRC= parser-phase.cc utilities.cc stringtab.cc dumptype.cc \
      tree.cc cool-tree.cc tokens-lex.cc  handle_flags.cc 
#需要链接到当前目录的文件
# TSRC= myparser mycoolc cool-tree.aps ref-parser
TSRC= myparser cool-tree.aps ref-parser

#bison要生成的源文件和头文件
CGEN= cool-parse.cc
HGEN= cool-parse.h
# LIBS= lexer semant cgen

#将所有源文件都连接起来
LIBS= lexer semant
CFIL= ${CSRC} ${CGEN}

#依赖的头文件
HFIL= cool-tree.h cool-tree.handcode.h 
LSRC= Makefile

#将.cc全部替换成.o后缀
OBJS= ${CFIL:.cc=.o}
#将结果输出到文档中去
OUTPUT= good.output bad.output

#依赖的头文件和部分源文件分别存放在include和src目录下
CPPINCLUDE= -I. -I ${CLASSDIR}/include/PA${ASSN} -I ${CLASSDIR}/src/PA${ASSN}

#bison的编译选项
BFLAGS = -d -v -y -b cool --debug -p cool_yy

CC=g++
CFLAGS=-g -Wall ${CPPINCLUDE}
FLEX=flex ${FFLAGS}
BISON= bison ${BFLAGS}
DEPEND = ${CC} -MM ${CPPINCLUDE}

default: source parser

source: ${SRC} ${TSRC} ${LSRC} ${LIBS} lsource

lsource: ${LSRC}

${OUTPUT}:	parser good.cl bad.cl
	@rm -f ${OUTPUT}
	./myparser good.cl >good.output 2>&1 
	-./myparser bad.cl >bad.output 2>&1 

parser: ${OBJS}
	echo "start parser"
	${CC} ${CFLAGS} ${OBJS} ${LIB} -o parser

.cc.o:
	${CC} ${CFLAGS} -c $<

cool-parse.cc cool-parse.h: ${ANALYZER}
	${BISON} ${ANALYZER}
	mv -f cool.tab.c cool-parse.cc

dotest:	myparser good.cl
	@echo "\nRunning parser on good.cl\n"
	@echo "\nRunning parser on bad.cl\n"

${LIBS}:
	ln -s ${CLASSDIR}/bin/reference-$@ $@
#sg: just symlink to the architecture independant refernce-* shell scripts
#	${CLASSDIR}/etc/link-object ${ASSN} $@

# These dependencies allow you to get the starting files for
# the assignment.  They will not overwrite a file you already have.

${SRC} :								
	-${CLASSDIR}/etc/copy-skel ${ASSN} ${SRC}

${LSRC} :
	-${CLASSDIR}/etc/link-shared ${ASSN} ${LSRC}

${TSRC} ${CSRC}:
	-ln -s ${CLASSDIR}/src/PA${ASSN}/$@ $@

${HSRC}:
	-ln -s ${CLASSDIR}/include/PA${ASSN}/$@ $@

submit-clean: ${OUTPUT}
	-rm -f *.s core ${OBJS} ${CGEN} ${HGEN} *~ parser

clean :
	-rm -f ${OUTPUT} *.s core ${OBJS} ${CGEN} ${HGEN} parser *~ *.a *.o *.cc *.d *.out *.tab.c *.yy.c *.tab.h

clean-compile:
	@-rm -f core ${OBJS} ${CGEN} ${HGEN} ${LSRC}

%.d: %.cc ${LSRC}
	${SHELL} -ec '${DEPEND} $< | sed '\''s/\($*\.o\)[ :]*/\1 $@ : /g'\'' > $@'

-include ${CFIL:.cc=.d}

default:
	@echo make <filename>

${TARGET_MULTI}:
	flex -o $@.yy.c $@.l

	bison -d $@.y

	bison -o $@.tab.c $@.y

	gcc -o $@.out $@.yy.c $@.tab.c
	./$@.out

${TARGET_SINGLE}:
	bison -o $@.c $@.y

	gcc -o $@.out  $@.c
	./$@.out
