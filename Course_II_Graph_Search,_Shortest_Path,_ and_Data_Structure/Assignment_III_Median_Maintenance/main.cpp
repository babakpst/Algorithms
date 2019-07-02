
/*
===================================================================================================
Developer: Babak Poursartip
           The University of Texas at Austin

Course II: Graph search, Shortest path, and Data Structure
Assignment III: Median maintenance
===================================================================================================
*/

// libraries
#include <iostream>
#include <fstream>
#include <string>

// objects
#include "median.h"

int main() {

  std::cout << " \n  --  Median maintenance -- \n";

  unsigned int SizeOfStream = 20; // size of the stream of numbers
  std::ifstream inputStream;      // input file name
  inputStream.open("example.txt");

  // holds the sum of the medians
  Median Find_the_Median(std::ifstream inputStream, unsigned int SizeOfStream);

  int SumOfMedian = Find_the_Median.find_Sum_Of_Median();

  std::cout << " The sum of all medias is: " << SumOfMedian << ".\n";
  std::cout << " The answer is: " << SumOfMedian % 10000 << ".\n";
  std::cout << " \n End of the code! \n";
  return 0;
}