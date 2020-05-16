


// RSelect Algorithm
// Babak Poursartip

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>


int ChoosePivot(int l, int r, int PivotType){
  
  int pivot; 

  if (PivotType == 1) {pivot = l;}
  else if (PivotType == 2) {pivot = r;}
  else if (PivotType == 3) {
  pivot = l + rand()%(l-r+1);
  };

  std::cout << " pivot selected: " << pivot << std::endl;
  return pivot;
}


int Partition(int*& array, int l, int r){

// assuming the pivot is located at the first entry of the array, i.e. array[l]
int p = array[l];
int i = l + 1;
for (int j = l+1; j <= r; j++){

  if (array[j] < p ){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    i++;
  }
};

int temp = array[l];
array[l]  = array[i-1];
array[i-1]  = temp;


  return i-1;
}


void RSelect(int*& array, int l, int r){

if (l>=r) return ;

int i = 5; // ith order statics- input
int PivotType = 1;
int pivot  = ChoosePivot(l, r, PivotType);

int temp = array[l];
array[l] = array[pivot]; 
array[pivot] = temp;

int j = Partition(array, l, r);

if (j==i) std::cout << " ith order statics is " << array[j] << std::endl;
else if ( j < i )  RSelect(array, j+1, r);
else  RSelect(array, l, j-1);
}

int main(){

  int const sizeOfArray = 20;
  int* array = new int[sizeOfArray];

  srand((unsigned)time(0));

  // filling the array randomly
  for (int i = 0; i < sizeOfArray; i++){
    array[i] = (rand()%100)+1;
    std::cout << " array[" << i <<"]=" << array[i] << std::endl;
  };

  /*
  //reading the array from the file
  std::fstream InputFile;
  InputFile.open("input1.txt",std::ios::in);

  for (int i= 0; i< sizeOfArray; i++){
    InputFile >> array[i];
    std::cout << " array[" << i <<"]=" << array[i] << std::endl;    
  };
  */


  RSelect(array,0,sizeOfArray);


  delete[] array;
  return 0;
}