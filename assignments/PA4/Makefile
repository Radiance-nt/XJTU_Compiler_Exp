#######################################
# Edit this!
# Set CLASSDIR to the location of the cool package.
#   e.g. the makefile needs to access ${CLASSDIR}/bin
CLASSDIR= /home/radiance/compiler_exp
#######################################

ASSN = 4
CLASS= cs164
AR= gar
ARCHIVE_NEW= -cr
LIB= -L/usr/sww/lib -lfl
RANLIB= gar -qs

SRC= semant.cc semant.h cool-tree.h cool-tree.handcode.h README checkpoint
CSRC= semant-phase.cc symtab_example.cc  handle_flags.cc  ast-lex.cc ast-parse.cc utilities.cc stringtab.cc dumptype.cc tree.cc cool-tree.cc
TSRC= mycoolc cool-tree.aps ref-semant
CGEN=
HGEN=
LIBS= lexer parser cgen
CFIL= semant.cc ${CSRC} ${CGEN}
LSRC= Makefile
OBJS= ${CFIL:.cc=.o}
OUTPUT= good.output bad.output


CPPINCLUDE= -I. -I ${CLASSDIR}/include/PA${ASSN} -I ${CLASSDIR}/src/PA${ASSN}

FFLAGS = -d8 -ocool-lex.cc
BFLAGS = -d -v -y -b cool --debug -p cool_yy
ASTBFLAGS = -d -v -y -b ast --debug -p ast_yy

CC=g++
CFLAGS=-g -Wall -Wno-unused ${CPPINCLUDE} -DDEBUG -Wno-deprecated
FLEX=flex ${FFLAGS}
BISON= bison ${BFLAGS}
DEPEND = ${CC} -MM ${CPPINCLUDE}

default: source semant

source: ${SRC} ${TSRC} ${LIBS} lsource

lsource: ${LSRC}

${OUTPUT}: semant
	@rm -f ${OUTPUT}
	./mysemant good.cl >good.output 2>&1 
	-./mysemant bad.cl >bad.output 2>&1 

compile:	semant change-prot

change-prot:
	@-chmod 660 ${SRC} ${OUTPUT}

SEMANT_OBJS := ${filter-out symtab_example.o,${OBJS}}

semant:  ${SEMANT_OBJS} lexer parser cgen
	${CC} ${CFLAGS} ${SEMANT_OBJS} ${LIB} -o semant
	@-chmod +x run.sh
	echo "\n######\n\nUsage: './run.sh examples/<filename>'\n\n######\n"

symtab_example: symtab_example.cc 
	${CC} ${CFLAGS} symtab_example.cc ${LIB} -o symtab_example

.cc.o:
	${CC} ${CFLAGS} -c $<

${LIBS}:
	ln -s ${CLASSDIR}/bin/reference-$@ $@
#	${CLASSDIR}/etc/link-object ${ASSN} $@

# These dependencies allow you to get the starting files for
# the assignment.  They will not overwrite a file you already have.

${SRC} :								
	-${CLASSDIR}/etc/copy ${ASSN} ${SRC}

${LSRC} :
	-${CLASSDIR}/etc/link-shared ${ASSN} ${LSRC}

${TSRC} ${CSRC}:
	-ln -s ${CLASSDIR}/src/PA${ASSN}/$@ $@

${HSRC}:
	-ln -s ${CLASSDIR}/include/PA${ASSN}/$@ $@

submit-clean: ${OUTPUT}
	-rm -f *.s core ${OBJS} ${CGEN} ${HGEN} *~ semant symtab_example

clean :
	-rm -f ${OUTPUT} *.s core ${OBJS} semant symtab_example *~ *.a *.o

clean-compile:
	@-rm -f core ${OBJS} ${LSRC}

%.d: %.cc ${SRC}
	${SHELL} -ec '${DEPEND} $< | sed '\''s/\($*\.o\)[ :]*/\1 $@ : /g'\'' > $@'

-include ${CFIL:.cc=.d}

