

// Merge Sort algorithm
// Babak Poursartip

// Comments
/*
This is code is based on the following youtube clip: https://www.youtube.com/watch?v=FYX_yG-9CxE
*/

#define DEBUG 0

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

//=================================================================================================
// merge function: 
// this function merges the left and right array so that they are in the ascending order
void Merge(int Array[], int low, int high, int mid, long long int &splitInv) {
  //std::cout << " >>>> Merge function ... " << low << " " << high <<  std::endl;
  if (DEBUG)
  for (int i =low; i<=high; i++) {
    std::cout << "numbers Merge function ... " << Array[i] << std::endl;
  }

  splitInv = 0;
  int i = low; 
  int j = mid+1;
  int k = low; 
  int const sizeOfArray=high-low;

  int* Merged = new int[sizeOfArray];
  
  printf("chk 00 \n");
  while (i<=mid && j<=high) {
    printf("chk 01 \n");
    if (Array[i]<Array[j])
    {
    printf("chk 02 \n");
      Merged[k] = Array[i];
      i++;
    }else {//if (Array[i]>Array[j])
      printf("chk 03 %d %d %d %d %d\n", k, j, low, high, sizeOfArray);
      Merged[k] = Array[j];
      splitInv += mid - i + 1;
      j++;
    }
    k++;
    printf("chk 04 \n");
  }

  printf("chk 10 \n");
  while (i <= mid)
  {
    Merged[k]= Array[i];
    i++;
    k++;
  }
  printf("chk 20 \n");
  while (j <= high)
  {
    Merged[k]= Array[j];
    j++;
    k++;
  }
  printf("chk 30 \n");
  for (int i=low; i <k; i++)
  {
    Array[i] = Merged[i];
    //std::cout << " Merged ... " << Merged[i] << std::endl;
  }
  printf("chk 40 \n");
  //delete [] Merged;
  printf("chk 50 \n");
}

//=================================================================================================
// MergeSort function splits the input array into the left and the right array
void MergeSort(int Array[], int low, int high, long long int &splitInv){
  
  //std::cout << " ==== MergeSort function ... " << low << " " << high <<  std::endl;
  if (DEBUG)
  for (int i =low; i<=high; i++)
  {
    std::cout << "numbers MergeSort function ... " << Array[i] << std::endl;
  }
  
  long long int splitInvTemp1=0;
  long long int splitInvTemp2=0;
  long long int splitInvTemp3=0;

  int mid;
  if (low<high){

    mid=(low+high)/2;
  
    MergeSort(Array,low, mid, splitInvTemp1);
    MergeSort(Array, mid+1, high, splitInvTemp2);

    Merge(Array, low, high, mid, splitInvTemp3);

    //std::cout << " ****** inversion " << splitInvTemp1 << " " << splitInvTemp2 << " "  << splitInvTemp3 << " " << std::endl;
    splitInv = splitInvTemp1 + splitInvTemp2 + splitInvTemp3; 
    std::cout << " merge sort: " << splitInv << "\n"; 
  }
}


//=================================================================================================
// main code
int main (){

int const sizeOfArray = 100000;
int array[sizeOfArray];

/*
srand((unsigned)time(0));

for (int i = 0; i < sizeOfArray; i++){
  array[i]   = (rand()%100)+1;
  std::cout << " array "  << i << " : " << array[i] << "\n";
}
*/

std::ifstream InputFile;
//InputFile.open("input1.txt", std::ios::in);
InputFile.open("IntegerArray.txt", std::ios::in);
for (int i =0; i< sizeOfArray; i++){
  InputFile >> array[i] ;
  //std::cout << " array "  << i << " : " << array[i] << "\n";
}


long long int splitInvCount = 0;
std::cout << " Passing data to the MergeSort function ... " << std::endl;

MergeSort(array, 0, sizeOfArray-1, splitInvCount);

std::cout << " Done wtih the MergeSort function! " << std::endl;
if (DEBUG)
for (int i = 0; i < sizeOfArray; i++){
  std::cout << " sorted "  << i << " : " << array[i] << "\n";
}

//delete[] array;
std::cout << " Number of inversions: " << splitInvCount << std::endl;

 return 0; 
}
