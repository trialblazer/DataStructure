#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap {
public:
    Heap(int a[], int size);
    bool insert(int value);
    void remove();
    int get();
    /// void swap(int *a, int *b);

protected:
    void swap(int *, int *);
    void siftdown(int begin);
    void siftup();

private:
    std::vector<int> v;
};

#endif // HEAP_H
