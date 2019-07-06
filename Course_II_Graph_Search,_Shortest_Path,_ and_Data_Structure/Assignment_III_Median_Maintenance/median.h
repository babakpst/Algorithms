
// libraries
#include <iostream>
#include <fstream>
#include <iomanip>

// classes
#include "heap.h"
#include "minHeap.h"
#include "maxHeap.h"

#ifndef MEDIAN_H
#define MEDIAN_H

class median {

  // members
private:
  Heap_Data_Structure *right = new minHeap(int CapSize); // right (min) heap
  Heap_Data_Structure *left = new maxHeap(int CapSize);  // left (max) heap

  int Median;    // holds the median of the sequence in each iteration
  int newNumber; // holds the new number in the stream

public:
  int SumOfMedian; // holds the sum of the medians

  int SizeOfStream; // size of the stream of numbers

  std::string inputFileName; // holds the name of the input file

  // methods
private:
  void MedianMaintenance(Heap_Data_Structure &right, Heap_Data_Structure &left,
                         int newNumber);

  int sign_num(int RightHeapSize, int LeftHeapSize);
  int average(int a, int b);

public:
  median();
  median(std::string inputFileName, unsigned int SizeOfStream);
  ~median();

  int find_Sum_Of_Median();
};

#endif // !MEDIAN_H
