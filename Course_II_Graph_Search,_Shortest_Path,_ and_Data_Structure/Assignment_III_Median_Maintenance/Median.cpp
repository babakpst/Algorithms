
#include "median.h"

// constructor =================================================================
// median::median() : SizeOfStream(0), inputStream("") {
Median::Median() {
  std::cout << " \n Finding the median of the sequence using median "
               "maintenance algorithm based on heap data structure. \n \n";
}

Median::Median(std::ifstream inputStream, int SizeOfStream)
    : inputStream(inputStream), SizeOfStream(SizeOfStream) {
  std::cout << " \n Finding the median of the sequence using median "
               "maintenance algorithm based on heap data structure. \n \n";
}

// median initiation ===========================================================
int median::find_Sum_Of_Median() {

  int temp;   // temp var to read the new number from the string
  int Median; // holds the median of the sequence in each iteration

  // loop of the stream of numbers
  for (unsigned int i = 0; i < SizeOfStream; i++) {
    inputStream >> temp;

    Median = MedianMaintenance(temp);

    std::cout << " The meidan after adding " << std::setw(2) << i
              << "th term: " << std::setw(6) << temp << " is: " << Median
              << "\n";
    SumOfMedian += Median;
    return SumOfMedian;
  };
}

// Median Maintenance algorithm ================================================
int median::MedianMaintenance(int newNumber) {
  int Median = 5;
  return Median;
}