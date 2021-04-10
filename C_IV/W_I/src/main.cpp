
/*

Babak Poursartip

Algorithm: All Pair Shortest Path

03/28/2021

Answer:
g1: negative cycle
g2: negative cycle
g3: -19

*/

#include "iostream"
#include "fstream"
#include "vector"
#include "iterator"
#include "string"
#include "algorithm"

#define Debug 0
static int Inf = 999999;

// =====================================
// =====================================
// =====================================
bool printGraph(std::vector<std::vector<int>> &graph ) {

std::cout << "\n here is the graph: \n";
auto lm = [](std::vector<int> &e) { 
  for_each(begin(e), end(e), [](int &m) {std::cout << m << " ";} );
  std::cout << "\n";
  };
for_each(begin(graph), end(graph), lm);

return true;
}

// ====================
bool readGraph(const std::string fileName, std::vector<std::vector<int>> &graph)
{
  bool ok=false;
  std::fstream inp;  // input file handler
  inp.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
      inp.open(fileName, std::ios::in);
  } catch (std::ifstream::failure &inputerr) { // catch for the input file
    printf(" Error while opening the input file!!! \n");
    printf(" The error message is: \n");
    printf("%s \n",inputerr.what());
    throw inputerr;
  }

  unsigned int nVertices;
  unsigned int nEdges;
  inp >> nVertices >> nEdges ;

  std::cout << "\n no. of vertices: " << nVertices << "\n no. of edges: " << nEdges << std::endl;  
  
  graph.resize(nVertices);
  for_each(begin(graph), end(graph),
           [&nVertices](std::vector<int> &e) { e.resize(nVertices, Inf); });

  // Set the diagonal to zeror
  for (unsigned int i = 0; i < nVertices; ++i)
  {
      graph[i][i] = 0;
  }
  int source, destination, length;

  for (unsigned int i = 0; i < nEdges; ++i)
  {
    inp >> source >> destination >> length;
    if (Debug)
      std::cout << source << " " << destination << " " << length << "\n";
    // vertix numbering in the file starts from zero
    graph[source-1][destination-1] = length;
  }

  inp.close();
  std::cout << " done reading. \n";

  if (Debug) printGraph(graph);

  ok = true;
  return ok;
}

bool FloyedWarshall(std::vector<std::vector<int>> dist) {
if (Debug) printGraph(dist);
unsigned int nVertices = dist.size();

for (unsigned k = 0; k < nVertices; ++k)
{
  if (k%100 ==0) std::cout << " vertix: " << k << std::endl;
  // source
  for (unsigned i = 0; i < nVertices; ++i)

  {
    // destination
    for (unsigned j = 0; j < nVertices; ++j)

    {
      if (dist[i][k] + dist[k][j] < dist[i][j])
        dist[i][j] = dist[i][k] + dist[k][j];
    }
  }
}
if (Debug) printGraph(dist);

//negative cycle
bool neg = false;
for (unsigned i = 0; i < nVertices; ++i)
  if (dist[i][i] < 0)
  {
    neg = true;
    break;
  }

if (neg) {
  std::cout << " Graph has negative cycle. \n";
  return false;
}

// find min
int shortestPath = Inf;

for (unsigned int i = 1; i < nVertices; ++i)
{
  for (unsigned int j = 1; j < nVertices; ++j)
  {
    if (dist[i][j] < shortestPath && i != j)
    {
      shortestPath = dist[i][j];
    }
  }
}
std::cout << "\n Shortest Shortest-path length: " << shortestPath << std::endl;

return true;
}

// =====================================
// =====================================
// =====================================
int main(int argc, char *argv[])
{
  std::cout << " start ...\n";
  //const std::string fileName = "input/test.txt";
  //const std::string fileName = "input/g1.txt";
  //const char *fileName = "input/g2.txt";
  const char *fileName = "input/g3.txt";
  //const char *fileName = "input/l.txt";

std::vector<std::vector<int>> graph;

  // reading the graph
bool read = readGraph(fileName, graph);

bool shortest = FloyedWarshall(graph);
std::cout << "\n ends \n";
return 0;
}