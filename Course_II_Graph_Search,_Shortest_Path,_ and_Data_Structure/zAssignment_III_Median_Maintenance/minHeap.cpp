
#include "minHeap.h"

// constructor =================================================================
minHeap::minHeap(int Capacity) : Heap_Data_Structure(Capacity) {
  std::cout << " constructing the left (min) heap \n";
}

// insert a new key in the heap ================================================
void minHeap::InsertKey(int var) {

  if (Heap_Size == Capacity) {
    std::cout << " You reached the max capacity of the heap. \n";
    return;
  }

  // First we insert the new element at the end of array
  Heap_Size++;
  Heap_Array[Heap_Size - 1] = var;

  int i = Heap_Size - 1;
  while (i != 0 && Heap_Array[parent(i)] > Heap_Array[i]) {
    swap(&Heap_Array[parent(i)], &Heap_Array[i]);
    i = parent(i);
  };
}

// returns true if var1 is smaller than var2 ===================================
bool minHeap::compare(int var1, int var2) { return (var1 > var2); }