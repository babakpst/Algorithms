/*
a class that holds a weighted, undirected graph using adjacency method.
*/

// libraries
#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

// classes
#include "../../include/module_1/message.h"

#ifndef GRAPH_H
#define GRAPH_H

class graph {

  // members
private:
  message m;
  int nVertices; // no. of vertices in the graph
  long sum = 0;  // cost of minimum spanning
  std::vector<std::list<std::pair<int, int>>> inpGraph;

  std::unordered_map<int, int> outMST;
  std::unordered_map<int, int> parent;
  std::unordered_map<int, int> key;

public:
  // methods
private:
  graph();

public:
  graph(const int);

  // pushes a vertix and its corresponding weighted edge
  void pushEdge(const int u, const int v, const int w, const int i);

  // find the Minimum Spanning Tree
  void findMST();

  // print the results
  void print();
};

#endif // !GRAPH_H
