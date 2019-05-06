
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



//=================================================================================================
int main(){

  std::cout << "\n Dijkstra shortest path algorithm for an undirected weighted graph \n";

  // input ========================================================================================
  // reading the graph from the input file ========================================================
  std::string FileName;  // the name of the input file
  FileName = "Dijkstra_Example.txt";
  //FileName = "dijkstraData.txt";

  int numVertices = 200; // no. of vertices in the graph.

  std::fstream InputFile;
  InputFile.open(FileName);


 
  std::cout << "\n End of the code! \n";
  return 0;
}
