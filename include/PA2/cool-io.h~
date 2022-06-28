//
// 该文件包含了cool编译器的输入输出所需要的所有头文件和名字空间
// 
//
#include "copyright.h"

#ifndef COOL_IO_H
#define COOL_IO_H

//
// include该文件的所有函数都可以使用c++的标准输入输出代码 
//

//缺省使用标准的iostream
#ifndef  COOL_USE_OLD_HEADERS

# include <iostream>

using std::ostream;
using std::cout;
using std::cerr;
using std::endl;

# include <fstream>

using std::ofstream;

# include <iomanip>

using std::oct;
using std::dec;
using std::setw;
using std::setfill;

//如果只包含std的名字空间，那么std:plus和plus AST中的节点类型产生冲突
//using namespace std;

#else  
// include老版本的头文件

// 这里没有测试，但是应该是可以使用的
# include <iostream.h>
# include <fstream.h>
# include <iomanip.h>

#endif // COOL_USE_OLD_HEADERS


#endif //COOL_IO_H
