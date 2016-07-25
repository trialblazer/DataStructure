#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#define MAXSIZE 10
#define DEFAULTSIZE 2147483647
#define DEFAULT_SIZE 0

class Graph_Matrix {
public:
    Graph_Matrix();
    Graph_Matrix(int, int);
    ~Graph_Matrix() {}
    Graph_Matrix& operator = (Graph_Matrix& g);
    bool insert_v(const char);
    bool insert_a(const char, const char, int = 1);
    bool delete_v(const char&);
    bool delete_a(const char&, const char&);
    void dfs(char&);
    void _dfs(char&);
    void bfs(char&);
    void _bfs(char&);
    void destory();
    void look();



private:
    int isexist(const char&);
    int next_head(int tail);

public:
    char vertex[MAXSIZE];
    int arc[MAXSIZE][MAXSIZE];
    int currentsize;

    bool isvisited[MAXSIZE];

    int sign1; ///值为0代表无向图，值为1代表有向图
    int sign2;  ///值为0代表图，值为1代表网
};

#endif // GRAPH_MATRIX_H
