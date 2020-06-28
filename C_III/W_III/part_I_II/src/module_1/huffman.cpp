
#include "../../include/module_1/huffman.h"

huffman::huffman() { m.pt(" input received."); }
huffman::huffman(const int nSymbols) : nSymbols{nSymbols} {

  m.pt(" input received.");
}

// =============================================================================
void huffman::pushSymbol(const int u, const int v, const int w) {
  alphabet.insert(
      std::pair<int, std::pair<int, int>>(u, std::pair<int, int>(v, w)));
}

// =============================================================================
void huffman::print() {
  m.pt("Here are the weights:");
  for (auto it : alphabet)
    printf("weight %d - (min %d : max %d) \n", it.first, it.second.first,
           it.second.second);
}
// =============================================================================
void huffman::ans() {
  m.pti("longest codeword is:  ", alphabet.begin()->second.second);
  m.pti("shortest codeword is: ", alphabet.begin()->second.first);
}

// =============================================================================
void huffman::largestCodeWord() {

  m.pt("wokring on the longest word ...");
  int sum;
  int mindepth, maxdepth;
  for (int n = 0; n < nSymbols - 1; ++n) {
    sum = alphabet.begin()->first;
    mindepth = alphabet.begin()->second.first;
    maxdepth = alphabet.begin()->second.second;
    alphabet.erase(alphabet.begin());
    sum += alphabet.begin()->first;
    mindepth = std::min(mindepth, alphabet.begin()->second.first);
    maxdepth = std::max(maxdepth, alphabet.begin()->second.second);
    ++maxdepth;
    ++mindepth;
    if (DEBUG)
      printf(" sum: %d, mindepth: %d , maxdepth: %d \n", sum, mindepth,
             maxdepth);
    alphabet.erase(alphabet.begin());
    alphabet.insert(std::pair<int, std::pair<int, int>>(
        sum, std::pair<int, int>(mindepth, maxdepth)));
  }
  if (DEBUG)
    print();
}