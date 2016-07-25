#include "SeqQueue.h"

template <class T>SeqQueue<T>::SeqQueue(int sz) {
    maxsize = sz>DEFAULTQUEUESIZE? sz:DEFAULTQUEUESIZE;
    elements = new T[maxsize];
    front = rear = 0;
}

template <class T>SeqQueue<T>::SeqQueue() {
    maxsize = DEFAULTQUEUESIZE;
    elements = new T[maxsize];
    front = rear = 0;
}


template <class T>SeqQueue<T>::~SeqQueue() {
    delete []elements;
    front = rear = 0;
}

template <class T>bool SeqQueue<T>::enqueue(const T& value) {
    if (isfull() == true)
        return false;
    elements[rear] = value;
    rear = (rear+1)%maxsize;
    return true;
}

template <class T>bool SeqQueue<T>::delqueue(T& x) {
    if (isempty() == true)
        return false;
    x = elements[front];
    front = (front+1)%maxsize;
}

template <class T>bool SeqQueue<T>::isempty() {
    return (front == rear);
}

template <class T>bool SeqQueue<T>::isfull() {
    return (rear+1 == front);
}

template <class T>int SeqQueue<T>::getlength() {
    return (rear-front+maxsize)%maxsize;
}

template <class T>bool SeqQueue<T>::getfront(T& x) {
    if (isempty() == true)
        return false;
    x = elements[front];
    return true;
}

template <class T>ostream& operator<<(ostream& o, SeqQueue<T>& s) {
    for (int i=0; i<s.getlength(); i++)
        o << "i:  " << s.elements[i] << endl;
}

template <class T>void SeqQueue<T>::makeempty() {
    front = rear = 0;
}

