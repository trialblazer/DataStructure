#ifndef QUEUE_H
#define QUEUE_H

template <class T>class Queue {
public:
    Queue() {}
    virtual ~Queue() {}
    virtual void enqueue(const T&)=0;
    virtual bool delqueue(T&)=0;
    virtual bool getfront(T&)=0;
    virtual int getlength()=0;
    virtual bool isempty()=0;
    virtual bool isfull()=0;
};

#endif // QUEUE_H
