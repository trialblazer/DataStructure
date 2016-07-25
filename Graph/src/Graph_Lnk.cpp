#include "Graph_Lnk.h"
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

Graph_Lnk::Graph_Lnk(bool s1, bool s2, int sz) {
    maxnodesize = sz;
    NodeTable = (Link2)new Node2[maxnodesize];
    if (NodeTable == NULL)
        exit(1);
    curnodesize = 0;
    sign1 = s1;
    sign2 = s2;
}

Graph_Lnk::~Graph_Lnk() {
    destory();
}

void Graph_Lnk::destory() {
    for (int i=0; i<curnodesize; i++) {
        Link1 pos = NodeTable[i].Next;
        while (pos != NULL) {
            Link1 temp = pos;
            pos = pos->Next;
            delete temp;
        }
    }
    delete []NodeTable;
    maxnodesize = DEFAULTSIZE;
    curnodesize = 0;
    sign1 = false;
    sign2 = false;
}

bool Graph_Lnk::expand() {
    maxnodesize *= 2;
    Link2 NewTable = (Link2)new Node2[maxnodesize];
    if (NewTable == NULL)
        return false;
    for (int i=0; i<curnodesize; i++) {
        NewTable[i].data = NodeTable[i].data;
        NewTable[i].Next = NodeTable[i].Next;
    }
    delete []NodeTable;
    NodeTable = NewTable;
    return true;
}

int Graph_Lnk::exist(const char& vertex) {
    for (int i=0; i<curnodesize; i++)
        if (NodeTable[i].data == vertex)
            return i;
    return -1;
}

Link1 Graph_Lnk::gettail(const int index) {
    Link1 pos = NodeTable[index].Next;
    if (pos == NULL)
        return NULL;
    while (pos->Next != NULL)
        pos = pos->Next;
    return pos;
}

bool Graph_Lnk::insert_a(const char& vertex1, const char& vertex2, int power) {
    int pos1 = exist(vertex1), pos2 = exist(vertex2);
    Link1 newnode = (Link1)new Node1(pos2, power);
    if (newnode == NULL)
        return false;
     if (pos1 != -1 && pos2 != -1) {
        Link1 tail = gettail(pos1);
        if (tail == NULL)
            NodeTable[pos1].Next = newnode;
        else
            tail->Next = newnode;
        if (!sign1) {
            sign1 = true;
            if (!insert_a(vertex2, vertex1, power)) {
                tail->Next = NULL;
                delete newnode;
                return false;
            }
            sign1 = false;
        }
        return true;
    }
    return false;
}

bool Graph_Lnk::insert_v(const char& vertex) {
    if (curnodesize == maxnodesize)
        if (!expand())
            return false;
    NodeTable[curnodesize].data = vertex;
    NodeTable[curnodesize++].Next = NULL;
    return true;
}


bool Graph_Lnk::delete_a(const char& v1, const char& v2) {
    int pos1 = exist(v1), pos2 = exist(v2);
    Link1 pos = NULL, temp = NULL;
/// 用sign来标记，然后执行删除具体操作，是因为当为无向图是在另一条链中删除失败时
/// 这种操作直接可以返回false，而不必把当前链已删除的节点复原
    int sign = 0;

    if (sign) {
/// 再次用了递归，如果该图是无向图，就把sign1设为true，再调用一次自身删除另一条边
/// 由于已经把sign1设为true；所以只删除NodeTable[v2]中的V1节点
/// 调用完毕后再把sign复原为false
        loop:if (!sign1) {
            sign1 = true;
            if (!delete_a(v2, v1)) {
                sign1 = false;
                return false;
            }
            sign1 = false;
        }

        if (sign == 0) {
            Link1 t = pos;
            NodeTable[pos1].Next = pos->Next;
            delete t;
        }
        if (sign == 1) {
            pos->Next = temp->Next;
            delete temp;
            temp = NULL;
        }
        return true;
    }
    if (pos1 != -1 && pos2 != -1) {
        pos = NodeTable[pos1].Next;
        if (pos == NULL)
            return false;
        if (pos->index == pos2)
            goto loop;
        temp = pos->Next;
        while (temp != NULL) {
            if (temp->index == pos2) {
                sign = 1;
                goto loop;
            }
            pos = pos->Next;
            temp = temp->Next;
        }
        if (temp == NULL)
            return false;
    }
    return false;
}

bool Graph_Lnk::change(const int Old, const int New) {
    for (int i=0; i<curnodesize; i++) {
        Link1 pos = NodeTable[i].Next;
        while (pos != NULL) {
            if (pos->index == Old)
                pos->index = New;
            pos = pos->Next;
        }
    }
}

bool Graph_Lnk::delete_v(const char& v) {
    int pos = exist(v);
    if (pos != -1) {
        while (NodeTable[pos].Next != NULL) {
            Link1 temp = NodeTable[pos].Next;
            delete_a(v, NodeTable[temp->index].data);
        }
        NodeTable[pos].data = NodeTable[curnodesize-1].data;
        NodeTable[pos].Next = NodeTable[curnodesize-1].Next;
        NodeTable[pos].Next = NULL;
        curnodesize--;
        change(curnodesize, pos);
        return true;
    }
    return false;
}

void Graph_Lnk::dfs(char& v) {
    int temp = exist(v);
    if (temp == -1)
        return;
    _dfs(v);
    for (int i=0; i<curnodesize; i++) {
        if (isvisited[i] == false)
            _dfs(vertex[i]);
    }
    for (int i=0; i<currentsize; i++)
        isvisited[i] = false;
}

void Graph_Lnk::_dfs(char& v) {
    int temp = isexist(v), t;
    if (isvisited[temp] ==  false) {
        cout << v << "  ";
        isvisited[temp] = true;
    }
    do {
        t = next_head(temp);
        if (t == -1)
            break;
        _dfs(vertex[t]);
    } while (1);
}

void Graph_Lnk::bfs(char& v) {
    int temp = isexist(v);
    if (temp == -1)
        return;
    cout << v << "  ";
    isvisited[temp] = true;
    _bfs(v);
    for (int i=0; i<currentsize; i++) {
        if (isvisited[i] == false) {
            cout << vertex[i] << "  ";
            isvisited[i] = true;
            _dfs(vertex[i]);
        }
    }
    for (int i=0; i<MAXSIZE; i++)
        isvisited[i] = false;
}

void Graph_Lnk::_bfs(char& v) {
    int temp = isexist(v);
    queue<int> s;
    while (1) {
        int t = next_head(temp);
        if (t == -1)
            break;
        isvisited[t] = true;
        cout << vertex[t] << "  ";
        s.push(t);
    }
    while (!s.empty()) {
        int top = s.front();
        s.pop();
        _bfs(vertex[top]);
    }
}

void Graph_Lnk::look() {
    for (int i=0; i<curnodesize; i++) {
        cout << NodeTable[i].data << "-->";
        Link1 pos = NodeTable[i].Next;
        while (pos != NULL) {
            cout << pos->index << ". ";
            pos = pos->Next;
        }
        cout << endl;
    }
}































