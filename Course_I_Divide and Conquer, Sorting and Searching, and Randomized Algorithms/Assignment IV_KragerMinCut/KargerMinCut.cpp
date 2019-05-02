
#include "KargerMinCut.h"



Karger::Karger(Graph& mGraph):cutGraph{mGraph}{
  std::cout << " Creating the Karger Algorithm ... \n";
  numV=cutGraph.getNumV();
  numE=cutGraph.getNumE();
}


// ================================================================================================
int Karger::KargerMinCut(){

  int MinCut = numV;   // holds min cut. It has been initialized with the number of vertices
  int numReducedV = numV; // number of vertices after contraction

  //while ( numReducedV >2 ){}

  return MinCut;
}

