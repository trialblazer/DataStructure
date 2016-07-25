#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
    Graph();
    ~Graph();
    bool insert(int vertex);
    bool insert_(int begin, int end);
    bool remove(int value);
    bool remove_(int begin, int end);
    void look(int vertex);
    void destory();

protected:
    int getnode(int vertex);

private:
    int **root;
    int *g;
    int currentsize;
    int Maxsize;
};

#endif // GRAPH_H
