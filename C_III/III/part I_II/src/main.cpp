
/*
===============================================================================
Developer: Babak Poursartip

Course III:     Greedy algorithm
Assignment III:   Huffman code
Data:           06/12/2020
===============================================================================
*/

// libraries
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// classes
#include "../include/module_1/huffman.h"
#include "../include/module_1/message.h"

int main() {

  message m;

  m.pt("course III - assingnment III: huffman ");

  // reading the graph from the input file
  std::fstream inp; // input file handler
  inp.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    if (DEBUG) {
      inp.open("input/test.txt", std::ios::in);
    } else {
      inp.open("input/huffman.txt", std::ios::in);
    }
  } catch (std::ifstream::failure &inputerr) { // catch for the input file
    m.pt(" Error while opening the input file!!! ");
    m.pt(" The error message is: ");
    m.pt(inputerr.what());
    throw inputerr;
  }

  int nSymbols; // no. of symbols
  inp >> nSymbols;
  m.pti("no. symbols: ", nSymbols);

  huffman hf(nSymbols);
  int w; // weight of each word
  for (int i = 0; i < nSymbols; ++i) {
    inp >> w;
    hf.pushSymbol(w, 0, 0);
  }

  m.pt("here is the input:");
  if (DEBUG)
    hf.print();

  hf.largestCodeWord();
  hf.ans();

  m.pt("End of the code!");
  return 0;
}
