#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
    Graph();
    ~Graph();
    bool insert(int vertex);
    bool insert(int begin, int end);
    bool remove(int vertex);
    bool remove(int begin, int end);
    int getfirstneighbor(int v);
    int getnextneighbor(int v, int w);
    bool look();
    void dfs(int vertex);
    bool isempty();

private:
    void _dfs(int n, int visited[]);
    int getindex(int vertex);
    int *v;
    int **e;
    int vertices;
    int edges;
    int MaxVertices;
};

#endif // GRAPH_H
