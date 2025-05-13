#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
    Graph(int vertices);    //Constructor to initialize adjacency matrix
    ~Graph();           //Destructor to free memory/
    void addEdge(int u, int v, int weight);     //Adds undirected edge
    void primMST(); // Must print MST edges and total weight

private:
    int** adjMatrix;       //2D array for adjacency matrix
    int numVertices;       //Number of vertices in the graph
};

#endif