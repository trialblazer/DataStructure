#include "Vector.h"

#include<iostream>
#include<stdlib.h>

#define DEFAULT_VECTOR_SIZE 10

Vector::Vector() {
    size = DEFAULT_VECTOR_SIZE;
    v = new int[size];
    if (v == NULL) {
        std::cerr << "Memory allocate failure!!" << std::endl;
        exit(1);
    }
    p=0;
}

Vector::Vector(int a[], int s) {
    int size = DEFAULT_VECTOR_SIZE>s? DEFAULT_VECTOR_SIZE : s;
    v = new int[s];
    if (v == NULL) {
        std::cerr << "Memory allocate failure!!" << std::endl;
        exit(1);
    }
    for (int i=0; i<size; i++)
        v[i] = a[i];
    p = s+1;
}

Vector::~Vector() {
    delete []v;
}

bool Vector::push(int value) {
    if (p == size)
        if (!expand())
            return false;
    v[p++] = value;
    return true;
}

bool Vector::expand() {
    int *tmpt = v;
    size*=2;
    v = new int[size];
    if (v == NULL)
        return false;
    for (int i=0; i<p; i++)
        v[i] = tmpt[i];
    delete []tmpt;
    return true;
}


void Vector::pop_back() {
    if (p == 0)
        return;
    p--;
}

int Vector::get(int index) {
    if (index<0 || index>size)
        return -1;
    if (p == 0)
        return -1;
    return v[index];
}

void Vector::sort() {
    for (int i=0; i<p-1; i++) {
        for (int j=0; j<p-1-i; j++) {
            if (v[j] > v[j+1]) {
                int tmpt = v[j];
                v[j] = v[j+1];
                v[j+1] = tmpt;
            }
        }
    }
}

int Vector::getcurrentsize() {
    return p;
}








