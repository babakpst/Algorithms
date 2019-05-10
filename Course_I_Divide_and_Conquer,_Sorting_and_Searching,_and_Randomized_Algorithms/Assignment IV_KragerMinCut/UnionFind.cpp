
/*

Babak Poursartip
05/03/2019

*/

#include "UnionFind.h"

UnionFind::UnionFind(){}
UnionFind::UnionFind(int numV):numV{numV},sz(numV+1,1){
  
  for (int i = 0; i <= numV; ++i) id.push_back(i);
  /*
  std::cout << " printing id: \n";
  int count = 0;
  for (std::vector<int>:: iterator iter = id.begin(); iter!=id.end(); ++iter) {
    std::cout << count << " " << *iter << "\n";
    count++;
  }
  std::cout << " printing sz: \n";
  count = 0;
  for (std::vector<int>:: iterator iter = sz.begin(); iter!=sz.end(); ++iter) {
    std::cout << count << " " << *iter << "\n";
    count++;
  }
*/

}

int UnionFind::getNumVertices(){return numV;}

int UnionFind::find(int p){
  while (p !=id[p]) {
    p=id[p]; 
    }

  return p;
}

bool UnionFind::connected(int p, int q){ return find(p) == find(q);} 

int UnionFind::getMax(){ return *std::max_element(sz.begin(),sz.end());}

void UnionFind::fUnion(int p, int q){
  int i = find(p);
  int j = find(q);

  if (i==j) return;

  // make smaller root point to the larger root.
  if (sz[i]<sz[j]) {
     id[i]=j;
     sz[j] += sz[i];
     }
     else{
       id[j] = i; 
       sz[i] += sz[j];
     }
   numV--;


 /*
 std::cout << " printing id: \n";
  int count = 0;
  for (std::vector<int>:: iterator iter = id.begin(); iter!=id.end(); ++iter) {
    std::cout << count << " " << *iter << "\n";
    count++;
  }
  std::cout << " printing sz: \n";
  count = 0;
  for (std::vector<int>:: iterator iter = sz.begin(); iter!=sz.end(); ++iter) {
    std::cout << count << " " << *iter << "\n";
    count++;
  }
*/


}

UnionFind::~UnionFind(){}