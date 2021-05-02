// 2SAT
//https://www.geeksforgeeks.org/2-satisfiability-2-sat-problem/
// A or B == -A-> B and -B-> A


#include <iostream>
#include <forward_list>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <memory>

#define DEBUG 1

// Depth-First-Search for Topographical Sort ======================================================
void DFS_Topo(std::forward_list<int> *&Graph_rev, std::vector<bool> &NodeExplored, int &v, 
std::stack<int> &finishingTime)
{
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
              std::stack<int> &finishingTime, int const n)
{
  for (int i=0; i < n; ++i){
    if (NodeExplored[i] == false) 
      DFS_Topo(Graph_rev, NodeExplored, i, finishingTime);
  }
}


// ================================================================================================
void DFS_SCC(std::forward_list<int> *&Graph, std::vector<bool> &NodeExplored, int const v, 
             std::vector<int> &scc, int &numSCC)
{
  NodeExplored[v] = true;
  scc[v] = numSCC;
  int node;

    for (std::forward_list<int>::iterator itr = Graph[v].begin(); itr!=Graph[v].end(); ++itr)
    {
      node = * itr;
      if (NodeExplored[node] == false) DFS_SCC( Graph, NodeExplored, node, scc, numSCC);
    }
}

// main Kosaraju algorithm ========================================================================
void SCC_Kosaraju(std::forward_list<int> *&Graph, std::forward_list<int> *&Graph_rev, int const n,
                  std::vector<int> &scc)
{
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
    if (NodeExplored[v] == false)  
    {
      numSCC = numSCC + 1;
      //std::cout << " node " << v << " numSCC " << numSCC << std::endl;
      DFS_SCC(Graph, NodeExplored, v, scc, numSCC);
    }
  }
}

//=================================================================================================
//=================================================================================================
bool readFile(std::string fileName, std::vector<std::vector<int>> &Graph, std::vector<std::vector<int>> &Graph_rev)
{
  std::cout << " reading the file ... \n";
  std::fstream file;
  file.open(fileName);

  int nClause, Node_I, Node_II;
  int firstedge, secondedge;
  file >> nClause;
  int const sizeOfGraph = 2*nClause+1;   // no. of nodes in the graph
  int const sizeOfEdges = 2*nClause+1;   // no. of edges in the graph

  Graph.resize(sizeOfGraph); // holds the original graph
  Graph_rev.resize(sizeOfGraph); // holds the reverse of the graph

  // pushing each vertix in the list
  for (int i=0; i<nClause; ++i){
    if (DEBUG) std::cout << " reading vertix: " << i << std::endl;
    file >> Node_I >> Node_II;

		if(Node_I < 0)  
			Node_I = nClause + abs(Node_I);	
		
		if(Node_I > nClause) 
			firstedge = Node_I -nClause;
		else 
			firstedge = nClause + Node_I;

		if(Node_II < 0) 
			Node_II = nClause + abs(Node_II);

		if(Node_II > nClause)
			secondedge = Node_II -nClause;
		else
			secondedge = nClause + Node_II;

    if (DEBUG) std::cout << Node_I <<" " << Node_II << "  " << firstedge << " " << secondedge << std::endl;
    Graph[firstedge].push_back(Node_II);
    Graph[secondedge].push_back(Node_I);
    Graph_rev[Node_II].push_back(firstedge);
    Graph_rev[Node_I].push_back(secondedge);
  }

  std::cout << " reading finished successfully. \n";
  return true;
}


//=================================================================================================
//=================================================================================================
int main(){

  std::cout << " 2SAT problem" << std::endl;

  // Storing the Graph using the adjacency list. To this aim, we use a linked list ================

  //example
  //std::string fileName = "2sat1.txt";
  std::string fileName = "ex.txt";

  // defining the linked list that holds the graph
  std::vector<std::vector<int>> Graph;     // holds the original graph
  std::vector<std::vector<int>> Graph_rev; // holds the reverse of the graph

  // reading the file containing the problem
  readFile(fileName, Graph, Graph_rev);


  if (DEBUG)  {
  // writing the graph on screen
  std::cout << " The graph :" << std::endl;
  for (int i=0; i< Graph.size(); ++i){
    std::cout << " Vertix= " << i << std::endl;
    for (std::vector<int>:: iterator itr=Graph[i].begin(); itr!=Graph[i].end(); ++itr){
      std::cout << *itr << "  " ;
    };
    std::cout << std::endl;
  };
  

  // writing the reverse of the graph on screen
  std::cout << " The reverse of a graph :" << std::endl;
  for (int i=0; i<Graph_rev.size(); ++i){
    std::cout << " Vertix= " << i << std::endl;
    for (std::vector<int>:: iterator itr=Graph_rev[i].begin(); itr!=Graph_rev[i].end(); ++itr){
      std::cout << *itr << "  " ;
    };
    std::cout << std::endl;
  };
  }
 
  /*
  std::vector<int> scc(sizeOfGraph);
  std::vector<int> NumOfNodeSCC(sizeOfGraph);


  // finding the Strongly Connected Components
  SCC_Kosaraju(Graph, Graph_rev, sizeOfGraph, scc);

  for (std::vector<int> :: iterator itr = scc.begin(); itr != scc.end(); ++itr ){
    //std::cout << " node " << *itr -1<< std::endl;
    NumOfNodeSCC[*itr  - 1]= NumOfNodeSCC[*itr  - 1] +1; // counting number of nodes in each SCC
  };


  //for (std::vector<int> :: iterator itr = NumOfNodeSCC.begin(); itr != NumOfNodeSCC.end(); ++itr ){
  //  std::cout << " num " << *itr << std::endl;
  //};


  std::sort(NumOfNodeSCC.begin(), NumOfNodeSCC.end());
  for (std::vector<int> :: reverse_iterator ritr=NumOfNodeSCC.rbegin(); ritr < NumOfNodeSCC.rbegin()+5; ++ritr){
    std::cout << " max number of nodes: " << *ritr << std::endl;  
  }
 */
 return 0;
}
