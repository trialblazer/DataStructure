#include <iostream>
#include<ctime>
#include <algorithm>
#include<cstdlib>

#include "List.h"
#include "Vector.h"
#include "Stack.h"
#include "tree.h"
#include "Heap.h"
#include "Graph.h"

#define Max 100

using namespace std;

int a[Max], b[Max];

void test_List() {
    cout << "List_test" << endl;
    List l;
    cout << "push" << endl;
    srand(time(NULL));
    for(int i=0; i<Max; ++i) {
        a[i] = rand()%(Max*10);
        l.push_front(a[i]);
    }
    l.prin();
    cout << endl;
    cout << "pop " << endl;
    for(int i=0; i<Max; i++)
        l.pop_front();
    l.prin();
    cout << endl;
}


void test_vector() {
    cout << "vector_test" << endl;
    Vector v;
    cout << "push " <<endl;
    srand(time(NULL));
    for(int i=0; i<Max; ++i) {
        a[i] = rand()%(Max*100);
        v.push(a[i]);
    }
    for(int i=0; i<Max; i++)
        cout << v.get(i) << "\t";

    cout << "pop \n";
    for(int i=0; i<Max; i++)
        v.pop_back();
    cout << v.get(0) << "\t";
    cout<<endl;
}


void test_stack() {
    cout << "stack_test\n";
    Stack v;
    cout << "push \n";

    srand(time(NULL));
    for(int i=0; i<Max; ++i) {
        a[i] = rand()%(Max*100);
        v.push(a[i]);
    }
    for(int i=0; i<Max; i++)
        cout << v.get(i) << "\t";

    cout<<endl << "pop 8\n";
    for(int i=0; i<Max; i++)
        v.pop_back();
    cout << v.get(0) << "\t";
    cout << endl;

}


void test_tree() {
    Tree v;
    cout << "tree_test\n" << "insert\n";
    srand(time(NULL));
    for(int i=0; i<Max; ++i) {
        a[i] = rand()%(Max*100);
        v.insert(a[i]);
    }

    cout << endl << "remove \n";
    for(int i=0; i<Max; i++)
        v.remove(a[i]);
    v.prin();

    cout << "\ninsert again\n";
    for(int i=0; i<Max; i++)
        v.insert(a[i]);

    cout << "\ndestory\n";
    v.destory();
    v.prin();
}


void test_Heap() {
    srand(time(NULL));
    for(int i=0; i<Max; ++i) {
        a[i] = rand()%(Max*100);
    }

    copy(a, a+Max, b);
    sort(a, a+Max);
    Heap v(a, Max);
    for(int i=0; i<Max; i++) {
        if (a[i] != v.get()) {
            for (int i=0; i<Max; i++)
                cout << b[i] << " ";
            cout << endl;
            cout << "wrong" << endl;
            break;
        }
        v.remove();
    }
}


void test_Graph() {
    Graph g;
    const int size = 4;
    int a[size] ={1, 2, 3, 4};
    for (int i=0; i<size; i++) {
        g.insert(a[i]);
    }
    g.insert(1, 3);
    g.insert(4, 2);
    g.look();
    //g.remove(7);
    //g.look();
    //g.remove(1);
    //g.look();
    //.remove(3, 5);
    //g.look();
    g.dfs(1);
}


int main()
{
    /// test_List();
    /// test_vector();
    /// test_stack();
    /// test_tree();
    /// test_tree();
    /// test_Heap();
    test_Graph();

    return 0;
}
