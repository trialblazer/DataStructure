#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define Max 11

void sort1(int a[], int size);  // √∞≈›≈≈–Ú
void sort2(int a[], int size);  // ≤Â»Î≈≈–Ú
void sort3(int a[], int size);  // —°‘Ò≈≈–Ú

int main() {
    int a[Max];
    srand(time(NULL));
    for (int i=1; i<Max; ++i) {
        a[i] = rand()%(Max*10);
        cout << a[i] << "  ";
    }
    cout << endl;
    /// sort1(a, Max);
    /// sort2(a, Max);
    sort3(a, Max);
    for (int i=1; i<Max; i++)
        cout << a[i] << "  ";
    cout << endl;
    return 0;
}

void sort1(int a[], int size) {
    for (int i=1; i<size; i++) {
        for (int j=1; j<size-i; j++) {
            if (a[j]>a[j+1]) {
                int tmpt = a[j];
                a[j] = a[j+1];
                a[j+1] = tmpt;
            }
        }
    }
}


void sort2(int a[], int size) {
    for (int i=2; i<size; i++) {
        a[0] = a[i];
        int j = i-1;
        while (a[0]<a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = a[0];
    }
}

void sort3(int a[], int size) {
    for (int i=1; i<size; i++) {
        int min = i;
        for (int j = i+1; j<size; j++) {
            while (a[min] > a[j])
                min = j;
        }
        if (min != i) {
            int tmpt = a[i];
            a[i] = a[min];
            a[min] = tmpt;
        }
    }
}























