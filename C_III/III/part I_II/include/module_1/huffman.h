
/*
===============================================================================
Developer: Babak Poursartip
Data:      06/12/2020
class:     Huffman code
===============================================================================
*/

// libraries
#include <algorithm> // std::for_each
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// classes
#include "../../include/module_1/message.h"

#ifndef HUFFMAN_H
#define HUFFMAN_H

class huffman {

  // members
private:
  message m;
  int nSymbols; // no. of vertices in the graph

  std::multimap<int, std::pair<int, int>> alphabet;

public:
  // methods
private:
  huffman();

public:
  huffman(const int);

  // pushes a vertix and its corresponding weighted edge
  void pushSymbol(const int u, const int v, const int w);
  void print();
  void largestCodeWord();
  void ans();
};

#endif // ! HUFFMAN_H
