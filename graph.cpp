//
// Created by jampe on 5/6/2025.
//
#include "graph.h"
#include <iostream>
#include "heap.h"
#include <climits>

using namespace std;

Graph::Graph(int vertices) {
    //Allocate memory for adjacent matrix
    adjMatrix = new int*[vertices];
    numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
      adjMatrix[i] = new int[vertices];
      for (int j = 0; j < vertices; j++) {
        adjMatrix[i][j] = 0;
      }
    }
}

Graph::~Graph() {
  for (int i = 0; i < numVertices; i++) {
    delete[] adjMatrix[i];
  }
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::primMST(){
  int* parent = new int[numVertices];    //Store MST structure
  int* value = new int[numVertices];     //Key values for vertices

  MinHeap minHeap(numVertices);

  //Initialize keys
  for (int i = 0; i < numVertices; i++) {
    parent[i] = -1;
    value[i] = INT_MAX;
    minHeap.insert(i, value[i]);
  }

  value[0] = 0;
  minHeap.decreaseKey(0, value[0]);

  while (!minHeap.isEmpty()) {
    int u = minHeap.extractMin();
    //check all adjacent vertices
    for (int i = 0; i < numVertices; i++) {
      if (adjMatrix[u][i] && minHeap.isInMinHeap(i) && adjMatrix[u][i] < value[i]) {
            value[i] = adjMatrix[u][i];
            parent[i] = u;
            minHeap.decreaseKey(i, value[i]);
      }
    }
  }
  //Print MST edges and total weight
  int weight = 0;
  for (int i = 1; i < numVertices; i++) {
    cout << parent[i] << "-" << i << "   Weight: " << adjMatrix[i][parent[i]] << endl;
    weight += adjMatrix[i][parent[i]];
  }
  cout << "Total Weight: " << weight << endl;
  delete[] parent;
  delete[] value;
 }