

#ifndef MEDIAN_H
#define MEDIAN_H

// libraries
#include <iostream>
#include <fstream>

// classes

class median {

  // members
private:
  Heap *right;
  Heap *left;

public:
  int SumOfMedian;

  // methods
private:
  void MedianMaintenance();

public:
  median();
  int find_Sum_Of_Median(std::ifstream inputStream);
}

#endif // !MEDIAN_H
