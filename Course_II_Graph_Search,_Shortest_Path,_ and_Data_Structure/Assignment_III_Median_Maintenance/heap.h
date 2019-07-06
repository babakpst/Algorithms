

// libraries
#include <iostream>
#include <vector>

// classes

#ifndef HEAP_H
#define HEAP_H

//==============================================================================
// defining the heap class  ====================================================
class Heap_Data_Structure {

  // -- members
private:
  std::vector<int> Heap_Array; // pointer to array of elements in heap
  int Capacity;                // max possible size of the min heap
  int Heap_Size;               // current number of elements in the heap
public:
  // -- methods
private:
public:
  // Constructor
  Heap_Data_Structure(int HeapSize);

  // required functions to form the heap data structure
  virtual void InsertKey(void) = 0; // inserts a new element and heapify
  virtual void Heapify(void) = 0;   // heapifying (min or max)

  virtual int extract(void) = 0; // extract the min/max key in the heap
  virtual int get(void) = 0; // returns either min or max of the heap (top key)

  void swap(int *x1, int *x2); // swaping two keys in the heap used for bubbling
  void PrintHeap();            // prints the entire heap

  int left(int term);  // returns the left child
  int right(int term); // returns the right child

  int parent(int i); // finds the parent of a key
  int GetHeapSize(); // extracts the heap size
};
#endif // !HEAP_H