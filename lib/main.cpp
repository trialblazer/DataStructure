/*#include <iostream>

#define MAX 1000

using namespace std;

// 自底向上
int fib(int n) {
    int n1, n2, n3;
    n1 = n2 = n3 = 1;
    while (n-1 > 0) {
        n3 = n2 + n1;
        int tmp = n3;
        n1 = n2;
        n2 = tmp;
        --n;
    }
    return n3;
}


// dynamic plan
// 动态规划，自顶向下

int dp[MAX];

int fib1(int n) {
    if (-1 != dp[n])
        return dp[n];

    if (n <= 1)
        return dp[n] = 1;
    return dp[n] = fib1(n-1) + fib1(n-2);
}

// 自底向上
int fib2(int n) {
    dp[0] = dp[1] = 1;
    for (int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

#include <math.h>

int g(int a[], int i, int j) {
    int Max = a[i];
    for (int t = i+1; t<j; t++)
        if (Max < a[t])
            Max = a[t];
    int tmpt = log(Max+1);
    return (tmpt*(j-i+1)+11);
}

int f(int a[], int i, int j, int m, int n) {
    if (m == 0 && n == 0)
        return g(a, i, j);
    else {
        if (m == 0 && n != 0) {
            int Min1 = g(a, i, i)+f(a, i+1, j, n, --n);
            for (int t=i+1; t<=j; t++) {
                int tmpt = g(a, i, t)+f(a, t+1, j, n, --n);
                if (Min1 < tmpt)
                    Min1 = tmpt;
            }
            return Min1;
        } else {
            int Min2 = g(a, i, i)+f(a, i+1, j, --m, n);
            for (int t=i+1; t<=j; t++) {
                int tmpt = g(a, i, t)+f(a, t+1, j, --m, n);
                if (Min2 < tmpt)
                    Min2 = tmpt;
            }
            return Min2;
        }
    }
}

int main() {
    for (int i=0; i<MAX; i++)
        dp[i] = -1;

    for (int i=0; i<10; i++)
        cout << "fib1(" << i << ") = " << fib(i) << endl;

    cout << endl << endl;
    int a[] = {1, 2};
    cout << f(a, 0, 1, 1, 1) << endl;

    //int a[] = {1, 2, 3, 12, 13, 14, 15, 2, 3};
    //cout << f(a, 0, 8, 8, 8) << endl;
    return 0;
}
*/

/*

#include <iostream>
using namespace std;


template <class T>
class MyArray {
public:
    MyArray(int sz);
    ~MyArray();
    int getsize();
    T* getdata(int pos);
    bool _insert(T value);
    void show();

private:
    T *data;
    int totalsize;
    int validsize;
};

template <class T> MyArray<T>::MyArray(int sz) {
    totalsize = sz;
    validsize = 0;
    data = new T[totalsize];
}

template <class T> MyArray<T>::~MyArray() {
    if (data != NULL) {
        delete []data;
        data = NULL;
    }
}

template <class T> int MyArray<T>::getsize() {
    return validsize;
}

template <class T> T* MyArray<T>::getdata(int pos) {
    if (pos<0 || pos>=totalsize)
        return NULL;
    return data[pos];
}

template <class T> bool MyArray<T>::_insert(T value) {
    if (validsize < totalsize) {
        data[validsize++] = value;
        return true;
    }
    return false;
}

template <class T>
class Unit {
public:
    T data;
    Unit *next;
};

template <class T>
class Array {
private:
    Unit<T> * head;
    Unit<T> * prior;
    Unit<T> * tail;

public:
    Array();
    ~Array();
    bool _push_back(T value);
    void show();
};

template <class T> Array<T>::Array() {
    prior = head = tail = NULL;
}

template <class T> Array<T>::~Array() {
    while (head->next != NULL) {
        Unit<T> * pointer = head;
        while (pointer->next != prior)
            pointer = pointer->next;
        delete prior;
        prior = pointer;
        prior->next = tail = NULL;
    }
    delete head;
    head = NULL;
}

template <class T> bool Array<T>::_push_back(T value) {
    Unit<T> * add = new Unit<T>;
    if (add == NULL)
        return false;
    add->data = value;
    add->next = NULL;
    if (head == NULL) {
        head = add;
        prior = add;
        prior->next = tail;
        return true;
    }
    prior->next = add;
    prior = prior->next;
    tail = prior->next;
    return true;
}

template <class T> void Array<T>::show() {
    Unit<T> * tmpt = head;
    while (tmpt != NULL) {
        cout << tmpt->data << "\t";
        tmpt = tmpt->next;
    }
    cout << endl;
}

template <class T> void MyArray<T>::show() {
    for (int i=0; i<validsize; i++)
        cout << data[i] << "\t";
    cout << endl;
}



template <class T> class Operator {
private:
    T* data;

public:
    Operator(T value);
    ~Operator();
    T getdata();
    T* getlink();
}

template <class T> Operator<T>::Operator() {

}

int main() {
    MyArray<int> m(5);
    for (int i=0; i<5; i++)
        m._insert(i);
    m.show();

    Array<int> n;
    for (int i=5; i<10; i++)
        n._push_back(i);
    n.show();
    return 0;
}
*/


#include <iostream>
#include "Tree.h"
using namespace std;


int main() {

    return 0;
}



















