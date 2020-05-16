
#include "minHeap.h"

// constructor =================================================================
minHeap::minHeap(int Capacity) : Heap_Data_Structure(Capacity) {
  std::cout << " constructing the left (min) heap \n";
}

// returns true if var1 is smaller than var2 ===================================
bool minHeap::compare(int var1, int var2) { return (var1 < var2); }