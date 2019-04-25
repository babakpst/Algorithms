

/*

Developer: Babak Poursartip

Assignment IV of CourseI: Divide and Conquer, Sorting and Searching, and Randomized Algorithms
Karger Minimum Cut (Contraction Algorithm)

Date: April 23, 2019

*/

// libraries
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>




// ================================================================================================
void printGraph(std::vector<int> adj[], int V) 
{ 
    std::cout << " number of vertices: " << V << std::endl;
    for (int v = 0; v < V; ++v) 
    { 
        std::cout << "\n Adjacency list of vertex "
             << v+1 << "\n head "; 
        for (auto x : adj[v]) 
           std::cout << "-> " << x+1; 
        printf("\n"); 
    } 
} 

// ================================================================================================
int KargerMinCut(std::vector<int> mGraph, int& numV, int& numEdges){

  int MinCut = 0;
  int numReducedV = 0; // number of vertices after contraction
  while ( numReducedV >2 ){



  }



  return MinCut;
}



// ================================================================================================
int main(){

std::cout <<"\n Assignment IV: Karger minimum cut aglorthtm \n";

// Define graph
int numV = 8; // num of vertices in the graph
std::vector<int> mGraph[numV];


// Reading the Graph from the file ----------------------------------------------------------------
std::ifstream InputGraph("test.txt");
std::string line;

int counter = 0;
int counterVertix; 
int numEdges =0;
int rootVertix; 
while ( std::getline(InputGraph, line)){
  counter++;
  counterVertix = 0;
  std::istringstream in(line);
  int vertix = 0;
  std::cout << " Reading vertix: " << counter << "\n";
    while (in >> vertix){
        counterVertix++;
        if (counterVertix==1) rootVertix = vertix-1;
        //std::cout << vertix << "\n";
        if (counterVertix != 1) {
          numEdges++;
          mGraph[rootVertix].push_back(vertix-1);
          std::cout << rootVertix << "   " << vertix << "\n";
        }
        }
}

InputGraph.close(); 
numEdges = numEdges/2;
printGraph(mGraph, 8);

// contraction algorithm (Karger) -----------------------------------------------------------------

srand(time(NULL));

int MinCut = KargerMinCut(mGraph, numV, numEdges);
std::cout << " \n Min number of cut is: " << MinCut << "\n";

// Closing the code -------------------------------------------------------------------------------
std::cout << "\n End of the code! \n";

return 0;

}