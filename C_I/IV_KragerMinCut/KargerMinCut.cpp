
#include "KargerMinCut.h"
#include "UnionFind.h"


Karger::Karger(Graph mGraph):cutGraph{mGraph}{
  numV=cutGraph.getNumV();
  numE=cutGraph.getNumE();
  
  std::cout << " Creating the Karger Algorithm- N. Vertices: " << numV << " no. of Edges: " <<  
                                                                                     numE <<  "\n";
  //UnionFind uf(numV);
  }


// ================================================================================================
int Karger::KargerMinCut(){
  
	UnionFind uf(cutGraph.getNumV());
  
	while (uf.getNumVertices() > 2){
    
  	int randEdge = rand()%cutGraph.getNumE();
		    
    int src = cutGraph.getEdge(randEdge).src;
		int dest = cutGraph.getEdge(randEdge).dest;
		
    //std::cout << "random edge " << std::setw(5) <<  randEdge << " " << std::setw(5) << cutGraph.getNumE() << " src:" << std::setw(5) << src << " dest:" << std::setw(5) << dest << std::endl;

    int comp1 = uf.find(src);
		
    int comp2 = uf.find(dest);
		
    if (comp1 == comp2) continue; //if same component, skip this edge
		else {
			uf.fUnion(src, dest);
		}
  
   
  
  }

  int MinCut = 0;
	for (int i = 0; i<cutGraph.getNumE(); i++)
	{
		int subset1 = uf.find(cutGraph.getEdge(i).src);
		int subset2 = uf.find(cutGraph.getEdge(i).dest);
		if (subset1 != subset2)
			MinCut++;
	}

	return MinCut;

}

Karger::~Karger(){}