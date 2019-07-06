
// libraries
#include <iostream>
#include <fstream>
#include <iomanip>

// classes
#include "heap.h"

#ifndef MEDIAN_H
#define MEDIAN_H

class median {

  // members
private:
  Heap_Data_Structure *right;
  Heap_Data_Structure *left;

public:
  int SumOfMedian;           // holds the sum of the medians
  int newNumber;             // holds the new number in the stream
  unsigned int SizeOfStream; // size of the stream of numbers

  std::string inputFileName; // holds the name of the input file

  // methods
private:
  int MedianMaintenance(int newNumber);

public:
  median();
  median(std::string inputFileName, unsigned int SizeOfStream);

  int find_Sum_Of_Median();
};

#endif // !MEDIAN_H
