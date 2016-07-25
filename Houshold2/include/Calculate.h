

#ifndef CALCULATE_H
#define CALCULATE_H

#define Max 100  /// 用户输入表达式的上限
#include "Stack.h"   /// 里面包含栈的定义
#include <cstring>

class Node {
public:
    short sign;  ///sign为0时代表a为正1为操作符
    char a[20]; /// 节点中存储的数据

public:
    Node():sign(0) {strcpy(a, "");}
    Node(short s, char b[20]) {strcpy(a, b); sign = s;}
    ~Node() {}
};

class Calculate {
    Node ar[Max];           /// 保存用户输入的表达式
    int pr[Max/2+1];        /// 保存临时操作符的优先级
    int len;                /// 用户输入表达式的长度
    int size;               /// 数组pr的长度
    bool tag;               /// 为false表示当前字符不在括号内，否则在
    Stack<Node> a;          /// 保存后续算数表达式
    Stack<Node> b;          /// 辅助栈

private:
    void exchange();        /// 将用户输入的算数表达式转化成后序表达式存于a中
    void change();
    int priority(char data);/// 获取data的优先级，t表示data是否在括号内

    void add(Node& a, Node& b, Node& c);  /// 大数据加法
    void subtraction(Node&a, Node& b, Node& c); /// 大数据减法
    void ride(Node& a, Node& b, Node& c);  /// 大数据乘法
    void division(Node& a, Node& b, Node& c);  /// 大数据除法

public:
    void calculate();       /// 计算表达式

};

#endif // CALCULATE_H
