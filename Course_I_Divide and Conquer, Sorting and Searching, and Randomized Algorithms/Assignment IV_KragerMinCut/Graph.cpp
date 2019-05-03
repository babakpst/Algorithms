
#include "Graph.h"


Graph::Graph():numV{1}, numE{0}{
  std::cout << " Creating graph, no initialization. \n";
}

Graph::Graph(int numV):numV{numV}, numE{0}{
  std::cout << " Creating the graph object, initialization with no of vertices ...\n";
}

Graph::Graph(int numV, int numE):numV{numV}, numE{numE}, edges(numE){
  std::cout << " Creating the graph object, full initialization ...\n";
}

Graph::Edge::Edge():src{0}, dest{0}{}
Graph::Edge::Edge(int src, int dest):src{src}, dest{dest}{}



int Graph::getNumV(){return numV;}
int Graph::getNumE(){return numE;}



void Graph::addEdge(int src, int dest){
  edges.push_back({src, dest});
  numE++;
}


void Graph::read(){

// Reading the Graph from the file ----------------------------------------------------------------
std::ifstream InputGraph("test.txt");
std::string line;

int counter=0; // counts vertices
while ( std::getline(InputGraph, line)){
  counter++;
  std::istringstream iss(line);
  
  int src, dest;
  iss >> src;
  std::cout << " Reading vertix: " << counter << "\n";
    while (iss >> dest){
        if (dest > src) {
          addEdge(src, dest);
          }
        }
  }

InputGraph.close(); 
std::cout << " total number of edges: " << numE << "\n";

}

void Graph::printGraph() 
{ 
  for (std::vector<Edge>::iterator itr=edges.begin(); itr!=edges.end(); ++itr){
    std::cout << itr->src << " -> " << itr->dest << '\n';
  }
} 


Graph::Edge Graph::getEdge(int index){return edges[index];}

Graph::~Graph(){}
Graph::Edge::~Edge(){}