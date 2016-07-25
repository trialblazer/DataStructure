#include<iostream>

using namespace std;

void sort(int a[], int begin, int end);

int main() {
    int a[10];
    for (int i=0; i<10; i++)
        cin >> a[i];
    sort(a, 0, 10);
    for (int i=0; i<10; i++)
        cout << a[i] << "  ";
    cout << endl;
    return 0;
}

void sort(int a[], int begin, int end) {
    if (begin+1 == end)
        return;

    int mid = (begin+end)/2;
    if (a[mid-1] > a[mid] && mid>0) {
        int tmpt = a[mid-1];
        a[mid-1] = a[mid];
        a[mid] = tmpt;
    }
    sort(a, begin, mid);
    sort(a, mid, end);
}



#include<iostream>

using namespace std;

void perm(int a[], int begin, int end);

#define Max 4
int b[Max];

int main() {
    int a[Max] = {1,2,3,4};
    for (int i=0; i<Max; i++)
        b[i] = 0;
    perm(a, 0, Max-1);
    return 0;
}


void perm(int a[],int begin, int end) {
    if (begin == end) {
        for (int i=0; i<=end; i++) {
            cout << a[i] << "  ";
        }
        cout << endl;
        return;
    }

    for (int i=0; i<=end; i++) {
        if (b[end] == 0) {
            int tmpt = a[end--];
            a[end+1] = a[i];
            a[i] = tmpt;
            b[end+1] = 1;
            perm(a, begin, end);
            b[end] = 0;
        }
    }
}
