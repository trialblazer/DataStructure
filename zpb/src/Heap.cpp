#include "Heap.h"
#include<iostream>

Heap::Heap(int a[], int size) {
    for (int i=0; i<size; i++)
        v.push_back(a[i]);
    for (int i=(size-1)/2; i>=0; i--)
        siftdown(i);
}


bool Heap::insert(int value) {
    v.push_back(value);
    // for(int i=(p-1)/2; i>=0; i--)
    //    siftdown(i);
    siftup();
    return true;
}


int Heap::get() {
    if (!v.empty())
        return v[0];
    return -1;
}


void Heap::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void Heap::siftup() {
    int p = v.size();
    for(int i=p-1; i>0; i=(i-1)/2) {
        if (v[i] < v[(i-1)/2])
            swap(&v[i], &v[(i-1)/2]);
        else
            break;
    }
}


void Heap::siftdown(int begin) {
    int i = begin;
    int p = v.size();
    while(1) {
        /// int p = v.size();
        /// if ((2*i+2)>=p)
        if ((2*i+1)>=p)
            break;
        int j = 2*i+1;
        if ((j+1)<p)
            v[j]>v[j+1]? j++: j=j;
        if (v[i]>v[j])
            swap(&v[i], &v[j]);
        else
            break;
        i = j; /// 把当前节点指向与其交换的子节点
    }
}


void Heap::remove() {
    int p = v.size();
    if (p>0) {
        v[0] = v[p-1];
        p--;
        siftdown(0);
    }
    /// if (p == 0) {
    ///    delete []v;
    ///    p = NULL;
    /// }
}


/*
void Heap::adjust() {
    for (int j=p-1; j>0; j--) {
        if (v[(j-1)/2] > v[j]) {
            change(&v[(j-1)/2], &v[j]);
            int i = j;
            while ((2*i+1) < p) {
                if ((2*i+2) < p) {
                    int tem = v[2*i+1] > v[2*2+2]? (2*2+2):(2*i+1);
                    if (v[tem] < v[i]) {
                        change(&v[tem], &v[i]);
                        i = tem;
                    } else {
                        break;
                    }
                } else {
                    if (v[i] > v[2*i+1])
                        change(&v[i], &v[2*i+1]);
                    break;
                }
            }
        }
    }
}
*/
