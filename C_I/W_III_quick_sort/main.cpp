
// quicksort using the Toughgarden book
// Babak Poursartip

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define DEBUG 0
long long int noComparison=0; 

// ===========================================================
int ChoosePivot(int l, int r, int flag){

int i=0;  // pivot
if (flag==1){
 i = l; // always the first element
} else if (flag ==2){
 i = r; // always the last element
} else if (flag ==3){
 i = l + rand() %(l-r+1);      // random pivot, average of 10 runs
} else if (flag ==4){
// not active
}
if (DEBUG) std::cout<< " pivot " << l << " " << i << " " << r <<  std::endl;

return i;
}


// ===========================================================
int Partition(int*& array, int l, int r){
  // new pivot position
  int p = array[l];
  int i = l+1;
  for (int j = l+1; j <= r; j++){
    if (array[j]< p){
      int temp = array[j];
      array[j] = array[i];
      array[i] = temp;
      i++;
    }
  }

  int temp = array[l];
  array[l] = array[i-1];
  array[i-1] = temp;

  if (DEBUG) std::cout << " Partitioned " << l << " " << r << " " << i - 1 << std::endl;
  if (DEBUG) 
  for (int k = l; k < r; k++){
    std::cout << " sorted "  << k << " : " << array[k] << "\n";
  }

  return i-1;
}

// ================================================================================================
void QuickSort(int*& array, int l, int r){

// base case
if (l>=r) return;

// input ===========
int flag = 3;

// pivot
int i = ChoosePivot( l, r, flag); 

// swap 
int temp = array[l];
array[l] = array[i];
array[i]= temp;

// new pivot position
int j=Partition(array, l, r);
noComparison += (long long int)(r-l);
std::cout << " quick: " << noComparison << "\n";

if (DEBUG)  std::cout << " new pivot position: " << j << " l " << l << " r " << r << std::endl;
if (l<j-1) QuickSort(array, l, j-1);
if (j+1<r) QuickSort(array, j+1, r);

}

// main code ======================================================================================
int main(){

// input ==================
//int const sizeOfArray = 15;
int const sizeOfArray = 10000;
int *array= new int[sizeOfArray];


srand((unsigned)time(0));

// filling the array. The assumption is that all numbers are distinct.
/*
for (int i = 0; i < sizeOfArray; i++){
  array[i]   = (rand()%100)+1;
  std::cout << " array "  << i << " : " << array[i] << "\n";
}
*/

std::fstream InputFile;

// input ==================
//InputFile.open("input1.txt", std::ios::in);
InputFile.open("QuickSort.txt", std::ios::in);

for (int i =0; i < sizeOfArray; i++){
  InputFile >> array[i];
  if (DEBUG) std::cout << " array " << i << " : " << array[i] << "\n";
}

  QuickSort(array,0 ,sizeOfArray-1);
  
  std::cout << " Done wtih the QuickSort function! " << std::endl;
  if (DEBUG)  
  for (int i = 0; i < sizeOfArray; i++){
    std::cout << " sorted "  << i << " : " << array[i] << "\n";
  }

  std::cout << " total number of comparisons: "  << noComparison << "\n";
  
  delete[] array;
  return 0;
}
