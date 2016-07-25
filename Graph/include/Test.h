#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <windows.h>
#include "Graph_Matrix.h"
#include "Graph_Lnk.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define MAXSIZE 10

/// Graph_Matrix������
template <class T> class Test {
    void creat();
    void insert_v();
    void insert_a();
    void remove_v();
    void remove_a();
    void destory();
    void dfs();
    void bfs();
    void look();

public:
    void menue();
    Test():sign1(0), sign2(0), g(NULL) {}
    ~Test() {delete g;}

private:
    int sign1, sign2;
    T *g;
};

template <class T> void Test<T>::menue() {
    while (1) {
        system("cls");
        cout << "1.����һ��ͼ��" << endl;
        cout << "2.����ͼ��" << endl;
        cout << "3.����ڵ㡣" << endl;
        cout << "4.����ߡ�" << endl;
        cout << "5.ɾ���ڵ㡣" << endl;
        cout << "6.ɾ���ߡ�" << endl;
        cout << "7.��ȱ�����" << endl;
        cout << "8.��ȱ�����" << endl;
        cout << "9.�鿴��" << endl;
        cout << "0.�˳���" << endl;
        char a;
        fflush(stdin);
        a = getch();
        switch(a) {
            case '1':system("cls"); creat(); break;
            case '2':system("cls"); destory(); break;
            case '3':system("cls"); insert_v(); break;
            case '4':system("cls"); insert_a(); break;
            case '5':system("cls"); remove_v(); break;
            case '6':system("cls"); remove_a(); break;
            case '7':system("cls"); dfs(); break;
            case '8':system("cls"); bfs(); break;
            case '9':system("cls"); look(); break;
            case '0':return;
            default: break;
        }
    }
}
template <class T> void Test<T>::look() {
    if (g == NULL) {
        cout << "��ͼ��" << endl;
        Sleep(3000);
    } else {
        g->look();
        char a = getch();
    }
}
template <class T> void Test<T>::creat() {
    if (g != NULL) {
        delete g;
        g = NULL;
    }
    cout << "��������ͼ��0��������ͼ��1����";
    cin >> sign1;
    cout << "����ͼ��0��������1����";
    cin >> sign2;
    g = new T(sign1, sign2);
}
template <class T> void Test<T>::insert_v() {
    cout << "������Ҫ����ڵ�ĸ�����";
    int size;
    cin >> size;
    cout << "����������Ҫ����Ľڵ㣺";
    char vertex, start, tail;
    for (int i=0; i<size; i++) {
        cin >> vertex;
        if (!g->insert_v(vertex)) {
            cout << "����ʧ��" << endl;
            Sleep(3000);
        }
    }
}
template <class T> void Test<T>::insert_a() {
    char head, tail;
    cout << "������Ҫ����ıߣ�����#����������";
    cin >> tail;
    while (tail != '#') {
        cin >> head;
        int power;
        if (sign2 == 1) {
            cout << "������ñߵ�Ȩֵ��";
            cin >> power;
            if (!g->insert_a(head, tail, power)) {
                cout << "����ʧ��" << endl;
                Sleep(3000);
            }
        } else
            if (!g->insert_a(head, tail)) {
                cout << "����ʧ��" << endl;
                Sleep(3000);
            }
        cin >> tail;
    }
}
template <class T> void Test<T>::remove_a() {
    cout << "������Ҫɾ���ıߣ�";
    char head, tail;
    cin >> tail >> head;
    if (!g->delete_a(head, tail)) {
        cout << "ɾ��ʧ��" << endl;;
        Sleep(3000);
    }
}
template <class T> void Test<T>::remove_v() {
    cout << "������Ҫɾ���Ľڵ㣺";
    char vertex;
    cin >> vertex;
    if (!g->delete_v(vertex)) {
        cout << "ɾ��ʧ��" << endl;
        Sleep(3000);
    }
}
template <class T> void Test<T>::destory() {
    g->destory();
    delete g;
    g = NULL;
}
template <class T> void Test<T>::dfs() {
    if (g == NULL)
        return;
    cout << "�����뿪ʼ�ڵ㣺";
    char start;
    cin >> start;
    g->dfs(start);
    getch();
}
template <class T> void Test<T>::bfs() {
    if (g == NULL)
        return;
    cout << "�����뿪ʼ�ڵ㣺";
    char start;
    cin >> start;
    g->bfs(start);
    getch();
}

#endif // TEST_H
