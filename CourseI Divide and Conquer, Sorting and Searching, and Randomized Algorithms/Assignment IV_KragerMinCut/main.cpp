

/*

Developer: Babak Poursartip

Assignment IV of CourseI: Divide and Conquer, Sorting and Searching, and Randomized Algorithms
Karger Minimum Cut (Contraction Algorithm)

Date: April 23, 2019

*/

// libraries
#include <iostream>
#include "Graph.h"

// ================================================================================================
int main(){

std::cout <<"\n Assignment IV: Karger minimum cut aglorthtm \n";

// Define graph -----------------------------------------------------------------------------------
int numV = 8; // num of vertices in the graph
int iter = 200; // total number of running the algorithm to find the min cut
int MinCut = numV; // minimum cut

Graph mGraph(numV);

// Reading the Graph from the file
mGraph.read();
mGraph.printGraph();


// contraction algorithm (Karger) -----------------------------------------------------------------

//srand(time(NULL));

//int MinCut = KargerMinCut(mGraph, numV, numEdges);
//std::cout << " \n Min number of cut is: " << MinCut << "\n";

// Closing the code -------------------------------------------------------------------------------
std::cout << "\n End of the code! \n";

return 0;

}