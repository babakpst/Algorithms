
/*
===============================================================================
Developer: Babak Poursartip
           The University of Texas at Austin

Course II:     Graph search, Shortest path, and Data Structure
Assignment IV: The 2-Sum problem
Data:           07/21/2019
===============================================================================
*/

// libraries
#include <iostream>
#include <string>

// classes
#include "../include/module_1/TwoSum.h"

int main() {

  std::cout << " \n  --  2-Sum problem -- \n";

  // int sizeOfStream = 20; // size of the stream of numbers
  // long long target = 15; // target sum
  // std::string inputFileName = "input/example.txt"; // holds the input file
  // name

  int sizeOfStream = 1000000;                   // size of the stream of numbers
  long long target = 7547817288ll;              // target sum
  std::string inputFileName = "input/2sum.txt"; // holds the input file name

  TwoSum Find_Two_Sum(sizeOfStream, target, inputFileName);
  Find_Two_Sum.readData();
  Find_Two_Sum.list_2_sum();
  // Find_Two_Sum.brute_force_2_sum();
  Find_Two_Sum.list_2_sum_total();

  std::cout << " \n End of the code! \n";
  return 0;
}