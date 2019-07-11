
// libraries
#include <iostream>

// classes
#include "heap.h"

#ifndef MAXHEAP_H
#define MAXHEAP_H

class maxHeap : public Heap_Data_Structure {
  // members
private:
public:
  // methods
private:
  // required functions to form the heap data structure
  virtual bool compare(int, int);

public:
  maxHeap();
  maxHeap(int CapSize);
  //~maxHeap();
};

#endif // !MAXHEAP_H