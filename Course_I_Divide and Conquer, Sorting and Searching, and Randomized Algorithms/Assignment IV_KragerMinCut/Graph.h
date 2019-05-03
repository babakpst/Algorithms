
/*

Developer: Babak Poursartip
Assignment 4 of course I

*/

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


class Graph{

private:
  int numV; // number of vertices
  int numE; // number of edges

  struct Edge{
    int src, dest;
    Edge();
    Edge(int src, int dest);
    ~Edge();
  };

  std::vector<Edge> edges;


public:

  Graph();
  Graph(int numV);
  Graph(int numV, int numE);
  ~Graph();

  int getNumV();
  int getNumE();
  
  void read();
  void addEdge(int src, int dest);
  void printGraph();
  
Edge getEdge(int index);

};

#endif