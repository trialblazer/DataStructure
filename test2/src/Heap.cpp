#include "Heap.h"

#include<iostream>
#include<stdlib.h>

#define DEFAULT_HEAP_SIZE 5

Heap::Heap() {
    Maxsize = DEFAULT_HEAP_SIZE;
    root = new int[Maxsize];
    if (root == NULL) {
        std::cout << "Memory allocate failure!\n";
        exit(1);
    }
    p = 0;
}

Heap::Heap(int a[], int size) {
    Maxsize = DEFAULT_HEAP_SIZE > size? DEFAULT_HEAP_SIZE:size;
    root = new int[Maxsize];
    if (root == NULL) {
        std::cout << "Memory allocate failure!\n";
        exit(1);
    }
    for (int i=0; i<size; i++)
        insert(a[i]);
   //     root[i] = a[i];
}

Heap::~Heap() {
    delete []root;
    root = NULL;
}


void Heap::siftdown(int key) {
    int min;
    while (key*2+1 < p) {
        if (p <= 2*key+2) {
            if (root[key] > root[key*2+1]) {
                int tmpt = root[key];
                root[key] = root[key*2+1];
                root[key*2+1] = tmpt;
            } else
                break;
        } else {
            min = root[key*2+1] > root[key*2+2]? key*2+2:key*2+1;
            if (root[key] > root[min]) {
                int tmpt = root[key];
                root[key] = root[min];
                root[min] = tmpt;
            } else
                break;
        }
        key = min;
    }
}

void Heap::siftup(int key) {
    while (key > 0) {
        int p = (key-1)/2;
        if (root[key] < root[p]) {
            int tmpt = root[p];
            root[p] = root[key];
            root[key] = tmpt;
        } else
            break;
        key = p;
    }
}


bool Heap::insert(int value) {
    if (p == Maxsize)
        return false;
    root[p++] = value;
    siftup(p-1);
    return true;
}

int Heap::gettop() {
    if (p == 0)
        return -1;
    return root[0];
}


void Heap::remove_top() {
    if (p == 0)
        return;
    root[0] = root[--p];
    if (p != 0)
        siftdown(0);
}

void Heap::prin() {
    for (int i=0; i<p; i++)
        std::cout << root[i] << "  ";
}




































