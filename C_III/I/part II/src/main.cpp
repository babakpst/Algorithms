
/*
===============================================================================
Developer: Babak Poursartip

Course III:     Greedy algorithm
Assignment I:   Prim's algo
Data:           05/25/2020
===============================================================================
*/

// libraries
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// classes
#include "../include/module_1/graph.h"
#include "../include/module_1/message.h"

#define DEBUG 0

int main() {

  message m;
  int mod;
  m.pt("course III - assingnment I: Prim's algo: ");

  // reading the graph from the input file
  std::fstream inpGraph; // input file handler
  inpGraph.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {

    if (DEBUG) {
      inpGraph.open("input/test.txt", std::ios::in);
      mod = 0;
    } else {
      inpGraph.open("input/edges.txt", std::ios::in);
      mod = 1;
    }
  } catch (std::ifstream::failure &inputerr) { // catch for the input file
    m.pt(" Error while opening the input file!!! ");
    m.pt(" The error message is: ");
    m.pt(inputerr.what());
    throw inputerr;
  }

  int nV, nE; // no. of Vertices and Edges

  inpGraph >> nV >> nE;
  m.pti(" vertices: ", nV);
  m.pti(" edges: ", nE);
  graph G(nV);

  int u, v, w;
  for (int i = 0; i < nE; ++i) {
    inpGraph >> u >> v >> w;
    G.pushEdge(u - mod, v - mod, w, i);
  }

  G.findMST();
  G.print();

  m.pt("End of the code!");
  return 0;
}
