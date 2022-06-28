#ifndef _COOL_PARSE_H
#define _COOL_PARSE_H
//
// 该文件定义了词法过程中的记号和语法树中的节点结构
//
#include "copyright.h"

#ifndef _COOL_H_
#define _COOL_H_

#include <iostream>

//给类型起个新名字
typedef int Boolean;       
class Entry;             //Entry定义在stringtab.h文件中，表示语法树中的节点的类型（Int,String,id）
typedef Entry *Symbol;   //用Symbol表示Entry类型的指针

//下面这些函数的实现在cool-tree.handcode.h文件当中，词法分析用不到
Boolean copy_Boolean(Boolean);
void assert_Boolean(Boolean);
void dump_Boolean(std::ostream &,int,Boolean);

//下面这些函数的实现在stringtab.cc文件当中，词法分析也用不到
Symbol copy_Symbol(Symbol);        
void assert_Symbol(Symbol);        
void dump_Symbol(std::ostream &,int,Symbol);

#endif

//给节点类型都取一个别名
#include "tree.h"
typedef class Program_class *Program;
typedef class Class__class *Class_;
typedef class Feature_class *Feature;
typedef class Formal_class *Formal;
typedef class Expression_class *Expression;
typedef class Case_class *Case;
typedef list_node<Class_> Classes_class;
typedef Classes_class *Classes;
typedef list_node<Feature> Features_class;
typedef Features_class *Features;
typedef list_node<Formal> Formals_class;
typedef Formals_class *Formals;
typedef list_node<Expression> Expressions_class;
typedef Expressions_class *Expressions;
typedef list_node<Case> Cases_class;
typedef Cases_class *Cases;

//定义语法树的节点类型
typedef union {
  Boolean boolean;
  Symbol symbol;
  Program program;
  Class_ class_;
  Classes classes;
  Feature feature;
  Features features;
  Formal formal;
  Formals formals;
  Case case_;
  Cases cases;
  Expression expression;
  Expressions expressions;
  char *error_msg;
} YYSTYPE;

//定义记号
#define	CLASS	258
#define	ELSE	259
#define	FI	260
#define	IF	261
#define	IN	262
#define	INHERITS	263
#define	LET	264
#define	LOOP	265
#define	POOL	266
#define	THEN	267
#define	WHILE	268
#define	CASE	269
#define	ESAC	270
#define	OF	271
#define	DARROW	272
#define	NEW	273
#define	ISVOID	274
#define	STR_CONST	275
#define	INT_CONST	276
#define	BOOL_CONST	277
#define	TYPEID	278
#define	OBJECTID	279
#define	ASSIGN	280
#define	NOT	281
#define	LE	282
#define	ERROR	283
#define	LET_STMT	284


extern YYSTYPE cool_yylval;
#endif
