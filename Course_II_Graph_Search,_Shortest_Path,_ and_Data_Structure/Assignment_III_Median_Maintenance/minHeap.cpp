
#include "minHeap.h"

// constructor =================================================================
minHeap::minHeap(int CapSize) : Heap_Data_Structure(int Capsize) {
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

// heapifying function =========================================================
void minHeap::Heapify(int term) {

  int leftItem = left(term);
  int rightItem = right(term);
  int smallest = term;
  if (leftItem < Heap_Size && Heap_Array[leftItem] < Heap_Array[term])
    smallest = leftItem;
  if (rightItem < Heap_Size && Heap_Array[rightItem] < Heap_Array[smallest])
    smallest = rightItem;
  if (smallest != term) {
    swap(&Heap_Array[term], &Heap_Array[smallest]);
    Heapify(smallest);
  }
}