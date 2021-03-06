
// heap class

#include "heap.h"

// constructor =================================================================
Heap_Data_Structure::Heap_Data_Structure(int Capacity) : Capacity{Capacity} {
  std::cout << " Constructing the heap array! \n";
  Heap_Size = 0;

  Heap_Array.reserve(Capacity);
}

Heap_Data_Structure::~Heap_Data_Structure() {}

// swaping two keys in the heap ================================================
void Heap_Data_Structure::swap(int *x1, int *x2) {
  int temp = *x1;
  *x1 = *x2;
  *x2 = temp;
}

// finds the parent of a key ===================================================
int Heap_Data_Structure::parent(int i) { return (i - 1) / 2; }

// prints the heap
void Heap_Data_Structure::PrintHeap() {
  std::cout << "\n Final heap array: \n";
  for (int i = 0; i < Heap_Size; i++)
    std::cout << " heap: " << Heap_Array[i] << "\n";
}

// extract the min of the heap and heapifies the rest of the heap ==============
int Heap_Data_Structure::extract() {
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

// heapifying function =========================================================
void Heap_Data_Structure::Heapify(int term) {

  int leftItem = left(term);
  int rightItem = right(term);
  int smallest = term;
  if (leftItem < Heap_Size && compare(Heap_Array[leftItem], Heap_Array[term]))
    smallest = leftItem;
  if (rightItem < Heap_Size &&
      compare(Heap_Array[rightItem], Heap_Array[smallest]))
    smallest = rightItem;
  if (smallest != term) {
    swap(&Heap_Array[term], &Heap_Array[smallest]);
    Heapify(smallest);
  }
}

// insert a new key in the heap ================================================
void Heap_Data_Structure::InsertKey(int var) {

  if (Heap_Size == Capacity) {
    std::cout << " You reached the max capacity of the heap. \n";
    return;
  }

  // First we insert the new element at the end of array
  Heap_Size++;
  Heap_Array[Heap_Size - 1] = var;

  int i = Heap_Size - 1;
  while (i != 0 && compare(Heap_Array[i], Heap_Array[parent(i)])) {
    swap(&Heap_Array[parent(i)], &Heap_Array[i]);
    i = parent(i);
  };
}

// returns the left child ======================================================
int Heap_Data_Structure::left(int term) { return 2 * term + 1; }

// returns the right child =====================================================
int Heap_Data_Structure::right(int term) { return 2 * term + 2; }

// returns the min of the heap =================================================
int Heap_Data_Structure::get() { return Heap_Array[0]; }

// returns the numbers of keys in the heap =====================================
int Heap_Data_Structure::GetHeapSize() { return Heap_Size; }
