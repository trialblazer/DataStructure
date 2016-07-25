#ifndef LIST_H
#define LIST_H

#include "Person.h"

class Node {
public:
    Person p;
    int index;
    class Node *next;
};

class List {
public:
    List();
    ~List();
    bool insert(char a[], char c[]);        ///添加好友
    Person* find(int index);                ///通过序号查找好友
    Person* find(char c[]);                 ///通过账号查找好友
    int getsize();                          ///获取好友的个数
    void print();                           ///遍历好友链表
    char* getname(char c[]);                ///通过账号获取好友名字

private:
    Node* head;
    int total;
};

#endif // LIST_H
