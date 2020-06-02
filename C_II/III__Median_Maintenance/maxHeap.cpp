
#include "maxHeap.h"

// constructor =================================================================
maxHeap::maxHeap(int Capacity) : Heap_Data_Structure(Capacity) {
  std::cout << " constructing the right (max) heap \n";
}

// returns true if var1 is greater than var2 ===================================
bool maxHeap::compare(int var1, int var2) { return (var1 > var2); }
