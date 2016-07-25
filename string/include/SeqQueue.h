#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include "Queue.h"
#include <iostream>
#define DEFAULTQUEUESIZE 20
using namespace std;
template <class T> class SeqQueue:public Queue<T> {
public:
    SeqQueue();
    SeqQueue(int sz = DEFAULTQUEUESIZE);
    ~SeqQueue();
    bool enqueue(const T&);
    bool delqueue(T&);
    bool getfront(T&);
    int getlength();
    bool isempty();
    bool isfull();
    friend ostream& operator<<(ostream& o, SeqQueue<T>& s);
    void makeempty();

private:
    int maxsize;
    T* elements;
    int front,rear;
};

#endif // SEQQUEUE_H
