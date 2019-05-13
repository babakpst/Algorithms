/*

Babak Poursartip
05/8/2019

Assignment II, course II

*/

#include "Graph.h"

//=================================================================================================
Graph::Graph():numVertices(0), numEdges(0), FileName(" "){
  std::cout << "\n Creating graph with default values ... \n";
}

//=================================================================================================
Graph::Graph(int numVertices, std::string FileName):numVertices{numVertices}, FileName{FileName}{
  std::cout << "\n Creating the graph object ... \n";
  edges = new std::list <std::pair<int, int>>[numVertices];
}

//=================================================================================================
void Graph::readGraph(){
  std::cout << "\n Reading graph from file: " << FileName << "\n";

  // open the input file
  std::cout << " Opening the input file ... \n";
  std::ifstream inputFile(FileName);
  
  std::string line;
  std::string temp;

  int count = 0; // counts number of vertices in the file
    while (std::getline(inputFile, line)){
      count++;
      std:: stringstream iss(line);

      int src;    // the vertix no (from)- source
      int dest;   // the vertix no (to)- destination
      int weight; // the weight of the edge

      std::getline(iss, temp, ' ');
      src = std::stoi(temp);

      std::cout << " ---reading vertix: " << src << "\n";

        while (std::getline(iss, temp,',')){
          dest = std::stoi(temp);
          std::getline(iss, temp, ' ');
          weight = std::stoi(temp);
          std::cout << src << " " << dest << " " << weight << "\n";
          if (src > dest) addEdge(src, dest, weight);
        }
    }

  inputFile.close();
  std::cout << " read the graph from the input file, successfully! \n";
}

//=================================================================================================
void Graph::addEdge(int src, int dest, int weight){
  edges[src].push_back(std::make_pair(dest, weight));
  edges[dest].push_back(std::make_pair(src, weight));
}

//=================================================================================================
void Graph::printGraph(){
  for (int i=0; i<numVertices; ++i){
    std::cout << " vertix: " << i << "\n";
      for (std::list<std::pair<int,int>>:: iterator itr=edges[i].begin(); itr!=edges[i].end(); ++itr){
        std::cout << " src: " << i << " dest: " << (*itr).first << " weight: " << (*itr).second << "\n";
    }
}
}
