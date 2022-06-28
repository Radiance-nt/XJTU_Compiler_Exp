//
// 该文件定义了一个list的模版以及和list相关的操作函数
//
#include "copyright.h"

#ifndef _LIST_H_
#define _LIST_H_

#include "cool-io.h"  
#include <stdlib.h>

template <class T>
class List {
private:
  T *head;
  List<T>* tail;
public:
  List(T *h,List<T>* t = NULL): head(h), tail(t) { }

  T *hd() const       { return head; }  
  List<T>* tl() const { return tail; }
};

/////////////////////////////////////////////////////////////////////////
// 
// 和list相关的函数模版
//
// 为了方便定义多个list的情况，这里将函数定义为模版函数，而不是list类的成员函数
//
/////////////////////////////////////////////////////////////////////////

//
// Map a function for its side effect over a list.
//
template <class T>
void list_map(void f(T*), List<T> *l)
{
  for (l; l != NULL; l = l->tl())
    f(l->hd());
}

//
// 将已知的list打印出来
// 这里需要求"<<" 对该S类型定义过.
//
template <class S, class T>
void list_print(S &str, List<T> *l)
{
   str << "[\n";
   for(; l != NULL; l = l->tl())
	str << *(l->hd()) << " ";
   str << "]\n";
}

//
// 计算一个list的长度
//
template <class T>
int list_length(List<T> *l)
{
  int i = 0;
  for (; l != NULL; l = l->tl())
    i++;
  return i;
}

#endif

