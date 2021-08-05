
#include "../../include/module_1/order.h"

order::order() { m.pt(" input received."); }
order::order(std::vector<int> &input, const int &max) : input{input}, max{max} {
  m.pt(" input received.");
}

//==============================================================================
// greedy algo to find the schedule in decreasing order of the difference
void order::difference() {

  std::multimap<float, int> order;
  int index;
  float val;
  const float coe = 0.4 / max;

  for (std::vector<int>::iterator it = input.begin(); it != input.end();
       it += 2) {
    index = (it - input.begin()) / 2;
    val = *it - *(it + 1) + coe * *it;
    // printf("job %d:  %d  %d %f \n", index, *it, *(it + 1), val);
    order.insert(std::make_pair(val, index));
  }
  m.pt("");

  int completion = 0; // completion time of the job j
  long sum = 0;       // sum of the weighted completion time
  for (std::multimap<float, int>::reverse_iterator it = order.rbegin();
       it != order.rend(); ++it) {
    completion += input[2 * it->second + 1];
    sum += completion * input[2 * it->second];

    // printf("order:  %12.6f  %4d  %4d %ld \n", it->first, it->second,
    // completion, sum);
  }

  // Q1 answer 69119377652
  ans_diff = sum;
  printf(" the answer is:  %ld \n", sum);
}

//==============================================================================
// greedy algo to find the schedule in decreasing order of the difference
void order::division() {

  std::multimap<float, int> order;
  int index;
  float val;
  float var1, var2;
  for (std::vector<int>::iterator it = input.begin(); it != input.end();
       it += 2) {
    index = (it - input.begin()) / 2;

    var1 = *it, var2 = *(it + 1);
    // val = ((int)(*it)) / ((int)(*(it + 1)));
    val = var1 / var2;

    // printf("job %6d:  %8d  %8d %12.8f \n", index, *it, *(it + 1), val);
    order.insert(std::make_pair(val, index));
  }
  m.pt("");

  int completion = 0; // completion time of the job j
  long sum = 0;       // sum of the weighted completion time
  for (std::multimap<float, int>::reverse_iterator it = order.rbegin();
       it != order.rend(); ++it) {

    completion += input[2 * it->second + 1];
    sum += completion * input[2 * it->second];

    // printf("order:  %12.6f  %4d  %4d %ld \n", it->first, it->second,
    // completion,           sum);
  }

  // Q2 answer
  ans_div = sum;
  printf(" the answer is:  %ld \n", sum);
}