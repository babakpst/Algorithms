
#include <vector>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Graph.h"

class Karger{

private:
  int numV; // number of vertices
  int numE; // number of edges
  Graph cutGraph;

public:

Karger();
Karger(Graph& cutGraph);

int KargerMinCut();

};


