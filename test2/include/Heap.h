#ifndef HEAP_H
#define HEAP_H

class Heap {
public:
    Heap();
    Heap(int a[], int size);
    ~Heap();
    bool insert(int value);
    void remove_top();
    int gettop();
    void adjust();
    void prin();

protected:
    void siftup(int key);
    void siftdown(int key);

private:
    int *root;
    int p;
    int Maxsize;
};

#endif // HEAP_H
