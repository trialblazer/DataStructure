#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Queue.h"
#include <iostream>
#include <list>
using namespace std;

template <class T> struct queuenode {
    T data;
    struct queuenode<T>* link;
};

template <class T>class LinkedQueue:public Queue<T> {
public:
    bool enqueue(const T&);
    bool delqueue(T&);
    bool isempty();
    int getlength();
    void makeempty();
    bool getfront(T&);
    friend ostream& operator<<(ostream&, LinkedQueue<T>&);

private:
    list<queuenode<T> > q;
    list<queuenode<T> > rq;
};

#endif // LINKEDQUEUE_H
