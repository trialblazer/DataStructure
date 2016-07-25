#include <iostream>
#include<ctime>
#include <algorithm>
#include<cstdlib>

// #include "List.h"
// #include "Vector.h"
// #include "Stack.h"
// #include "Tree.h"
// #include "Heap.h"
#include "Graph.h"

#define Max 10

using namespace std;

int a[Max], b[Max];

/*

void test_List() {
    cout << "List_test" << endl;
    List l;
    cout << "push" << endl;
    srand(time(NULL));
    for(int i=0; i<Max; ++i) {
        a[i] = rand()%(Max*10);
        l.push_back(a[i]);
    }
    cout << l.search(a[5]) << endl;
    cout << "pop->prin " << endl;
    for(int i=0; i<Max/2; i++)
        l.pop_front();

    l.destory();

    cout << l.search(a[5]) << endl;
    l.prin_back();

    cout << endl << "push" << endl;
    for (int i=1; i<=Max; i++)
        l.push_front(i);
    cout << l.get(5) << endl;
    cout << "pop->prin" << endl;
    for (int i=0; i<Max; i++)
        l.pop_back();
    l.prin_front();
    cout << endl;

    for (int i=Max; i>=0; i--)
        l.push_back(i);
    l.sort();
    for (int i=0; i<Max; i++) {
        cout << l.get(1) << "  ";
        l.pop_front();
    }
    cout << endl;
}


void test_vector() {
    cout << "vector_test" << endl;
    Vector v;
    int q = v.getcurrentsize();
    cout << "push " <<endl;
    srand(time(NULL));
    for(int i=0; i<Max; ++i) {
        a[i] = rand()%(Max*10);
        v.push(a[i]);
    }
    cout << endl;
    cout << "pop \n";
    for(int i=0; i<q; i++)
        v.pop_back();
    cout << v.get(0) << "  ";
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
        cout << v.get(i) << "  ";
    cout<<endl << "pop 8\n";
    v.sort();
    for(int i=0; i<Max; i++) {
        cout << v.gettop() << "  ";
        v.pop();
    }
    cout << endl << v.gettop() << "\t";
    cout << endl;
}


void test_tree() {
    Tree v;
    cout << "tree_test\n" << "insert\n";
    srand(time(NULL));
    for(int i=0; i<Max; ++i) {
        a[i] = rand()%(Max*10);
        v.insert(a[i]);
    }
    cout << endl << "remove \n";
    for(int i=0; i<Max; i++)
        v.remove(a[i]);
    v.inorder();
    cout << endl;

    cout << "\ninsert again\n";
    for(int i=0; i<Max/2; i++)
        v.insert(a[i]);
    for(int i=Max/2; i<Max; i++)
        v.insert(a[i]);
    if (v.find(a[Max/2]))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    cout << "\ndestory\n";
    v.destory();
    v.postorder();
}



void test_Heap() {
    Heap v;
    srand(time(NULL));
    for(int i=0; i<Max; ++i) {
        a[i] = rand()%(Max*10);
        v.insert(a[i]);
    }
    cout << endl;
    copy(a, a+Max, b);
    sort(a, a+Max);
    //Heap v(a, Max);
    for(int i=0; i<Max; i++) {
        if (a[i] != v.gettop()) {
            cout << "wrong" << endl;
            break;
        }
        v.remove_top();
    }
}
*/


void test_Graph() {
    Graph g;
    const int size = 4;
    int a[size] ={1, 2, 3, 4};
    for (int i=0; i<size; i++) {
        g.insert(a[i]);
    }
    g.insert_(1, 3);
    g.insert_(4, 2);
    g.look(7);
    //g.remove(7);
    //g.look();
    //g.remove(1);
    //g.look();
    //.remove(3, 5);
    //g.look();
    //g.dfs(1);
}



int main()
{
    /// test_List();
    /// test_vector();
    /// test_stack();
    /// test_tree();
    /// test_Heap();
    test_Graph();

    return 0;
}
