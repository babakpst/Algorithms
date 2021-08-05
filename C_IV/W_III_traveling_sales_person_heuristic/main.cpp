
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
#include <limits>

#define DEBUG 0
//const long double max = std::showMinMax<long double>();
const long double max = 999'999'999'9.0;

// =======================
long double calculateDistance(const std::pair<double, double> &p1, const std::pair<double, double> &p2){
  if (DEBUG) std::cout<< "1: "<< p1.first<< " " << p1.second<< " 2: "<< p2.first<< " " << p2.second<< " dis: "  << sqrt(pow((p2.first - p1.first), 2) + pow((p2.second - p1.second), 2)) << std::endl;
  return (pow((p2.first - p1.first), 2) + pow((p2.second - p1.second), 2));
}

// =======================
bool readMap(std::vector<std::pair<double, double>> &map, const std::string fileName){
  
  std::fstream inp(fileName);
  int nCities;
  inp >> nCities;

  map.resize(nCities);
  
  double x, y;
  int j;
  for (int i = 0; i < nCities; ++i) {
    inp >> j >> x >> y;
    map[j-1] = std::make_pair(x, y);
  }
  inp.close();

  int n = 0;
  if (DEBUG) std::cout << " here is the map: \n";
  if (DEBUG) for_each(begin(map), end(map), [](std::pair<double, double>& e){static int i = 0; std::cout<< i <<" " << e.first<< " " << e.second<<std::endl;});
  return true;
}

// =================================================
long double nextStop(const std::vector<std::pair<double, double>> &map, int &currentCity, std::vector<bool> &visitedCities)
{
  double newDistance = max;
  int nCities = map.size();
  int nextCity;
  long double distance;
  for (int i = 0; i <nCities; ++i)
  {
    if (visitedCities[i]==false && (distance = calculateDistance(map[currentCity], map[i])))
    {
      if (newDistance > distance)
      {
        newDistance = distance;
        nextCity = i;
      }
    }
  }

  std::cout << " from city: " << currentCity;
  currentCity = nextCity;
  newDistance = sqrt(newDistance);
  std::cout << " to next city: " << nextCity << " at: " << newDistance << std::endl;
  return newDistance;
}

// =================================================
long double TravelingSalesmanProblem(std::vector<std::pair<double, double>> &map){
    
  int nCities = map.size();
  int startingCity = 0;
  int currentCity = startingCity; // starting point
  long double totalDistance = 0;
  
  std::vector<bool> visitedCities(nCities,false);
  
  if (DEBUG) std::cout << "\n starting from: " << startingCity << std::endl;
  for (int i = 1; i<nCities; ++i)      
  {
    visitedCities[currentCity] = true;
    if (DEBUG) std::cout << currentCity << std::endl;
    totalDistance += nextStop(map, currentCity, visitedCities);
  }

  double dist = sqrt(
                   pow(map[currentCity].first-map[startingCity].first,2) + 
                   pow(map[currentCity].second-map[startingCity].second,2)
                   );
  totalDistance += dist;
  std::cout << " next city: " << startingCity << " at: " << dist << std::endl;
return totalDistance;
}

int main(){
  std::cout << " starts ... \n";


  std::string fileName = "real.txt";
  //std::string fileName = "tsp_small.txt";
  //std::string fileName = "tsp_5.txt";

  // reading the map
  std::vector<std::pair<double, double>> map;
  readMap(map, fileName);
  std::cout << map.size() << " " << map[map.size()-1].first << " " << map[map.size()-1].second << std::endl;

  long double min = TravelingSalesmanProblem(map);
  std::cout << "\n min distance is: " << (long)min << std::endl;
  std::cout << " ends here \n";
  return 0;
}
