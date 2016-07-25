#ifndef GRAPH_LNK_H
#define GRAPH_LNK_H

#define DEFAULTSIZE 20

#include <iostream>
typedef struct Node1 {
    int index;
    int power;
    struct Node1* Next;

    Node1(const int& data, const int& p) {
        index = data;
        power = p;
        Next = NULL;
    }
}Node1, *Link1;

typedef struct Node {
    char data;
    Link1 Next;
}Node2, *Link2;

class Graph_Lnk {
public:
    Graph_Lnk(bool=false, bool=false, int=DEFAULTSIZE);
    ~Graph_Lnk();
    bool insert_v(const char&);
    bool insert_a(const char&, const char&, int=0);
    bool delete_a(const char&, const char&);
    bool delete_v(const char&);

    void bfs( char&);
    void _bfs( char&);
    void dfs( char&);
    void _dfs( char&);
    void destory();
    void look();

private:
    bool expand();
    int exist(const char&);
    Link1 gettail(const int);
    bool change(const int Old, const int New);
    /// ��NodeTable[]�е����нڵ���indexΪold�ĸ�Ϊnew

private:
    Link2 NodeTable;
    int curnodesize;
    int maxnodesize;

    bool sign1; /// ֵΪfalse��ʾ����ͼ
    bool sign2;  /// ֵΪtrue��ʾ��
};

#endif // GRAPH_LNK_H
