#include "Graph.h"

#include<stdlib.h>
#include<iostream>

#define DEFAULT_GRAPH_SIZE 15

Graph::Graph() {
    MaxVertices = DEFAULT_GRAPH_SIZE;
    v = new int[MaxVertices];
    e = (int **) new int *[MaxVertices];
    if (v == NULL || e == NULL) {
        std::cerr << "Memory allocate failure!\n";
        exit(-1);
    }
    for (int i=0; i<MaxVertices; i++) {
        e[i] = new int[MaxVertices];
        if (e[i] == NULL) {
            std::cerr << "Memory allocate failure!\n";
            exit(-1);
        }
    }
    vertices =0;
    edges = 0;

}

Graph::~Graph() {
    delete []v;
    for (int i=0; i<MaxVertices; i++)
        delete []e[i];
    delete []e;
}


bool Graph::insert(int vertex) {
    if (vertices < MaxVertices) {
        v[vertices] = vertex;
        for (int i=0; i<=vertices; i++) {
            e[vertices][i] = 0;
            e[i][vertices] = 0;
        }
        vertices++;
        return true;
    } /// else
    return false;
}


bool Graph::insert(int p1, int p2) {
    int index1 = getindex(p1);
    int index2 = getindex(p2);
    if (p1 != -1 && p2 != -1) {
        if (index1 == index2)
            return true;
        e[index1][index2] = 1;
        e[index2][index1] = 1;
        edges++;
        return true;
    } /// else
    return false;
}


bool Graph::remove(int p1, int p2) {
    int index1 = getindex(p1);
    int index2 = getindex(p2);
    if (p1 != -1 && p2 != -1) {
        if (index1 == index2)
            return true;
        e[index1][index2] = 0;
        e[index2][index1] = 0;
        edges--;
        return true;
    }
    return false;
}


bool Graph::remove(int vertex) {
    vertex = getindex(vertex);
    if (vertex != -1) {
        for (int i=0; i<vertices; i++)
                if (e[vertex][i] == 1)
                    edges--;
        if (vertex != (vertices-1)) {
            /// for (int i=0; i<vertices; i++) {
            ///    e[vertex][i] = e[vertices-1][i];
            ///    e[i][vertex] = e[i][vertices-1];
            /// }
            for (int i=0; i<vertices; i++)
                e[vertex][i] = e[vertices-1][i];
            for (int i=0; i<vertices; i++)
                e[i][vertex] = e[i][vertices-1];
        }
        ////////////////////////
        v[vertex] = v[vertices-1];
        ///////////////////////
        vertices--;
        return true;
    }
    return false;
}


bool Graph::look() {
    if (vertices > 0) {
        for (int i=0; i<vertices; i++) {
            std::cout << "和" << v[i] << "相连的点：  ";
            for (int j=0; j<vertices; j++) {
                if (e[i][j] == 1)
                    std::cout << v[j] << "   ";
            }
            std::cout << "\n";
        }
        std::cout << "\n\n";
        return true;
    }
    return false;
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
