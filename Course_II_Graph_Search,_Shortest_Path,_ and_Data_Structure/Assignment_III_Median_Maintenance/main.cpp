
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
#include <string>

// objects
#include "median.h"

int main() {

  std::cout << " \n  --  Median maintenance -- \n";

  int SizeOfStream = 20;                     // size of the stream of numbers
  std::string inputFileName = "example.txt"; // holds the input file name

  // holds the sum of the medians
  median Find_the_Median(SizeOfStream, inputFileName);

  int SumOfMedian = Find_the_Median.find_Sum_Of_Median();

  std::cout << " The sum of all medias is: " << SumOfMedian << ".\n";
  std::cout << " The answer is: " << SumOfMedian % 10000 << ".\n";
  std::cout << " \n End of the code! \n";
  return 0;
}