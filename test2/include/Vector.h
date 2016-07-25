#ifndef VECTOR_H
#define VECTOR_H


class Vector {
public:
    Vector();
    Vector(int a[], int s);
    ~Vector();
    bool push(int value);
    void pop_back();
    bool expand();
    int get(int index);
    void sort();
    int getcurrentsize();

private:
    int *v;
    int p;
    int size;
};

#endif // VECTOR_H
