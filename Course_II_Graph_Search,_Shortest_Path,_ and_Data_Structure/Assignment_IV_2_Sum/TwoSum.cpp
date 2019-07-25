
#include "TwoSum.h"

// constructor
TwoSum::TwoSum(int sizeOfStream, int target, std::string inputFileName)
    : sizeOfStream{sizeOfStream}, target{target}, inputFileName{inputFileName} {
  std::cout << " Initiating the 2-Sum class ... \n";
  std::cout << " size of stream: " << sizeOfStream << ", target: " << target
            << "\n";
  // numbers.reserve(sizeOfStream);
}

// ======
void TwoSum::readData() {
  std::cout << " reading numbers from the file ... \n";
  std::ifstream inputFile(inputFileName);
  int temp;
  for (int i = 0; i < sizeOfStream; ++i) {
    inputFile >> temp;
    numbers.push_back(temp);
    std::cout << " reading: " << i << " " << numbers[i] << "\n";
  }
}

// ===
void TwoSum::brute_force_2_sum() {

  std::cout << " Evaluating 2-sum using brute force method: \n";

  for (std::vector<int>::iterator it1 = numbers.begin(); it1 != numbers.end();
       ++it1) {
    for (std::vector<int>::iterator it2 = it1 + 1; it2 != numbers.end();
         ++it2) {
      if ((*it1 + *it2) == target) {
        std::cout << std::distance(numbers.begin(), it1) << ":" << *it1 << "--"
                  << std::distance(numbers.begin(), it2) << ":" << *it2 << "\n";
      }
    }
  }
}

// ===
void TwoSum::hash_table_2_sum() {
  std::cout << " Evaluating 2-sum using hash table ... \n";
}

void TwoSum::list_2_sum() {
  std::unordered_set<int> set;
  for (int i = 0; i < sizeOfStream; i++) {
    int temp = target - numbers[i];

    if (set.find(temp) != set.end())
      std::cout << "Pair with given target " << target << " is (" << numbers[i]
                << ", " << temp << ")\n";

    set.insert(numbers[i]);
  }
}
