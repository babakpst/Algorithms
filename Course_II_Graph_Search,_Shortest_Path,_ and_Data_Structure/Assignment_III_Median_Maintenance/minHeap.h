
// libraries
#include <iostream>

// classes
#include "heap.h"

#ifndef MINHEAP_H
#define MINHEAP_H

class minHeap : public Heap_Data_Structure {
  // members
private:
public:
  // methods
private:
  // required functions to form the heap data structure
  virtual void InsertKey(int var); // inserts a new element and heapify
  virtual void Heapify(int term);  // heapifying (min or max)
  virtual int extract();

public:
  minHeap();
  minHeap(int Capacity);
  //~minHeap();
};

#endif // !MINHEAP_H