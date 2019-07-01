#include "median.h"

median::median() {
  std::cout << " \n Finding the median of the sequence using median "
               "maintenance algorithm based on heap data structure. \n \n"
}

int median::find_Sum_Of_Median(std::ifstream inputStream)
    : inputStream = inputStream {

  // loop of the stream of numbers
  for (unsigned int i = 0; i < SizeOfStream; i++) {
    inputStream >> temp;
    Median = MedianMaintenance(temp);
    // Median = 5;
    std::cout << " The meidan after adding " << std::setw(2) << i
              << "th term: " << std::setw(6) << temp << " is: " << Median
              << "\n";
    SumOfMedian += Median;
  };
}

void median::MedianMaintenance() {}