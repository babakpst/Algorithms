
/*
===============================================================================
Developer: Babak Poursartip

Course III:       Greedy algorithm
Assignment III:   Dynamic Programming
Data:             06/14/2020
===============================================================================
*/

#define DEBUG 0 // 0 FALSE, 1 TRUE

// libraries
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

// classes
int main() {

  printf("Start running the code ...\n");  

  // reading the path graph from the input file
  std::fstream inp; // input file handler
  inp.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    if (DEBUG) {
      inp.open("test.txt", std::ios::in);
    } else {
      inp.open("mwis.txt", std::ios::in);
    }
  } catch (std::ifstream::failure &inputerr) { // catch for the input file
    printf(" Error while opening the input file!!! \n");
    printf(" The error message is: \n");
    printf("%s \n",inputerr.what());
    throw inputerr;
  }

  int nVertices; // no. of vertices in the path graph
  int weight;    // weight of each vertix
  inp >> nVertices;
  
  std::vector<unsigned long> pg(nVertices+1); // path graph
  
  for (unsigned long i = 0; i < nVertices; ++i) {
    inp >> weight;
    pg[i+1]=weight;
  }


  std::vector<unsigned long> wis(nVertices+1, 0); // weights of IS: equivalent to A in the algo.
  std::set<unsigned long> IS;

  // initialize
  wis[1] = pg[1];
  // finding the weights
  for (unsigned long i=2; i<=nVertices; ++i){
    wis[i] = std::max(wis[i-1],wis[i-2]+pg[i]);
  }

  if (DEBUG) 
  for (unsigned long i=0; i<=nVertices; ++i){
    printf("%ld - ", wis[i]);
    if ((i % 10)==9) printf("\n");
  }


  printf("\n max weight is: %ld \n", wis[nVertices] );

  // finding the set
  long i = nVertices, one=1ul;

  while(i >= one){
    //if (wis[i-1]>=(wis[i-2] + pg[i])) --i;
    if (wis[i-1]==wis[i]) --i;
    else {
      IS.insert(i);
      i-=2;
      if (DEBUG) printf(" in the set: %ld \n", i);
    }
  }

  //if (DEBUG){
  printf(" IS: \n");
  //unsigned long index;
  for (std::set<unsigned long>::iterator it=IS.begin(); it !=IS.end(); ++it){
    printf(" %ld - ", *it);
    //index = it - IS.begin();
    auto index = std::distance(IS.begin(),it);
    if ((index % 20)==19) printf("\n");
  }
  //}

  printf("\n\n are you here: \n");
  std::vector<int> vx={ 1, 2, 3, 4, 17, 117, 517, 997};
  bool is_in;
  for (std::vector<int>::iterator it = vx.begin(); it!=vx.end(); ++it){
    is_in = IS.find(*it) != IS.end();
    printf(" %d \n", is_in);
  }

  

  printf("\nEnd of the code!\n");
  return 0;
}
