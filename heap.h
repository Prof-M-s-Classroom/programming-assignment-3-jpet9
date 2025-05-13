#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity);      //Constructor - initializes heap with capacity
    ~MinHeap();                 //Destructor - (cleans memory)
    void insert(int vertex, int key);   //inserts vertex at given key
    int extractMin();                   //remove & return smallest key vertex
    void decreaseKey(int vertex, int newKey);   //decrease the key of vertex
    bool isInMinHeap(int vertex);               //check if vertex is in heap
    bool isEmpty();                         //check if heap is empty

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx);           //maintains heap properties
    void swap(int* x, int* y);          //swaps two elements in key
    int parent(int i) {return (i-1)/2;} //returns parent index
    int left(int i){ return (2*i + 1);} //returns the left child
    int right(int i){return (2*i + 2); } // returns the right child
};

#endif