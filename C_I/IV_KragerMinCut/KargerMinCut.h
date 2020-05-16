

#ifndef KARGERMINCUT_H
#define KARGERMINCUT_H

#include <vector>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

#include "Graph.h"

class Karger{

private:
  int numV; // number of vertices
  int numE; // number of edges
  Graph cutGraph;

public:

Karger();
Karger(Graph cutGraph);

~Karger();
int KargerMinCut();

};


#endif