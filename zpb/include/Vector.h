#ifndef VECTOR_H
#define VECTOR_H

class Vector {
public:
    Vector();
    ~Vector();
    bool push(int value);
    bool pop_back();
    bool empty();
    bool expand();
    int get(int index);

private:
    int *v;
    int p;
    int size;
};

#endif // VECTOR_H
