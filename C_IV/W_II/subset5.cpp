#include<iostream>
#include<cstdio>
#include<vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

vector<int> v;
static int ind = 0;

// ========================
void subset(std::map<std::set<int>,int> &indxMap, std::vector<int> arr,int k,int n,int idx)
{

  if(idx==n) return;

  if(k==1)
  {
    for(int i=idx;i<n;i++)
     {
        v.push_back(arr[i]);
        std::set<int> mySet;
        for (auto c: v) mySet.insert(c);
        indxMap.insert(std::pair<std::set<int>,int>(mySet,ind));
        ++ind;
        for (auto c: v) std::cout << c << " ";
        std::cout << std::endl;
        v.pop_back();
     }
  }

  for(int j=idx;j<n;j++) 
  {
    v.push_back(arr[j]);
    subset(indxMap, arr,k-1,n,j+1);
    v.pop_back();
  }
}


// ====================
int main(){
  int n = 6; // size of array
  std::vector<int> arr(n);
  iota(begin(arr), end(arr), 1);  
  int k = 2;

  std::map<std::set<int>,int> indxMap;

  subset(indxMap, arr,k,n,0);


  std::cout << " print map: \n";
  for (auto c: indxMap){
    std::set<int> mySet = c.first;
    int val = c.second;
    std::cout << "{";
    for (auto it = mySet.begin(); it !=mySet.end(); ++it)
        cout  << *it<< ' ';
    std::cout << "}: " << val << std::endl;
  }

}
