/*

Babak Poursartip
05/8/2019

Assignment II, course II

*/

#include "Graph.h"

Graph::Graph():numVertices{0}, numEdges{0}, FileName{" "}{
  std::cout << "\n Creating graph with default values ... \n";
}

Graph::Graph(std::string FileName, int numVertices):FileName{FileName}, numVertices{numVertices}{
  std::cout << "\n Creating the graph object ... \n";
}


void Graph::readGraph(){
  std::cout << "\n Reading graph from file: " << FileName << "\n";

  std::fstream inputFile(FileName);
  std:: string line;

  int count = 0; // counts number of vertices in the file
    while (std::getline(inputFile,line)){
      count++;
      std::istringstream iss(line);

      int src;  // the vertix no (from)- source
      int dest; // the vertix no (to)- destination
      int weight; // the weight of the edge
      iss >> src;
      std::cout << " reading vertix: " << src << "\n";
        while (iss >> dest){
          iss >> weight;
          std::cout << " edge: " << dest << " weight: " << weight << "\n";
          if (src > dest) addEdge(src, dest, weight);
        }
    }
  inputFile.close();
  std::cout << " read the graph from the input file, successfully! \n";
}

void Graph::addEdge(int src, int dest, int weight){

}

void Graph::printGraph(){
  int count = 0;
  //for (std::)
}
