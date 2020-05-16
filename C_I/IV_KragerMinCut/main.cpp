

/*

Developer: Babak Poursartip

Assignment IV of CourseI: Divide and Conquer, Sorting and Searching, and Randomized Algorithms
Karger Minimum Cut (Contraction Algorithm)

Date: April 23, 2019

*/

// libraries
#include <iostream>
#include "Graph.h"
#include "KargerMinCut.h"

// ================================================================================================
int main(){

std::cout <<"\n Assignment IV: Karger minimum cut aglorthtm \n";

// Define graph -----------------------------------------------------------------------------------
int Niter =400; // total number of running the algorithm to find the min cut

//int numV = 8; // num of vertices in the graph
//std::string File = "test.txt";

int numV = 200; // num of vertices in the graph
std::string File = "kargerMinCut.txt";

int MinCut = numV; // minimum cut

Graph mGraph(numV, File);

// Reading the Graph from the file
mGraph.read();
mGraph.printGraph();  // will print edges if needed


// contraction algorithm (Karger) -----------------------------------------------------------------

srand(time(NULL));

int check;
  for(int i = 0; i<Niter; ++i){
    Karger KargerAlgo(mGraph);
    
    check = KargerAlgo.KargerMinCut();
    std::cout << " MinCut in iteration: " << i << " is: " << check << "\n";
    if ( MinCut > check ) MinCut = check; 
    }

std::cout << " \n Min number of cut is: " << MinCut << "\n";

// Closing the code -------------------------------------------------------------------------------
std::cout << "\n End of the code! \n";

return 0;

}