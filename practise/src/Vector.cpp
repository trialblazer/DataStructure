#include "Vector.h"

Vector::Vector() {
    v = new int[DEFAULT_VECTOE_SIZE];
    if(v == NULL) {
        std::cerr << "memory allocate failure!!" << std::endl;
        return;
    }
    size = DEFAULT_VECTOE_SIZE;
    p = 0;
}

Vector::Vector(int s) {
    v = new int[s];
    if(v == NULL) {
        std::cerr << "memory allocate failure!!" << std::endl;
        return;
    }
    size = s;
    p = 0;
}

Vector::~Vector() {
    p = 0;
    v = NULL;
}

bool Vector::push_back(int value) {
    if(p == size)
        expand();
    v[p] = value;
    p++;
}

bool Vector::expand() {
    int *q = new int[size*2];
    if(q == NULL) {
        std::cerr << "Memory allocate failure!" << std::endl;
        return false;
    }
    for(int i = 0; i<size; i++)
        q[i] = v[i];
    delete[]v;
    v = q;
    size *= 2;
    return true;
}

int Vector::get(int index) {
    if(index<0 || index>=p) {
        std::cout << "out of size, get failure!" << std::endl;
        return -1;
    }
    return v[index];
}

bool Vector::pop_back() {
    if(p<0) {
        std::cout << "empty, failure!!" << std::endl;
        return false;
    }
    p--;
    return true;
}
