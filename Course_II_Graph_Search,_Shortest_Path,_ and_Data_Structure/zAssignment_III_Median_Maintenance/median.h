
// libraries
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

// classes
#include "heap.h"
#include "minHeap.h"
#include "maxHeap.h"

#ifndef MEDIAN_H
#define MEDIAN_H

class median {

  // members
private:
  Heap_Data_Structure *right; // right (min) heap
  Heap_Data_Structure *left;  // left (max) heap

  int Median;    // holds the median of the sequence in each iteration
  int newNumber; // holds the new number in the stream

public:
  int SumOfMedian; // holds the sum of the medians

  int SizeOfStream; // size of the stream of numbers

  std::string inputFileName; // holds the name of the input file

  // methods
private:
  int MedianMaintenance(int newNumber);
  int sign_num(int RightHeapSize, int LeftHeapSize);
  int average(int a, int b);

public:
  median();
  median(int SizeOfStream, std::string inputFileName);
  ~median();

  int find_Sum_Of_Median();
};

#endif // !MEDIAN_H
