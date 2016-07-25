#include "Vector.h"

#include<iostream>
#include<stdlib.h>

#define DEFAULT_VECTOR_SIZE 10

Vector::Vector() {
    v = new int[DEFAULT_VECTOR_SIZE];
    if (v == NULL) {
        std::cout << "Memory allocate failure!!" << std::endl;
        exit(-1);
    }
    p = 0;
    size = DEFAULT_VECTOR_SIZE;
}

Vector::~Vector() {
    delete []v;
    v = NULL;
}

bool Vector::push(int value) {
    if (p == size) {
        if (expand()) {
            v[p] = value;
            p++;
            return true;
        }
        return false;
    }
    v[p] = value;
    p++;
    return true;
}

bool Vector::expand() {
    size = p*2;
    int *t = new int[size];
    if (t == NULL) {
        std::cout << "memory allocate failure!" << std::endl;
        return false;
    }

    for(int i=0; i<p; i++)
        t[i]=v[i];
    int *p = v;
    v = t;
    t = NULL;
    delete []p;
    p = NULL;
    return true;
}

int Vector::get(int index) {
    if(index<0 || index>=p) {
        std::cout << "outof size" << std::endl;
        return -1;
    }
    return v[index];
}

bool Vector::pop_back() {
    if(empty())
        return false;
    p--;
    return true;
}

bool Vector::empty() {
    if(p == 0)
        return true;
    return false;
}














