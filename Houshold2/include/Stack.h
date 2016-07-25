#ifndef STACK_H
#define STACK_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/// 用数组模拟栈
#define DEFAULTSIZE 50  /// 栈的上限


#define NULL 0

template <class T>
class Stack {
public:
    Stack();
    ~Stack();
    bool push(const T& value);
    bool pop(T& value);
    T& pop();
    bool _empty() {return cursize == 0;}
    bool full() {return cursize == DEFAULTSIZE;}

//private:
    T *_stack;
    int cursize;
};


template <class T>
Stack<T>::Stack()
{
    _stack = new T[DEFAULTSIZE];
    if (_stack == NULL) {
        printf("Memory allocate failure!");
        system("pause");
        exit(1);
    }
    cursize = 0;
}

template <class T>
Stack<T>::~Stack()
{
    cursize = 0;
    delete []_stack;
}

template <class T>
bool Stack<T>::push(const T& value) {
    if (full())
        return false;
    _stack[cursize++] = value;
    return true;
}

template <class T>
bool Stack<T>::pop(T& value) {
    if (_empty())
        return false;
    value = _stack[--cursize];
    return true;
}

template <class T>
T& Stack<T>::pop() {
    if (_empty())
        exit(1);
    return _stack[--cursize];
}

#endif // STACK_H
