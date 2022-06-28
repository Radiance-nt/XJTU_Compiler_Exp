# 2022-编译器实验

#### 西安交通大学 (XJTU) 编译原理 实验

关键词： cool, coolc, bison, flex, compiler, xjtu

这个课还是比较有难度的，改的（搬的）CS143课程。

我站在巨人们的肩膀上整理了一份答案和报告，应该能让你至少通过这门课程。希望大家能省下时间，无论是继续在这门课上下功夫，还是做别的有意义的事情。

代码主要来源于

[mhq1065/coolc-compiler](https://github.com/mhq1065/coolc-compiler)

PA4的代码来源于:
[afterthat97/cool-compiler](https://github.com/afterthat97/cool-compiler)

**感谢前人的付出**

------

##  你需要会的

### 必会

Linux基础，比如跑文件要`chmod +x <file>`

Makefile基础

### 选会（希望你还是能学一点）

编译知识

编译原理实现过程

	宏观上，各种分析是怎么结合的
	
	具体来说，%% % 这些东西是在做什么，怎么分析的还是希望能懂一点点



------
##  实验要求及秒杀方法

一般都是直接make就行，我都整理好了，每个`Assignment`里应该都有readme，也可以参考报告。

但可能有bug。一般来说，小bug改makefile，大bug去上面两个仓库里找。

### 第一次实验 Hello_world

配环境 (easy) 

### 第二次实验 PA1

编写编译运行coolc程序，内容是一个堆栈机，直接make就好

### 第三次实验 PA1.5

各种统计，多重入口，指定文件make，手动`./`来跑

### 第四次实验 PA2

文件coolc的词法分析器编写，直接make

### 第五次实验 PA3

YACC语法分析，见里面readme


### 第六次实验 PA3

自己写一个cool.y，在`makefile`里换以下ANALYZER

根据仓库一

​	cool.y为原语法分析器
​	cool.ans.y即为语法分析器，可替换cool.y编译使用，增加了对let的支持

### 第七次实验 PA4

做了个检查嵌套继承

### 第八次实验

选做...

