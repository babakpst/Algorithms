
#include "../../include/module_1/graph.h"

graph::graph() { m.pt("default ctor"); }

graph::graph(const int nVertices) : nVertices{nVertices} {
  inpGraph.resize(nVertices);
  m.pt("object created successfully.");
}

// =============================================================================
void graph::pushEdge(const int u, const int v, const int w, const int count) {
  printf("edge %d: %d %d %d \n", count, u, v, w);
  inpGraph[u].push_back(std::make_pair(v, w));
  inpGraph[v].push_back(std::make_pair(u, w));
}

// =============================================================================
void graph::print() {

  for (auto e : outMST) {
    std::cout << e.first << " -- " << e.second << std::endl;
  }
  printf("\n\n Answer \n   total weight: %ld \n\n", sum);
}

// =============================================================================
// find the MST using prim algo: https://www.youtube.com/watch?v=z1L3rMzG1_A
void graph::findMST() {
  printf(" \n working on MST \n");

  std::vector<int> Q; // un explored vertices
  Q.resize(nVertices);

  for (int i = 0; i < nVertices; ++i) {
    parent[i] = INT_MIN;
    key[i] = INT_MAX;
    Q[i] = i;
  }
  // assume that the source is vertix 0
  key[0] = 0;

  while (!Q.empty()) { // O(V)
    // this part returns the vertix with the smallest element
    int u = *std::min_element(Q.begin(), Q.end(), [&](int x, int y) {
      return key[x] < key[y];
    }); // O(v)
    printf(" \n min is: %d %d %d\n", u, parent[u], parent[u] != INT_MIN);

    // removing the vertix from the list of unexplored vertices
    std::vector<int>::iterator itr = remove(Q.begin(), Q.end(), u); // O(V)
    Q.erase(itr, Q.end()); // erase() following remove() idiom

    if (parent[u] != INT_MIN) {
      outMST[u] = parent[u]; // This is one edge of MST
      sum += key[u];
      printf("adding: %d %d %ld \n", u, parent[u], sum);
    }

    // finding the adjacent vertices of current vertix
    std::vector<std::list<std::pair<int, int>>> adj;
    std::list<std::pair<int, int>>::iterator it;
    // traverse over all the vertices attached to u
    for (it = inpGraph[u].begin(); it != inpGraph[u].end(); ++it) {
      int v = (*it).first;
      int weight = (*it).second;
      printf(" fix: %d %d %d \n", u, v, weight);

      if (find(Q.begin(), Q.end(), v) != Q.end()) { // O(V)
        printf(" mod: %d %d %d \n", v, weight, key[v]);
        if (weight < key[v]) {

          parent[v] = u;
          key[v] = weight;
          printf(" ok: %d %d %d \n", v, parent[v], key[v]);
        }
      }
    }
  }
}