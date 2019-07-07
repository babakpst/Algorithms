
#include "maxHeap.h"

// constructor =================================================================
maxHeap::maxHeap(int Capacity) : Heap_Data_Structure(Capacity) {
  std::cout << " constructing the right (max) heap \n";
}

// insert a new key in the heap ================================================
void maxHeap::InsertKey(int var) {

  if (Heap_Size == Capacity) {
    std::cout << " You reached the max capacity of the heap. \n";
    return;
  }

  // First we insert the new element at the end of array
  Heap_Size++;
  Heap_Array[Heap_Size - 1] = var;

  int i = Heap_Size - 1;
  while (i != 0 && Heap_Array[parent(i)] < Heap_Array[i]) {
    swap(&Heap_Array[parent(i)], &Heap_Array[i]);
    i = parent(i);
  };
}

// heapifying function =========================================================
void maxHeap::Heapify(int term) {

  int leftItem = left(term);
  int rightItem = right(term);
  int smallest = term;
  if (leftItem > Heap_Size && Heap_Array[leftItem] > Heap_Array[term])
    smallest = leftItem;
  if (rightItem > Heap_Size && Heap_Array[rightItem] > Heap_Array[smallest])
    smallest = rightItem;
  if (smallest != term) {
    swap(&Heap_Array[term], &Heap_Array[smallest]);
    Heapify(smallest);
  }
}
/*
// extract the min of the heap and heapifies the rest of the heap ==============
int maxHeap::extract() {
  if (Heap_Size <= 0)
    return INT16_MAX;
  if (Heap_Size == 1) {
    Heap_Size--;
    return Heap_Array[0];
  }

  // If the heap has more than one element, we need to extract the root and
  // bubble
  int root = Heap_Array[0];
  Heap_Array[0] = Heap_Array[Heap_Size - 1];
  Heap_Size--;
  Heapify(0);

  return root;
}
*/