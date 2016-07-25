#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
template <class T>
class List_Node {
public:
    List_Node<T>():link(NULL), prior(NULL) {}
    List_Node<T>(T value):link(NULL), prior(NULL), value(value) {}
    T& getdata() {return value;}
    void setlink(List_Node<T>* newlink) {link = newlink;}
    List_Node<T>* getlink() {return link;}
    void setprior(List_Node<T>* newprior) {prior = newprior;}
    List_Node<T>* getprior() {return prior;}

private:
    T value;
    List_Node<T>* link;
    List_Node<T>* prior;
};

template <class T>
class List {
public:
    List();
    ~List();
    List_Node<T>* getlink(int index);
    List_Node<T>* getprior(int index);
    int getcount();
    bool addtail(T value);
    bool removetail();
    bool addat(T value, int index);
    bool removeat(int index);
    List_Node<T>* gethead();
    List_Node<T>* gettail();
    void clear();
    T& getdata(int index);

private:
    List_Node<T>* head;
    List_Node<T>* tail;
};

#endif // LIST_H
