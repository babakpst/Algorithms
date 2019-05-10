
/*
Babak Poursartip
05/07/2019

Assignment II, course II

The graph class

*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>

class Graph{

private:

int numVertices;
int numEdges;

std::string FileName;

struct Edge{
  int src, dest, weight;
  Edge();
  Edge(int src, int dest, int weight);
};

std::list <std::pair<int, int>> *edges;

public:

Graph();
Graph(int numVertices, std::string FileName);

void readGraph();
void printGraph();

void addEdge(int src, int dest, int weight);

};

#endif