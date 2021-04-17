
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
#include <cmath>
#include <map>
#include <set>

const double max = 999999999.0;

// =======================
double calculateDistance(const std::pair<double, double> &p1, const std::pair<double, double> &p2){
  return sqrt(pow((p2.first - p1.first), 2) + pow((p2.second - p1.second), 2));
}

// =======================
bool readMap(std::vector<std::vector<double>> &map, const std::string fileName){
  
  std::fstream inp(fileName);
  int nCities;
  inp >> nCities;

  map.resize(nCities);
  for (auto &cities:map)
    cities.resize(nCities);

  
  std::vector<std::pair<double,double>> coordinates(nCities);
  double x, y;
  for (int i = 0; i < nCities; ++i) {
    inp >> x >> y;
    coordinates[i] = std::make_pair(x, y);
  }
  inp.close();

  for (int i = 0; i < nCities; ++i)
    for (int j = 0; j < nCities; ++j)
    {
      if (i == j)
        map[i][j] = 0.0;
      else
      {
        map[i][j] = calculateDistance(coordinates[i], coordinates[j]);
      }
    }

  std::cout << " here is the map: \n";
  for (int i = 0; i < nCities; ++i)
  {
    for (int j = 0; j < nCities; ++j) std::cout << map[i][j] << " ";
    std::cout << std::endl;
  }

  return true;
}


//===============
void findSubsets(std::map<std::set<int>,int> &indxMap, std::vector<std::vector<double>> &A, 
                 std::vector<int> arr, std::vector<int> v, int k, int n, int idx,
                 std::vector<std::vector<double>> &map)
{
  static int ind = 1;
  if (idx == n) return;

  if (k == 1)
  {
    for (int i = idx; i < n; i++)
    {
      v.push_back(arr[i]);
      // result.push_back(v);
      
      std::set<int> mySet;
      mySet.insert(0);
      for (auto c: v) mySet.insert(c);
      indxMap.insert(std::pair<std::set<int>,int>(mySet,ind));
      std::cout << "no. " << ind << ":   ";
      ++ind;
      for (auto c: v) std::cout << c << " ";
        std::cout << std::endl;
      
      for (auto j : v)
      {
        int min = max;
        std::set<int> myFind(mySet);
        myFind.erase(j);
        double value = + map[][j];
        if (min > value) min = value; 

        int aIndx = indxMap.find(mySet)->second;
        A[aIndx][j] =
      }
      std::cout << std::endl;

      v.pop_back();
     }
  }

  for (int j = idx; j < n; j++)
  {
    v.push_back(arr[j]);
    findSubsets(indxMap, A, arr, v, k - 1, n, j + 1, map);
    v.pop_back();
  }
}

// =========================
double TravelingSalesmanProblem(std::vector<std::vector<double>> &map){
    
    
    double min = max;
    int nCities = map.size();
    
    
    // base case
    int totalSize = 1<<nCities;
    --totalSize;
    std::vector<std::vector<double>> A(totalSize);
    std::cout << " allocation: \n";
    for (int i = 0; i < totalSize; ++i)
    {
      A[i].resize(nCities);
      A[i][0] = max;
    }
    A[0][0] = 0.0;
    
    std::vector<int> arr(nCities-1);
    iota(begin(arr), end(arr), 1);
    std::vector<int> v;
    
    std::map<std::set<int>,int> indxMap; // holds the index of A


    for (int m = 1; m<nCities; ++m){ // subproblem size
       // for each set S of {1,2,3, ..., n} of size m that contains 1,
       std::cout << " subsets of size : " << m << std::endl;
       findSubsets(indxMap, A, arr, v, m, nCities, 0, map);
         // for each j in S not containing 1.
    }

// ====================================
return min;
}

int main(){
  std::cout << " starts ... \n";

  std::vector<std::vector<double>> map;
  //std::string fileName = "tsp.txt";
  //std::string fileName = "tsp_small.txt";
  std::string fileName = "tsp_5.txt";
  readMap(map, fileName);
  double min = TravelingSalesmanProblem(map);
  std::cout << " min distance is: " << min << std::endl;
  std::cout << " ends here \n";
  return 0;
}
