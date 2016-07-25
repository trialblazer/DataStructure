#include "Graph_Matrix.h"
#include <iostream>
#include <queue>
#include <conio.h>
using namespace std;

Graph_Matrix::Graph_Matrix():currentsize(0), sign1(0), sign2(0) {
    for (int i=0; i<MAXSIZE; i++) {
        for (int j=0; j<MAXSIZE; j++) {
            arc[i][j] = DEFAULT_SIZE;
            cout << arc[i][j] << " ";
        }
        isvisited[i] = false;
    }
    getch();
}


Graph_Matrix::Graph_Matrix(int s1, int s2):currentsize(0), sign1(s1), sign2(s2) {
    for (int i=0; i<MAXSIZE; i++) {
        for (int j=0; j<MAXSIZE; j++) {
            if (sign2)
                arc[i][j] = DEFAULTSIZE;
            else
                arc[i][j] = DEFAULT_SIZE;
        }
        isvisited[i] = false;
    }
}

Graph_Matrix& Graph_Matrix::operator = (Graph_Matrix& g) {
    sign1 = g.sign1;
    sign2 = g.sign2;
    currentsize = g.currentsize;
    for (int i=0; i<MAXSIZE; i++) {
        vertex[i] = g.vertex[i];
        for (int j=0; j<MAXSIZE; j++) {
            arc[i][j] = g.arc[i][j];
        }
        isvisited[i] = g.isvisited[i];
    }
    return *this;
}

void Graph_Matrix::destory() {
    currentsize = 0;
    for (int i=0; i<MAXSIZE; i++) {
        for (int j=0; j<MAXSIZE; j++){
            if (sign2)
                arc[i][j] = DEFAULT_SIZE;
            else
                arc[i][j] = DEFAULTSIZE;
        }
    }
}

int Graph_Matrix::isexist(const char& v) {
    for (int i=0; i<currentsize; i++)
        if (v == vertex[i])
            return i;
    return -1;
}

bool Graph_Matrix::insert_v(const char v) {
    if (currentsize < MAXSIZE) {
        vertex[currentsize++] = v;
        return true;
    }
    return false;
}

///bool Graph_Matrix::insert_a(const char head, const char tail, int power=1)
bool Graph_Matrix::insert_a(const char head, const char tail, int power) {
    int x = isexist(head), y = isexist(tail);
    if (x !=-1 && y !=-1) {
        int temp = sign2==0? DEFAULT_SIZE:DEFAULTSIZE;
        if (arc[x][y] == temp) {
            arc[x][y] = power;
            if (sign2 == 0 && sign1 == 0)
                arc[y][x] = power;
            return true;
        }
    }
    return false;
}

bool Graph_Matrix::delete_v(const char& v) {
    int temp = isexist(v);
    if (temp != -1) {
        vertex[temp] = vertex[--currentsize];
        for (int i=0; i<=currentsize; i++) {
            arc[temp][i] = arc[currentsize][i];
            arc[i][temp] = arc[i][currentsize];
        }
        int t = sign2==0? DEFAULT_SIZE:DEFAULTSIZE;
        for (int i=0; i<=currentsize; i++) {
            arc[currentsize][i] = t;
            arc[currentsize][temp] = t;
            return true;
        }
    }
    return false;
}

bool Graph_Matrix::delete_a(const char& start, const char& tail) {
    int x = isexist(start), y = isexist(tail);
    if (x !=-1 && y !=-1) {
        int t = sign2==0? DEFAULT_SIZE:DEFAULTSIZE;
        arc[x][y] = t;
        if (!sign2)
            arc[y][x] = t;
        return true;
    }
    return false;
}

int Graph_Matrix::next_head(int tail) {
    int temp = sign2==0? DEFAULT_SIZE:DEFAULTSIZE;
    for (int i=0; i<currentsize; i++) {
        if (isvisited[i] == false && arc[i][tail] != temp)
            return i;
    }
    return -1;
}

void Graph_Matrix::dfs(char& v) {
    int temp = isexist(v);
    if (temp == -1)
        return;
    _dfs(v);
    for (int i=0; i<currentsize; i++) {
        if (isvisited[i] == false)
            _dfs(vertex[i]);
    }
    for (int i=0; i<currentsize; i++)
        isvisited[i] = false;
}

void Graph_Matrix::_dfs(char& v) {
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

void Graph_Matrix::bfs(char& v) {
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

void Graph_Matrix::_bfs(char& v) {
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

void Graph_Matrix::look() {
    cout << "   ";
    for (int i=0; i<currentsize; i++) {
        if (sign2)
            cout << vertex[i] << "    ";
        else
            cout << vertex[i] << "   ";
     }
    cout << endl;
    for (int i=0; i<currentsize; i++) {
        cout << vertex[i] << "  ";
        for (int j=0; j<currentsize; j++)
            cout << arc[i][j] << "  ";
        cout << endl;
    }
}
















































