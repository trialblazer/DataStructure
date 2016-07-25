#ifndef STACK_H
#define STACK_H

#include "Vector.h"

class Stack {
public:
    bool push(int value);
    void pop();
    int gettop();
    int get(int index);
    void sort();

private:
    Vector v;
};

#endif // STACK_H
