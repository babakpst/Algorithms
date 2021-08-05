#include<iostream>
#include<cstdio>
#include<vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;
vector<vector<int> > result;

// ========================
void subset(std::vector<int> arr,int k,int n,int idx)
{

  if(idx==n) return;

  if(k==1)
  {
    for(int i=idx;i<n;i++)
     {
        v.push_back(arr[i]);
        result.push_back(v);
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

  std::cout << " outside the subset loop: \n";
  for(int i = 0;i<result.size();i++)
  { 
    for(int j = 0;j<result[i].size();j++)
    {
       cout << result[i][j] << " ";
    }
  cout << endl;
  }
}
