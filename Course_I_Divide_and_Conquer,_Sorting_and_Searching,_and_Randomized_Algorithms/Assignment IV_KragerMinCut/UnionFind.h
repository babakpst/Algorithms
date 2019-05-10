
/*

Babak Poursartip
May 3, 2019

Union find 

*/

#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <iostream>
#include <vector>
#include <algorithm>

class UnionFind{
  
private:
int numV;  // number of remaining vertices/components
std::vector<int> id; //parent link (site indexed)
std::vector<int> sz;

public:

UnionFind();
UnionFind(int numV);
~UnionFind();
int getNumVertices();

int find(int p);

bool connected(int p, int q);

int getMax();

void fUnion(int p, int q);

};


#endif // !UNIONFIND_H
