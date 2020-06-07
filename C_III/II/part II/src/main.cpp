
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
#include "../include/module_1/cluster.h"
#include "../include/module_1/message.h"

int main() {

  message m;
  int nCluster = 4; // input

  m.pt("course III - assingnment II: cluster ");

  // reading the graph from the input file
  std::fstream inpGraph; // input file handler
  inpGraph.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {

    if (DEBUG) {
      inpGraph.open("input/clustering_big_test.txt", std::ios::in);
    } else {
      inpGraph.open("input/clustering_big.txt", std::ios::in);
    }
  } catch (std::ifstream::failure &inputerr) { // catch for the input file
    m.pt(" Error while opening the input file!!! ");
    m.pt(" The error message is: ");
    m.pt(inputerr.what());
    throw inputerr;
  }

  int nV;    // no. of Vertices
  int nbits; // no. of bits of each vertix

  inpGraph >> nV >> nbits;
  m.pti(" vertices: ", nV);
  m.pti(" nbits: ", nbits);

  cluster cl(nV, nCluster);

  for (int i = 0; i < nV; ++i) {
    std::vector<int> vertix;
    int w;
    for (int j = 0; j < nbits; ++j) {
      inpGraph >> w;
      vertix.push_back(w);
    }
    cl.graph.push_back(vertix);
  }

  m.pt("here is the input:");
  if (DEBUG)
    cl.printInput();

  int index1, index2;
  int distance;
  std::vector<int>::iterator vit1, vit2;
  for (std::vector<std::vector<int>>::iterator it1 = cl.graph.begin();
       it1 != cl.graph.end(); ++it1) {
    index1 = it1 - cl.graph.begin();
    printf(" %3d\n", index1);
    for (std::vector<std::vector<int>>::iterator it2 = it1 + 1;
         it2 != cl.graph.end(); ++it2) {
      vit1 = (*it1).begin();
      vit2 = (*it2).begin();
      index2 = it2 - cl.graph.begin();
      distance = 0;
      for (int i = 0; i < nbits; ++i) {
        distance += abs(*vit1 - *vit2);
        ++vit1;
        ++vit2;
      }
      // printf(" distance: %d \n", distance);
      cl.pushEdge(index1, index2, distance);
    }
  }

  if (DEBUG)
    cl.printGraph();

  m.pt("working on the cluster");
  cl.findClusters();
  m.pt("renumbering");
  cl.clusterRenumber();
  m.pt("distance");
  cl.findDist();
  m.pt("printing");
  cl.printCluster();

  m.pt("End of the code!");
  return 0;
}
