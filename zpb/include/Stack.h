#ifndef STACK_H
#define STACK_H

#include"Vector.h"

class Stack {
public:
    bool empty();
    bool pop_back();
    bool push(int value);
    int get(int index);

private:
    Vector v;
};

#endif // STACK_H
