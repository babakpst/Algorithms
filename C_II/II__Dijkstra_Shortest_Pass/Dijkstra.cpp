
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
  /*
  FileName = "Dijkstra_Example.txt";
  int numV = 9; // no. of vertices in the graph.
  int source = 1; // the source vertix to find the shortest path
  */
  
  /*
  FileName = "dijkstraDataII.txt";
  int numV = 200; // no. of vertices in the graph
  int source = 1;
  */

  ///*
  FileName = "dijkstraData.txt";
  int numV = 200; // no. of vertices in the graph
  int source = 1;
  //*/

  // reading the graph ============================================================================
  Graph Graph(numV, FileName);
  
  Graph.readGraph();
  Graph.printGraph();
  
  // Dijkstra algo, finding the shortest path =====================================================
  
  Graph.findShortestPath(source);

  Graph.printShortestDistance();

  std::cout << "\n End of the code! \n";
  return 0;
}
