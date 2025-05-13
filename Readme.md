[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
James Petropulos

## Description
Briefly describe what your program does and how the code is structured.
This program basically finds the minimum spanning tree of a graph with the implementation 
of Prim's Algorithm. Adjacency matrix is used to represent the graph. A custom min heap is 
created to ensure efficient traversal of minimum weighted edges.
## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------|
| Insert in MinHeap    | O(log V)  |
| Extract Min          | O(log V)  |
| Decrease Key         | O(log V)  |
| Prim’s MST Overall   | O(V^2)    |

## Explain Big O complexity of:
Insert in MinHeap: It inserts a vertex into the heap at the end. It then moves in order to
preserve min-heap properties so worst case it moves through entire height of heap. The height of
binary heap is log V

Extract Min: This removes minimum element and moves last element to the root position. Minheapify 
is called to restore heap property and this leads to the O (log V)

Decrease Key: Reduces key value of vertex in key. This also perlocates through the height of the heap.
Leads to O(log V)

_Explain why your MST implementation has the above runtime._
Our code uses an adjacency matrix which means the code checks all V^2 edges.
Heap operations contribute O(V log V + E log V) but O(V^2) takes over the runtimes.

## Assumptions
We are assuming that the graph is undirected and connected. Main.cpp must not be edited.
No usage of STL priority_queue or set within the code.

## Test Case Description
I tested a basic connected graph, single vertex graph, a graph with multiple edges between same vertices,
and a disconnected graph. They all worked out
Input: 
    Basic connected graph was the given values -> Graph g(5) g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);

Single Vertex Graph -> Graph g(1)

Graph with multiple edges between same vertices -> Graph g(3)
g.addEdge(0, 1, 2);
g.addEdge(0, 1, 5);
g.addEdge(1, 2, 3);
g.addEdge(1, 2, 1);

Disconnected Graph -> g(4)
g.addEdge(0, 1, 2);
g.addEdge(2, 3, 3);

These all worked out with my code.
    

## Challenges faced
It was hard to manage the Min Heap with position[] array. I kept running into the 
problem of not putting the key in the correct position which messed up the decreaseKey().
I also had trouble all heap operations maintained the heap property throughout the code.
I had to keep fixing my heap operations because it was not doing it correctly for a while.