
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
#include <iomanip>

// objects

int main() {

  std::cout << " \n  --  Median maintenance -- \n";

  unsigned int SizeOfStream = 20; // size of the stream of numbers
  std::ifstream inputStream;      // input file name
  inputStream.open("example.txt");

  int SumOfMedian = 0; // holds the sum of the medians

  // loop of the stream of numbers
  for (unsigned int i = 0; i < SizeOfStream; i++) {
    inputStream >> temp;
    // Median = MedianMaintenance(temp);
    Median = 5;
    std::cout << " The meidan after adding " << std::setw(2) << i
              << "th term: " << std::setw(6) << temp << " is: " << Median
              << "\n";
    SumOfMedian += Median;
  };

  std::cout << " The answer is: " << SumOfMedian % 10000 << "\n";
  std::cout << " \n End of the code! \n";
  return 0;
}