#include<iostream>
#include<ctime>
#include<cstdlib>

#include <algorithm>

#include "include/Tree.h"
#include "include/list.h"

#define Max 10

using namespace std;

int a[Max];


void test_tree() {
    Tree t;
    srand(time(NULL));
    for(int i=0; i<Max; ++i) {
        a[i] = rand()%(Max*10);
        t.insert1(a[i]);
    }

    cout << "insert done" << endl;

    for (int i=0; i<Max; ++i) {
        int t = rand()%Max;
        swap(a[i], a[t]);
    }
    cout << t.depth() << endl;;
    if (t.find(a[34]))
        cout << "dfsd" << endl;;
    for(int i=0; i<Max; ++i)
        t.remove(a[i]);

    cout << "remove done" << endl;

    cout << "after delete " << endl;
    t.intravel();
}

void test_list() {
    List l;
    for(int i=0; i<Max; ++i) {
        l.push_back(rand()%(Max*10));
    }

    List::Iterator it = l.rbegin();
    while (it != l.rend()) {
        cout << *it << endl;
        --it;
    }
}

int main() {
    // test_tree();
    test_list();
    return 0;
}
