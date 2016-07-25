#include <iostream>
#include "Hash.h"

using namespace std;

void test() {
    Hash h(20, 19);
    int a[10];
    cout << "Please input ten numbers:";
    for (int i=0; i<10; i++) {
        cin >> a[i];
        if (!h.insert(a[i]))
            cout << "fail insert " << a[i] << endl;
    }
    cout << endl;
    for (int i=0; i<20; i++)
        if (h.inf[i] == active)
            cout << i << " : " << h.ht[i] << endl;
    cout << endl;
    cout << "The size of hashtable is " << h.getsize() << endl;
    int p;
    if (h.search(6, p))
        cout << "Yes, find 6. It's pos is " << p << endl;
    if (!h.search(12, p))
        cout << "No find 12" << endl;
    if (h.remove(6))
        cout << "Yes, remove 6" << endl;
    cout << "The size of hashtable is " << h.getsize() << endl;
    if (!h.search(6, p))
        cout << "No find 6" << endl;
    h.makempty();
    cout << "After makeempth,The size of hashtable is " << h.getsize() << endl;
}

int main()
{
    test();
    cout << endl;
    return 0;
}
