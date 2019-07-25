
// libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

// classes

#ifndef TWOSUM_H
#define TWOSUM_H

class TwoSum {

  // members
private:
public:
  int sizeOfStream;
  int target;
  std::string inputFileName;

  std::vector<int> numbers;
  // methods
private:
public:
  TwoSum(int, int, std::string);
  void readData();
  void brute_force_2_sum();
  void hash_table_2_sum();
  void list_2_sum();
};

#endif // !TWOSUM_H
