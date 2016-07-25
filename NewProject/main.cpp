#include <stdio.h>
#include <list>
#include <algorithm>
using namespace std;
const int SIZE = 8;

int offset[8][2] = {{-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}};

typedef struct {
    int x, y;
}Node;

typedef struct ChessBoard {
    int count, ch[SIZE][SIZE];
    list<Node> path;

    void inint();
    void look();
    int get_num(int x, int y);
    bool find_best(int x, int y, int num, Node key);
    void walk_chess(int x, int y);
}CB;

void CB::inint() {
    count = 0;
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            ch[i][j] = 0;
        }
    }
}

void CB::look() {
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++)
            printf("%d ", ch[i][j]);
        puts("");
    }
}

int CB::get_num(int x, int y) {
    int num = 0, i;
    for (i=0; i<8; i++) {
        if (ch[x+offset[i][0]][y+offset[i][1]] == 0)
            num++;
    }
    return num;
}


bool CB::find_best(int x, int y, int num, Node key) {
    Node key;
    int a[8], b[8], m, n, i, j;
    for (i=0; i<8; i++) {
        m = x+offset[i][0];
        n = y+offset[i][1];
        if (ch[m][n] != 0) {
            a[i] = 9;
            b[i] = a[i];
        } else {
            a[i] = get_num(m, n);
            b[i] = i;
        }
    }
    for (i=0; i<8; i++) {
        for (j=0; j<7-i; j++)
            if (a[j]>a[j+1]) {
                swap(a[j], a[j+1]);
                swap(b[j], b[j+1]);
            }
    }
    while (a[num]>8) {
        num++;
    }
    if (num>7)
        return false;
    key.x = x+offset[b[num]-1][0];
    key.y = y+offset[b[num]-1][1];
    return true;
}

void CB::walk_chess(int x, int y) {
    Node temp;
    temp.x = x;
    temp.y = y;
    path.insert(temp);
    ch[x][y] = 1;
    while (1) {
        if (count == SIZE*SIZE) {
            int n = SIZE*SIZE;
            while (!temp.empty()) {
                temp = path.front();
                path.pop_back();
                ch[temp.x][temp.y] = n--;
            }
            look();
            return;
        }
        int num=0, i;
        bool sign = false;
        for (i=0; i<8; i++) {
            temp = find_best(temp.x, temp.y, i);
            continue;
        }
    }
}







int main() {

    return 0;
}
