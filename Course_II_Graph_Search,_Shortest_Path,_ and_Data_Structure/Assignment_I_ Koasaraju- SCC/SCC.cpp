
/*
===================================================================================================
Developer: Babak Poursartip
           The University of Texas at Austin

Course II: Graph search, Shortest path, and Data Structure
Assignment I: Strongly Connected Components
===================================================================================================
*/

#include <iostream>
#include <forward_list>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

// Depth-First-Search for Topographical Sort ======================================================
void DFS_Topo(std::forward_list<int> *&Graph_rev, std::vector<bool> &NodeExplored, int &v, std::stack<int> &finishingTime ){

NodeExplored[v] = true;
int node;
int node2=v;
  for (std::forward_list<int>::iterator itr = Graph_rev[node2].begin(); itr != Graph_rev[node2].end(); ++itr){
    node = *itr;
    if (NodeExplored[node] == false) DFS_Topo(Graph_rev, NodeExplored, node, finishingTime);
  }
  finishingTime.push(v);
}


// function to find the Topographical Sort ========================================================
void TopoSort(std::forward_list<int> *&Graph_rev, std::vector<bool> &NodeExplored, 
              std::stack<int> &finishingTime, int const n){
//int CurrLabel = n;

for (int i=0; i < n; ++i){
  if (NodeExplored[i] == false) 
    DFS_Topo(Graph_rev, NodeExplored, i, finishingTime);
};
}


// ================================================================================================
void DFS_SCC(std::forward_list<int> *&Graph, std::vector<bool> &NodeExplored, int const v, 
             std::vector<int> &scc, int &numSCC){

NodeExplored[v] = true;
scc[v] = numSCC;
int node;

  for (std::forward_list<int>::iterator itr = Graph[v].begin(); itr!=Graph[v].end(); ++itr ){
    node = * itr;
    if (NodeExplored[node] == false) DFS_SCC( Graph, NodeExplored, node, scc, numSCC);
  };

}


// main Kosaraju algorithm ========================================================================
void SCC_Kosaraju(std::forward_list<int> *&Graph, std::forward_list<int> *&Graph_rev, int const n,
                  std::vector<int> &scc){

std::vector<bool> NodeExplored(n);
std::stack<int> finishingTime; // We use a stack to store the node numbers based on finishing time

for (int i = 0; i <n; ++i) NodeExplored[i] = false;

// first pass of depth-first-search to compute the f(v)'s, the magical ordering ----
TopoSort(Graph_rev, NodeExplored, finishingTime, n);

/*
// Printing content of stack -- finishing time
    std::cout << " finishing time" << std::endl;
    while (!finishingTime.empty()) { 
        std::cout << ' ' << finishingTime.top(); 
        finishingTime.pop(); 
    } 
*/

// second pass of depth-first-search to find SCC in reverse topological order ----

// marking all the nodes as unexplored
for (int i = 0; i <n; ++i)
  NodeExplored[i] = false;

int numSCC = 0; 

while (finishingTime.empty() == false){
  int v = finishingTime.top();
  finishingTime.pop();
  if (NodeExplored[v] == false)  {
    numSCC = numSCC + 1;
    //std::cout << " node " << v << " numSCC " << numSCC << std::endl;
    DFS_SCC(Graph, NodeExplored, v, scc, numSCC);
  }
};

}


//=================================================================================================
int main(){

  std::cout << " Kosaraju algorithm for finding Strongly Connected Components (SCC)" << std::endl;

  // Storing the Graph using the adjacency list. To this aim, we use a linked list ================

  // defining the linked list that holds the graph

  //SCC.txt
  int const sizeOfGraph = 875714;   // no. of nodes in the graph
  int const sizeOfEdges = 5105043;   // no. of nodes in the graph

  //example
  //int const sizeOfGraph = 12;   // no. of nodes in the graph
  //int const sizeOfEdges = 15;   // no. of nodes in the graph

  //example3
  //int const sizeOfGraph = 9;   // no. of nodes in the graph
  //int const sizeOfEdges = 11;   // no. of nodes in the graph

  std::forward_list<int> *Graph = new std::forward_list<int>[sizeOfGraph]; // holds the original graph
  std::forward_list<int> *Graph_rev = new std::forward_list<int>[sizeOfGraph]; // holds the reverse of the graph

  // opening the file containing the graph
  std::fstream fileGraph;
  fileGraph.open("SCC.txt");
  //fileGraph.open("SCC_Example.txt");
  //fileGraph.open("SCC_Example2.txt");
  //fileGraph.open("SCC_Example3.txt");

  int Node_I, Node_II;

  // pushing each vertix in the list
  for (int i=0; i<sizeOfEdges; ++i){
    fileGraph >> Node_I >> Node_II ;
    Graph[Node_I-1].push_front(Node_II-1);
    Graph_rev[Node_II-1].push_front(Node_I-1);
  }
  /*
  // writing the graph on screen
  std::cout << " The graph :" << std::endl;
  for (int i=0; i<sizeOfGraph; ++i){
    std::cout << " Vertix= " << i << std::endl;
    for (std::forward_list<int>:: iterator itr=Graph[i].begin(); itr!=Graph[i].end(); ++itr){
      std::cout << *itr << "  " ;
    };
    std::cout << std::endl;
  };
  

  // writing the reverse of the graph on screen
  std::cout << " The reverse of a graph :" << std::endl;
  for (int i=0; i<sizeOfGraph; ++i){
    std::cout << " Vertix= " << i << std::endl;
    for (std::forward_list<int>:: iterator itr=Graph_rev[i].begin(); itr!=Graph_rev[i].end(); ++itr){
      std::cout << *itr << "  " ;
    };
    std::cout << std::endl;
  };
  */
  std::vector<int> scc(sizeOfGraph);
  std::vector<int> NumOfNodeSCC(sizeOfGraph);


  // finding the Strongly Connected Components
  SCC_Kosaraju(Graph, Graph_rev, sizeOfGraph, scc);

  for (std::vector<int> :: iterator itr = scc.begin(); itr != scc.end(); ++itr ){
    //std::cout << " node " << *itr -1<< std::endl;
    NumOfNodeSCC[*itr  - 1]= NumOfNodeSCC[*itr  - 1] +1; // counting number of nodes in each SCC
  };

  /*
  for (std::vector<int> :: iterator itr = NumOfNodeSCC.begin(); itr != NumOfNodeSCC.end(); ++itr ){
    std::cout << " num " << *itr << std::endl;
  };
  */

  std::sort(NumOfNodeSCC.begin(), NumOfNodeSCC.end());
  for (std::vector<int> :: reverse_iterator ritr=NumOfNodeSCC.rbegin(); ritr < NumOfNodeSCC.rbegin()+5; ++ritr){
    std::cout << " max number of nodes: " << *ritr << std::endl;  
  }
 
 return 0;
}
