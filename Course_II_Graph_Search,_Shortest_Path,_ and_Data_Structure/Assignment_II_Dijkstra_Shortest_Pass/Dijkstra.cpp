
/*
===================================================================================================
Developer: Babak Poursartip
           The University of Texas at Austin

Course II: Graph search, Shortest path, and Data Structure
Assignment II: Dijkstra shortest path algorithm, without heap
===================================================================================================
*/

#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"

//=================================================================================================
int main(){

  std::cout << "\n Dijkstra shortest path algorithm for an undirected weighted graph \n";

  // input ========================================================================================
  std::string FileName;  // the name of the input file
  FileName = "Dijkstra_Example.txt";
  int numV = 9; // no. of vertices in the graph.

  //FileName = "dijkstraData.txt";
  //int numVertices = 200; // no. of vertices in the graph

  // reading the graph ============================================================================
  Graph Graph(numV, FileName);
  
  Graph.readGraph();
  Graph.printGraph();
  
  // Dijkstra algo, finding the shortest path =====================================================


 
  std::cout << "\n End of the code! \n";
  return 0;
}
