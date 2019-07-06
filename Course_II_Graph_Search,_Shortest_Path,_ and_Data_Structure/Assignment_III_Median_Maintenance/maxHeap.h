
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
  virtual void InsertKey(int var); // inserts a new element and heapify
  virtual void Heapify(int term);  // heapifying (min or max)

  virtual int extract(); // extract the min/max key in the heap
  virtual int get();     // returns either min or max of the heap (top key)
public:
  maxHeap();
  ~maxHeap();
}

#endif // !MAXHEAP_H