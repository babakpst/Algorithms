
// libraries
#include <iostream>
#include <fstream>
#include <iomanip>

// classes
#include "heap.h"

#ifndef MEDIAN_H
#define MEDIAN_H

class Median {

  // members
private:
  Heap_Data_Structure *right;
  Heap_Data_Structure *left;

public:
  int SumOfMedian;           // holds the sum of the medians
  int newNumber;             // holds the new number in the stream
  unsigned int SizeOfStream; // size of the stream of numbers

  std::ifstream inputStream; // input file name

  // methods
private:
  int MedianMaintenance(int newNumber);

public:
  median();
  median(std::ifstream inputStream, unsigned int SizeOfStream);

  int find_Sum_Of_Median();
};

#endif // !MEDIAN_H
