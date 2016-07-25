

#ifndef CALCULATE_H
#define CALCULATE_H

#define Max 100  /// �û�������ʽ������
#include "Stack.h"   /// �������ջ�Ķ���
#include <cstring>

class Node {
public:
    short sign;  ///signΪ0ʱ����aΪ��1Ϊ������
    char a[20]; /// �ڵ��д洢������

public:
    Node():sign(0) {strcpy(a, "");}
    Node(short s, char b[20]) {strcpy(a, b); sign = s;}
    ~Node() {}
};

class Calculate {
    Node ar[Max];           /// �����û�����ı��ʽ
    int pr[Max/2+1];        /// ������ʱ�����������ȼ�
    int len;                /// �û�������ʽ�ĳ���
    int size;               /// ����pr�ĳ���
    bool tag;               /// Ϊfalse��ʾ��ǰ�ַ����������ڣ�������
    Stack<Node> a;          /// ��������������ʽ
    Stack<Node> b;          /// ����ջ

private:
    void exchange();        /// ���û�������������ʽת���ɺ�����ʽ����a��
    void change();
    int priority(char data);/// ��ȡdata�����ȼ���t��ʾdata�Ƿ���������

    void add(Node& a, Node& b, Node& c);  /// �����ݼӷ�
    void subtraction(Node&a, Node& b, Node& c); /// �����ݼ���
    void ride(Node& a, Node& b, Node& c);  /// �����ݳ˷�
    void division(Node& a, Node& b, Node& c);  /// �����ݳ���

public:
    void calculate();       /// ������ʽ

};

#endif // CALCULATE_H
