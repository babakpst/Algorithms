
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
  virtual bool compare(int, int);

public:
  minHeap();
  minHeap(int Capacity);
  //~minHeap();
};

#endif // !MINHEAP_H