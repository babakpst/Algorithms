
#include "../../include/module_1/TwoSum.h"

// constructor
TwoSum::TwoSum(int sizeOfStream, long long target, std::string inputFileName)
    : sizeOfStream{sizeOfStream}, target{target}, inputFileName{inputFileName} {
  std::cout << " Initiating the 2-Sum class ... \n";
  std::cout << " size of stream: " << sizeOfStream << ", target: " << target
            << "\n";
  // numbers.reserve(sizeOfStream);
}

// ======
void TwoSum::readData() {
  std::cout << " reading numbers from the file ... \n";
  // opening the input file
  inputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    inputFile.open(inputFileName, std::ios::in);
  } catch (std::ifstream::failure
               &inputerr) { // here is the catch for opening the input file.
    std::cout << " Error while opening the input file. \n";
    std::cout << " Please make sure the input file is in the cpp folder.\n";
    std::cout << " The error message is: " << inputerr.what() << "\n";
  }

  long long temp;
  for (int i = 0; i < sizeOfStream; ++i) {
    inputFile >> temp;
    numbers.push_back(temp);
    // std::cout << " reading: " << i << " " << numbers[i] << "\n";
  }
  std::cout << " Done reading the data\n";

  std::cout << " sorting ... \n";
  std::sort(numbers.begin(), numbers.end());

  std::cout << "checking the repetition of the numbers ... \n";
  int numRepetition = 0;
  for (std::vector<long long>::iterator it = numbers.begin();
       it != numbers.end() - 1; ++it) {
    if (*it == *(it + 1)) {
      numRepetition++;
      std::cout << " repetition: " << numRepetition << " - " << *it << "\n";
    }
    // std::cout << " sorted: " << *it << "\n";
  }
  std::cout << " number of repetitions: " << numRepetition << "\n";
}

// ===
void TwoSum::brute_force_2_sum() {

  std::cout << " Evaluating 2-sum using brute force method: \n";
  int counter = 0;
  int NumOfPairs = 0;
  for (std::vector<long long>::iterator it1 = numbers.begin();
       it1 != numbers.end(); ++it1) {
    counter++;
    if (counter % 10000 == 0)
      std::cout << " item: " << counter++ << " - " << NumOfPairs << "\n";
    for (std::vector<long long>::iterator it2 = it1 + 1; it2 != numbers.end();
         ++it2) {
      if ((*it1 + *it2) == target) {
        NumOfPairs++;
        std::cout << std::distance(numbers.begin(), it1) << ":" << *it1 << "--"
                  << std::distance(numbers.begin(), it2) << ":" << *it2 << "\n";
      }
    }
  }
  std::cout << " Total number of pairs: " << NumOfPairs << "\n";
  std::cout << " End of brute-force search \n";
}

void TwoSum::list_2_sum() {

  std::cout << " Evaluating 2-sum using unordered set ... \n";
  int NumOfPairs = 0;
  std::unordered_set<long long> set;
  for (int i = 0; i < sizeOfStream; i++) {
    long long temp = target - numbers[i];
    // std::cout << temp << "\n";
    if (set.find(temp) != set.end()) {
      NumOfPairs++;
      std::cout << "Pair with given target " << target << " is (" << numbers[i]
                << ", " << temp << ")\n";
    }
    set.insert(numbers[i]);
  }
  std::cout << " Total number of pairs: " << NumOfPairs << "\n";
  std::cout << " End of the unsorted set \n";
}

// ====
void TwoSum::list_2_sum_total() {

  std::cout << " Calculating total number of targets in the set ... \n";
  int NumOfTargets = 0;
  std::unordered_set<long long> set;
  for (int i = 0; i < sizeOfStream; i++)
    set.insert(numbers[i]);
  for (long long targets = -10000; targets <= 10000; ++targets) {
    for (int i = 0; i < sizeOfStream; i++) {

      long long temp = targets - numbers[i];

      if (set.find(temp) != set.end()) {
        NumOfTargets++;
        std::cout << " For target: " << targets << " there is: " << temp << ", "
                  << numbers[i] << "\n";
        break;
      }
    }
  }
  std::cout << " Total number of targets: " << NumOfTargets << "\n";
  std::cout << " End of the unsorted set \n";
}