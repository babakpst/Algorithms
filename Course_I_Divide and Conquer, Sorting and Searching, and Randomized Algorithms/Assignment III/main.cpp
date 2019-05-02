
// quicksort using the Toughgarden book
// Babak Poursartip

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


int ChoosePivot(int l, int r, int flag){

int i;  // pivot
if (flag==1){
i = l; // always the first element
} else if (flag ==2){
i = r; // always the last element
} else if (flag ==3){
i = l + rand() %(l-r+1);      // random pivot, average of 10 runs
}
std::cout<< " pivot " << l << " " << i << " " << r <<  std::endl;

return i;
}

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



  std::cout << " Partitioned " << l << " " << r << " " << i - 1 << std::endl;
  for (int k = l; k < r; k++){
    std::cout << " sorted "  << k << " : " << array[k] << "\n";
  }

  return i-1;
}

// ================================================================================================
void QuickSort(int*& array, int l, int r){

// base case
if (l>=r) return;

int flag = 1;

// pivot
int i = ChoosePivot( l, r, flag); 

// swap 
int temp = array[l];
array[l] = array[i];
array[i]= temp;

// new pivot position
int j=Partition(array, l, r);
std::cout << " new pivot position: " << j << " l " << l << " r " << r << std::endl;
if (l<j-1) QuickSort(array, l, j-1);
if (j+1<r) QuickSort(array, j+1, r);

}

// main code ======================================================================================
int main(){

int const sizeOfArray = 15;
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
InputFile.open("input1.txt", std::ios::in);

for (int i =0; i < sizeOfArray; i++){
  InputFile >> array[i];
  std::cout << " array " << i << " : " << array[i] << "\n";
}


  QuickSort(array,0 ,sizeOfArray);
  
  std::cout << " Done wtih the QuickSort function! " << std::endl;
  for (int i = 0; i < sizeOfArray; i++){
    std::cout << " sorted "  << i << " : " << array[i] << "\n";
  }
  delete[] array;
  return 0;
}