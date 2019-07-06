
#include "median.h"

// constructor =================================================================
// median::median() : SizeOfStream(0), inputStream("") {

median::median() {
  std::cout << " \n Finding the median of the sequence using median "
               "maintenance algorithm based on heap data structure. \n \n";
}

median::median(std::string inputFileName, unsigned int SizeOfStream)
    : inputFileName(inputFileName), SizeOfStream(SizeOfStream) {
  std::cout << " \n Finding the median of the sequence using median "
               "maintenance algorithm based on heap data structure. \n \n";
}

// median initiation ===========================================================
int median::find_Sum_Of_Median() {

  int temp;   // temp var to read the new number from the string
  int Median; // holds the median of the sequence in each iteration

  // opening the input file
  std::ifstream inputStream(inputFileName);

  // loop of the stream of numbers
  for (unsigned int i = 0; i < SizeOfStream; i++) {
    std::cout << " reading sequence no.: " << std::setw(5) << i
              << " out of: " << std::setw(6) << SizeOfStream << "\n";
    inputStream >> temp;
    Median = MedianMaintenance(temp);

    std::cout << " The meidan after adding " << std::setw(2) << i
              << "th term: " << std::setw(6) << temp << " is: " << Median
              << "\n";
    SumOfMedian += Median;
  };
  return SumOfMedian;
}

// Median Maintenance algorithm ================================================
int median::MedianMaintenance(int newNumber) {
  int Median = 5;
  return Median;
}