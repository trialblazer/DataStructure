#include "Graph.h"

#include<iostream>
#include<stdlib.h>

#define DEFAULT_GRAPH_SIZE 10

Graph::Graph() {
    Maxsize = DEFAULT_GRAPH_SIZE;
    currentsize = -1;
    root = new int*[Maxsize];
    if (root == NULL) {
        std::cerr << "Memory allocate failure!\n";
        exit(1);
    }
    for (int i=0; i<Maxsize; i++) {
        //*root = new int[Maxsize];
        root[i] = new int[Maxsize];
        if (*root == NULL) {
            std::cerr << "Memory allocate failure!\n";
            exit(1);
        }
    }
    g = new int[Maxsize];
    if (g == NULL)
        exit(1);
}
/*
Graph::~Graph() {
    for (int i=0; i<Maxsize; i++)
        delete []p[i];
        //delete []*(p[i]);
    delete []p;
    delete []g;
}*/

bool Graph::insert(int vertex) {
    if (currentsize == Maxsize)
        return false;
    currentsize++;
    for (int i=0; i<Maxsize; i++) {
        root[currentsize][i] = 0;
        root[i][currentsize] = 0;
    }
    g[currentsize] = vertex;
    return true;
}

bool Graph::insert_(int begin, int end) {
    int i = getnode(begin);
    int j = getnode(end);
    if (i == -1 || j == -1)
        return false;
    if (i != j) {
        root[i][j] = 1;
        root[j][i] = 1;
    }
    return true;
}

bool Graph::remove(int vertex) {
    int j = getnode(vertex);
    if (j == -1)
        return false;
    for (int i=0; i<currentsize; i++) {
        root[j][i] = root[currentsize][i];
        root[i][j] = root[i][currentsize];
    }
    currentsize--;
    return true;
}

bool Graph::remove_(int begin, int end) {
    int i = getnode(begin);
    int j = getnode(end);
    if (i == -1 || j == -1)
        return false;
    root[i][j] = 0;
    root[j][i] = 0;
    return true;
}

void Graph::destory() {
    currentsize = 0;
}

//如果Value是数组中的数，则返回与它相连的数，否则返回-1.
void Graph::look(int vertex) {
    int j = getnode(vertex);
    std::cout << "和" << g[j] << "相连的点： ";
    if (j != -1) {
        for (int i=0; i<currentsize; i++)
            if (root[j][i] == 1)
                std::cout << g[i] << ",  ";
    }
}

// 如果Value是图中的数，则返回其在数组中的下标，否则-1.
int Graph::getnode(int vertex) {
    for (int i=0; i<currentsize; i++) {
        if (g[i] == vertex)
            return i;
    }
    return -1;
}











/*void Graph::dfs(int p1) {
    /// if (!isempty()) {
        int vertex = getindex(p1);
        if (vertex != -1) {
            int visited[vertices];
            int i =0;
            _dfs(vertex, visited, &i);
        }
    /// }
}


void Graph::_dfs(int n, int visited[], int *tmp) {
    std::cout << v[n] << "   ";
    visited[(*tmp)++] = n;
    for (int j =0; j<vertices; j++) {
        if (e[n][j] == 1) {
            int k =0;
            for (int i=0; i<*tmp; i++) {
                if (visited[i] == j) {
                    k = 1;
                    break;
                }
            }
            if (k != 1) {
                _dfs(j, visited, tmp);
                /// break;
            }
        }
    }
}*/

/*
void Graph::dfs(int p1) {
        int vertex = getindex(p1);
        if (vertex != -1) {
            int visited[vertices];
            for (int i=0; i<vertices; i++)
                visited[i] = 0;
            for (int i=0; i<vertices; i++)
                if (0 == visited[i])
                    _dfs(i, visited);
        }
}


void Graph::_dfs(int n, int visited[]) {
    std::cout << v[n] << "   ";
    visited[n] = 1;
    for (int j =0; j<vertices; j++) {
        if (e[n][j] == 1 && visited[j] == 0)
                _dfs(j, visited);
    }
}

int Graph::getindex(int vertex) {
    for(int i=0; i<vertices; i++)
        if (vertex == v[i])
            return i;
    return -1;
}


bool Graph::isempty() {
    if (vertices == 0)
        return true;
    return false;
}


*/









