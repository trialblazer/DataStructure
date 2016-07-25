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
    bool insert(char a[], char c[]);        ///��Ӻ���
    Person* find(int index);                ///ͨ����Ų��Һ���
    Person* find(char c[]);                 ///ͨ���˺Ų��Һ���
    int getsize();                          ///��ȡ���ѵĸ���
    void print();                           ///������������
    char* getname(char c[]);                ///ͨ���˺Ż�ȡ��������

private:
    Node* head;
    int total;
};

#endif // LIST_H
