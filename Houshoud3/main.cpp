#include <iostream>
#include "Tree.h"
#include <cstring>

using namespace std;

void test() {
    Trie t;
    char a[20];
    int i = 0;
    while (i == 0) {
        if (i < 5)
            cout << "Input the data you want to insert: " << endl;
        while (i++ < 1) {
            cin >> a;
            t.insert(a, strlen(a));
        }
        cout << "prin: " << endl;
        t.prin();
        cout << endl << "Input the data you want to find: ";
        i = 3;
        while (i++ < 7) {
            cin >> a;
            if (t.find(a, strlen(a)) == NULL)
                cout << "No find " << a << "!!" << endl;
            else
                cout << "Yes find " << a << endl;
        }
        cout << "Input the data you want to delete: ";
        cin >> a;
        t.del(a, strlen(a));
        t.prin();
        cout << endl;
    }
}

int main() {
    test();
    return 0;
}
