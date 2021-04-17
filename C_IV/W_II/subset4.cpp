#include<iostream>
#include<cstdio>
#include<vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

// ========================
void subset(std::vector<int> arr,int k,int n,int idx)
{

  if(idx==n) return;

  if(k==1)
  {
    for(int i=idx;i<n;i++)
     {
        v.push_back(arr[i]);
        for (auto c: v) std::cout << c << " ";
        std::cout << std::endl;
        v.pop_back();
     }
  }

  for(int j=idx;j<n;j++) 
  {
    v.push_back(arr[j]);
    subset(arr,k-1,n,j+1);
    v.pop_back();
  }
}


// ====================
int main(){
  int n = 6; // size of array
  std::vector<int> arr(n);
  iota(begin(arr), end(arr), 1);  
  int k = 2;

  subset(arr,k,n,0);

}
