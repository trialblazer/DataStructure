#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

#define DEFAULT_VECTOE_SIZE 10

class Vector {
public:
    Vector();
    Vector(int s);
    ~Vector();
    bool push_back(int value);
    int get(int index);
    bool pop_back();
private:
    bool expand();

    int size;
    int *v;
    int p;
};

#endif // VECTOR_H
