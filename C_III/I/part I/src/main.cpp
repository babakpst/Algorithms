
/*
===============================================================================
Developer: Babak Poursartip

Course III:     Greedy algorithm
Assignment I:   Scheduling jobs
Data:           05/23/2020
===============================================================================
*/

// libraries
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

// classes
#include "../include/module_1/message.h"
#include "../include/module_1/order.h"

int main() {

  message m;
  m.pt("course III - assingnment I: scheduling jobs ");

  std::vector<int> list; // vector to hold jobs and weights
  unsigned int njobs;    // total number of jobs in the file
  std::fstream jobs;     // input file handler
  jobs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    jobs.open("input/jobs.txt", std::ios::in);
    // jobs.open("input/test.txt", std::ios::in);
  } catch (std::ifstream::failure &inputerr) { // catch for the input file
    m.pt(" Error while opening the input file!!! ");
    m.pt(" The error message is: ");
    m.pt(inputerr.what());
    throw inputerr;
  }

  jobs >> njobs;
  m.pti("total number of jobs: ", njobs);

  list.resize(njobs * 2);
  int max_weight = 0;
  for (std::vector<int>::iterator it = list.begin(); it != list.end();
       it += 2) {
    jobs >> *it >> *(it + 1);
    if (*it > max_weight)
      max_weight = *it;
  }
  jobs.close();

  m.pt(" launch the difference algo: ");
  order diff(list, max_weight);
  diff.difference();
  diff.division();

  m.pt("End of the code!");
  return 0;
}
