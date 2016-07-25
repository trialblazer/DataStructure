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

/// Graph_Matrix测试类
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
        cout << "1.创建一个图。" << endl;
        cout << "2.销毁图。" << endl;
        cout << "3.插入节点。" << endl;
        cout << "4.插入边。" << endl;
        cout << "5.删除节点。" << endl;
        cout << "6.删除边。" << endl;
        cout << "7.深度遍历。" << endl;
        cout << "8.广度遍历。" << endl;
        cout << "9.查看。" << endl;
        cout << "0.退出。" << endl;
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
        cout << "空图！" << endl;
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
    cout << "创建无向图（0），有向图（1）：";
    cin >> sign1;
    cout << "创建图（0），网（1）：";
    cin >> sign2;
    g = new T(sign1, sign2);
}
template <class T> void Test<T>::insert_v() {
    cout << "请输入要插入节点的个数：";
    int size;
    cin >> size;
    cout << "请依次输入要插入的节点：";
    char vertex, start, tail;
    for (int i=0; i<size; i++) {
        cin >> vertex;
        if (!g->insert_v(vertex)) {
            cout << "插入失败" << endl;
            Sleep(3000);
        }
    }
}
template <class T> void Test<T>::insert_a() {
    char head, tail;
    cout << "请输入要插入的边（按‘#’结束）：";
    cin >> tail;
    while (tail != '#') {
        cin >> head;
        int power;
        if (sign2 == 1) {
            cout << "请输入该边的权值：";
            cin >> power;
            if (!g->insert_a(head, tail, power)) {
                cout << "插入失败" << endl;
                Sleep(3000);
            }
        } else
            if (!g->insert_a(head, tail)) {
                cout << "插入失败" << endl;
                Sleep(3000);
            }
        cin >> tail;
    }
}
template <class T> void Test<T>::remove_a() {
    cout << "请输入要删除的边：";
    char head, tail;
    cin >> tail >> head;
    if (!g->delete_a(head, tail)) {
        cout << "删除失败" << endl;;
        Sleep(3000);
    }
}
template <class T> void Test<T>::remove_v() {
    cout << "请输入要删除的节点：";
    char vertex;
    cin >> vertex;
    if (!g->delete_v(vertex)) {
        cout << "删除失败" << endl;
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
    cout << "请输入开始节点：";
    char start;
    cin >> start;
    g->dfs(start);
    getch();
}
template <class T> void Test<T>::bfs() {
    if (g == NULL)
        return;
    cout << "请输入开始节点：";
    char start;
    cin >> start;
    g->bfs(start);
    getch();
}

#endif // TEST_H
