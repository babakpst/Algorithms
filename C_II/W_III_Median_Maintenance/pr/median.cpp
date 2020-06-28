
#include "median.h"
#include "minHeap.h"
#include "maxHeap.h"

// constructor =================================================================
median::median() : SizeOfStream(0), inputFileName("") {
  std::cout << " \n Finding the median of the sequence using median "
               "maintenance algorithm based on heap data structure. \n \n";
}

median::median(int SizeOfStream, std::string inputFileName)
    : SumOfMedian(0), SizeOfStream(SizeOfStream), inputFileName(inputFileName) {
  std::cout << " \n Finding the median of the sequence using median "
               "maintenance algorithm based on heap data structure. \n \n";
  right = new minHeap(SizeOfStream);
  left = new maxHeap(SizeOfStream);
}

median::~median() {
  std::cout << " Killing objects and shutting down the code: \n";
  delete left;
  delete right;
}

// median initiation ===========================================================
int median::find_Sum_Of_Median() {

  int temp; // temp var to read the new number from the string

  // opening the input file
  std::ifstream inputStream(inputFileName);

  // loop of the stream of numbers
  for (int i = 0; i < SizeOfStream; i++) {
    // std::cout << " reading sequence no.: " << std::setw(5) << i
    //          << " out of: " << std::setw(6) << SizeOfStream << "\n";
    inputStream >> temp;
    Median = MedianMaintenance(temp);

    std::cout << " The meidan after adding " << std::setw(2) << i
              << "th term: " << std::setw(6) << temp << " is: " << Median
              << "\n";
    SumOfMedian += Median;
    // left->PrintHeap();
    // right->PrintHeap();
  };
  return SumOfMedian;
}

// compares the size of two heaps  =============================================
// it returens:
// 0 if two heaps have the same size
// -1 if the left heap contains more keys than the right key
//  1 if the left heap contains more keys than the right key
int median::sign_num(int LeftHeapSize, int RightHeapSize) {
  if (RightHeapSize == LeftHeapSize)
    return 0;
  return LeftHeapSize < RightHeapSize ? -1 : 1;
}

// finding the median by averaging the two mid number for the case that the
// number of keys are even
// int median::average(int a, int b) { return (a + b) / 2; }
int median::average(int a, int b) { return a; }

// Median Maintenance algorithm ================================================
int median::MedianMaintenance(int newNumber) {
  // this function returns the median of a sequence using the median
  // maintenance
  // mehtod, which is based on the heap data struture

  // First, we check whether the heaps are balanced. We count the number of
  // keys
  // in each heap and compare them together. This check assures that the
  // difference between the number of keys in the two heap in not more than 1
  int sig = sign_num(left->GetHeapSize(), right->GetHeapSize());

  switch (sig) {

  case -1: // if the right heap contains more keys than the left heap
    if (newNumber < Median) {
      // The new number needs to be added to the left heap, and the two heap
      // would have the same number of keys at the end of this step.
      left->InsertKey(newNumber);
    } else {
      // The min key in the right heap (min heap) should be transferred to the
      // left heap (max heap), first, and the new key should be added to the
      // right heap
      left->InsertKey(right->extract()); // removing the min from the righ heap
      right->InsertKey(newNumber); // inserting the new number in the left heap
    }
    // Both heaps have the same number of keys, thus the median is the average
    // the top keys in the two heaps
    Median = average(left->get(), right->get());
    break;

  case 0: // if the two heaps have equal number of keys
    if (newNumber < Median) {
      // the new number should be added to the left (max) heap and that new
      // number is indeed the median
      left->InsertKey(newNumber);
      Median = left->get();
    } else {
      // the new number should be added the right (min) heap and that new number
      // is indeed the median
      right->InsertKey(newNumber);
      Median = right->get();
    }
    break;

  case 1: // if the left heap contains more keys than the right heap
    if (newNumber < Median) {
      // the new number should fit in the left heap then, so, we need to extract
      // the min from the left heap and insert it in the right heap, first, and
      // then insert the new key in the left heap
      right->InsertKey(left->extract());
      left->InsertKey(newNumber);
    } else {
      // add the new number to the right heap
      right->InsertKey(newNumber);
    }
    // Both heaps have the same number of keys, thus the median is the average
    // the top keys in the two heaps
    Median = average(left->get(), right->get());
    break;

  default:
    std::cout << "something is wrong, check the median class.\n";
    break;
  }
  return Median;
}
