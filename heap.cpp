//
// Created by jampe on 5/6/2025.
//

#include "heap.h"
#include <iostream>
#include <climits>

using namespace std;

MinHeap::MinHeap(int capacity) {
    this->capacity = capacity;
    size = 0;

    //Allocates memory for heap storage
    heapArray = new int[capacity];    //store vertices
    keyArray = new int[capacity];     //store priority keys
    position = new int[capacity];     //maps vertex into heapArray

    //Initializes all keys as -1
    for (int i = 0; i < capacity; i++) {
        position[i] = -1;
        keyArray[i] = INT_MAX;
    }
}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

void MinHeap::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MinHeap::insert(int vertex, int key) {
    //check that there is space in heap
    if (size == capacity) {
        cerr << "Heap Overflow" << endl;
        return;
    }
    //insert at end, store vetex, store key, track position, and increase heap size
    int i = size;
    heapArray[i] = vertex;
    keyArray[vertex] = key;
    position[i] = i;
    size++;

    //fix heap properties
    while (i != 0 && keyArray[heapArray[parent(i)]] > keyArray[heapArray[i]]) {
        position[heapArray[i]] = parent(i);
        position[heapArray[parent(i)]] = i;
        swap(&heapArray[i], &heapArray[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin(){
  //check if heap is empty
  if (size <= 0) {
    cout << "Heap is Empty" << endl;
    return -1;
  }
  //checks if there is only one root node
  if (size == 1) {
    size--;
    return heapArray[0];
  }
  int root = heapArray[0];
  position[root]= -1;

  //replace root with last element
  heapArray[0] = heapArray[size-1];
  position[heapArray[0]] = 0;
  size--;

  minHeapify(0);    //restore heap property

  return root;
}

void MinHeap::decreaseKey(int vertex, int key){
  int i = position[vertex];
  keyArray[vertex] = key;

  //Move up if new key is less than its parent
  while (i != 0 && keyArray[heapArray[parent(i)]] > keyArray[position[parent(i)]]){
    position[heapArray[i]] = parent(i);
    position[heapArray[parent(i)]] = i;
    swap(&heapArray[i], &heapArray[parent(i)]);
    i = parent(i);
  }
}

bool MinHeap::isEmpty(){
  return size == 0;
}

bool MinHeap::isInMinHeap(int vertex){
  return position[vertex] != -1;
}

void MinHeap::minHeapify(int vertex){
  //setting initial conditions
  int l = left(vertex);
  int r = right(vertex);
  int small = vertex;

  //find smallest element between the three
  if (l < size && keyArray[heapArray[l]] < keyArray[heapArray[small]]){
    small = l;
  }
  if (r < size && keyArray[heapArray[r]] < keyArray[heapArray[small]]){
    small = r;
  }

  //if smallest of l or r, heapify keeps going
  if (small != vertex){
    position[heapArray[small]] = vertex;
    position[heapArray[vertex]] = vertex;
    swap(&heapArray[small], &heapArray[vertex]);
    minHeapify(small);
  }
}
