
#include "KargerMinCut.h"
#include "UnionFind.h"


Karger::Karger(Graph mGraph):cutGraph{mGraph}{
  std::cout << " Creating the Karger Algorithm ... \n";
  numV=cutGraph.getNumV();
  std::cout << "checkpoint K000" << std::endl;
  numE=cutGraph.getNumE();
  std::cout << "checkpoint K001" << std::endl;
  UnionFind uf(numV);
  std::cout << "checkpoint K002" << std::endl;
}


// ================================================================================================
int Karger::KargerMinCut(){
  std::cout << "checkpoint 100 " << std::endl;
	UnionFind uf(cutGraph.getNumV());
  std::cout << "checkpoint 200 " << std::endl;
	while (uf.getNumVertices() > 2){
    std::cout << "checkpoint 000 " << std::endl;
  	int randEdge = rand()%cutGraph.getNumE();
		std::cout << "checkpoint 001 " << randEdge << " " << cutGraph.getNumE() << std::endl;
    int src = cutGraph.getEdge(randEdge).src;
		int dest = cutGraph.getEdge(randEdge).dest;
		std::cout << "checkpoint 010 " << src <<  " " << dest << std::endl;
    int comp1 = uf.find(src);
		int comp2 = uf.find(dest);
		std::cout << "checkpoint 020 " << std::endl;
    if (comp1 == comp2) continue; //if same component, skip this edge
		else {
		  std::cout << "checkpoint 030 \n";
    	uf.fUnion(src, dest);
		}
  }

  std::cout << " outside the while loop" << std::endl;

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