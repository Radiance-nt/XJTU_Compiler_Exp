// -*-Mode: C++;-*-
//
// 这个文件定义了语法树的节点类型和符号表
// 
//
#include "copyright.h"


#ifndef _STRINGTAB_H_
#define _STRINGTAB_H_

#include <assert.h>
#include <string.h>
#include "list.h"    // list template
#include "cool-io.h"

class Entry;
typedef Entry* Symbol;

extern ostream& operator<<(ostream& s, const Entry& sym);
extern ostream& operator<<(ostream& s, Symbol sym);

/////////////////////////////////////////////////////////////////////////
//
//  节点的基本类型Entry
//
/////////////////////////////////////////////////////////////////////////

class Entry {
protected:
  char *str;     // string
  int  len;      // string的长度
  int index;     // 每一个string都有一个唯一的值
public:
  Entry(char *s, int l, int i);

  // 判断一个字符串s是否和entry中的str相等
  int equal_string(char *s, int len) const;  
                         
  // 判断index是否等于ind
  bool equal_index(int ind) const           { return ind == index; }

  ostream& print(ostream& s) const;

  // 获取str和str的长度
  char *get_string() const;
  int get_len() const;
};

//
// Cool语言当中有三种字符串:
//   一个真正的字符串, 一个表示id的字符串, 和一个表示整数的字符串 
// 
//
class StringEntry : public Entry {
public:
  void code_def(ostream& str, int stringclasstag);
  void code_ref(ostream& str);
  StringEntry(char *s, int l, int i);
};

class IdEntry : public Entry {
public:
  IdEntry(char *s, int l, int i);
};

class IntEntry: public Entry {
public:
  void code_def(ostream& str, int intclasstag);
  void code_ref(ostream& str);
  IntEntry(char *s, int l, int i);
};

typedef StringEntry *StringEntryP;
typedef IdEntry *IdEntryP;
typedef IntEntry *IntEntryP;

//////////////////////////////////////////////////////////////////////////
//
//  符号表
//
//////////////////////////////////////////////////////////////////////////

template <class Elem> 
class StringTable
{
protected:
   List<Elem> *tbl;   // 符号表是个list
   int index;         // 当前的索引值
public:
   StringTable(): tbl((List<Elem> *) NULL), index(0) { }   // 初始化一个空表
   // 下面的方法控制往list中添加元素  
   // 符号表对同一个字符串只有保留一个版本
   // 返回符号表中指向该字符串的指针

   // add the prefix of s of length maxchars
   Elem *add_string(char *s, int maxchars);

   // add the (null terminated) string s
   Elem *add_string(char *s);

   // add the string representation of an integer
   Elem *add_int(int i);


   // 迭代器
   int first();       // 第一个
   int more(int i);   // 还有节点?
   int next(int i);   // 下一个

   Elem *lookup(int index);      // 根据索引查询
   Elem *lookup_string(char *s); // 根据string查询

   void print();  // 打印整个列表，用来调试

};

class IdTable : public StringTable<IdEntry> { };

class StrTable : public StringTable<StringEntry>
{
public: 
   void code_string_table(ostream&, int classtag);
};

class IntTable : public StringTable<IntEntry>
{
public:
   void code_string_table(ostream&, int classtag);
};

extern IdTable idtable;
extern IntTable inttable;
extern StrTable stringtable;
#endif
