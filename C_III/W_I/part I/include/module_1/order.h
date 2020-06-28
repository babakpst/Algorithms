
// libraries
#include <iostream>
#include <map>
#include <string>
#include <vector>

// classes
#include "../../include/module_1/message.h"

#ifndef ORDER_H
#define ORDER_H

class order {

  // members
private:
  std::vector<int> input;
  int max;
  int ans_diff;
  int ans_div;
  message m;

public:
  // methods
private:
  order();

public:
  order(std::vector<int> &, const int &);
  void difference();
  void division();
};

#endif // !ORDER_H
