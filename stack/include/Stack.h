#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>

#include "../include/Vector.h"

class Stack
{
public:
    Stack();
    bool empty();
    bool push(int value);
    bool pop();
    int top();
private:
    Vector v;
    int p;
};

#endif // STACK_H_INCLUDED
