

// Developer: Babak Poursartip
//            The University of Texas at Austin

// Course II: Graph search, Shortest path, and Data Structure
// Assignment I: Strongly Connected Components

#include <iostream>
#include <forward_list>
#include <fstream>
#include <string>

/*
// Depth-First-Search for Topographical Sort
void DFS_Topo(){

}

// function to find the Topographical Sort
void TopoSort( int Graph, ){
CurrLabel = n;

}





void DFS_SCC(){


}
*/


int main(){

  std::cout << " Kosaraju algorithm for finding Strongly Connected Components " << std::endl;

  // Storing the Graph using the adjacency list. To this aim, we use a linked list ================

  // defining the linked list that holds the graph
  int const sizeOfGraph = 12;
  std::forward_list<int> Graph[sizeOfGraph];

  // opening the file containing the graph
  std::fstream fileGraph;
  //fileGraph.open("SCC.txt");
  fileGraph.open("SCC_Example.txt");

  int Node_I, Node_II;

  for (int i=0; i<sizeOfGraph; ++i){
   fileGraph >> Node_I >> Node_II ;
    Graph[Node_I-1].push_front(Node_II-1);
  }

  for (int i=0; i<sizeOfGraph; ++i){
    std::cout << " Vertix= " << i+1 << std::endl;
    for (std::forward_list<int>:: iterator itr=Graph[i].begin(); itr!=Graph[i].end(); ++itr){
      std::cout << *itr+1 << "  " ;
    };
    std::cout << std::endl;
  };

  return 0;
}