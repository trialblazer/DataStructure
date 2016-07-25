#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
template <class T>
class ListNode {
    ListNode(T value=0):next(NULL), prior(NULL), data(value){}
    bool insert(ListNode<T>* position, T value);
    bool remove(T value);
    ListNode<T>* find(T value);
    T& getdata();

private:
    ListNode<T>* next;
    ListNode<T>* prior;
    T data;
};

template <class T>
class List {
public:
    List():head(NULL), tail(NULL), total(0) {}
    ~List();
    bool insert(T value);
    bool remove(T value);
    ListNode<T>* find(T value);
    T& getdata();

private :
    ListNode<T> *head;
    ListNode<T> *tail;
    int total;
};



#endif // LIST_H
