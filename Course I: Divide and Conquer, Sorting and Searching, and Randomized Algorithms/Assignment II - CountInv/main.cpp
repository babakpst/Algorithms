

// Merge Sort algorithm
// Babak Poursartip

// Comments
/*
This is code is based on the following youtube clip: https://www.youtube.com/watch?v=FYX_yG-9CxE
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

//=================================================================================================
// merge function: 
// this function merges the left and right array so that they are in the ascending order
void Merge(int Array[], int low, int high, int mid, int& splitInv)
{
  //std::cout << " >>>> Merge function ... " << low << " " << high <<  std::endl;
  for (int i =low; i<=high; i++)
  {
    //std::cout << "numbers Merge function ... " << Array[i] << std::endl;
  }

  splitInv = 0;
  int i = low; 
  int j = mid+1;
  int k = low; 
  int const sizeOfArray=high-low;

  int* Merged = new int[sizeOfArray];

  while (i<=mid && j<=high)
  {
    if (Array[i]<Array[j])
    {
      Merged[k] = Array[i];
      i++;
    }
    else //if (Array[i]>Array[j])
    {
      Merged[k] = Array[j];
      splitInv += mid - i + 1;
      j++;
    }
    k++;
  }

  while (i <= mid)
  {
    Merged[k]= Array[i];
    i++;
    k++;
  }

  while (j <= high)
  {
    Merged[k]= Array[j];
    j++;
    k++;
  }

  for (int i=low; i <k; i++)
  {
    Array[i] = Merged[i];
    //std::cout << " Merged ... " << Merged[i] << std::endl;
  }
}

//=================================================================================================
// MergeSort function splits the input array into the left and the right array
void MergeSort(int Array[], int low, int high, int& splitInv){
  
  //std::cout << " ==== MergeSort function ... " << low << " " << high <<  std::endl;
  for (int i =low; i<=high; i++)
  {
    std::cout << "numbers MergeSort function ... " << Array[i] << std::endl;
  }
  
  int splitInvTemp1=0;
  int splitInvTemp2=0;
  int splitInvTemp3=0;

  if (low<high){

    int const mid=(low+high)/2;
  
    MergeSort(Array,low, mid, splitInvTemp1);
    MergeSort(Array, mid+1, high, splitInvTemp2);

    Merge(Array, low, high, mid, splitInvTemp3);

    //std::cout << " ****** inversion " << splitInvTemp1 << " " << splitInvTemp2 << " "  << splitInvTemp3 << " " << std::endl;
    splitInv = splitInvTemp1 + splitInvTemp2 + splitInvTemp3; 
  }
}


//=================================================================================================
// main code
int main (){

int const sizeOfArray = 1000;
int array[sizeOfArray];

/*
srand((unsigned)time(0));

for (int i = 0; i < sizeOfArray; i++){
  array[i]   = (rand()%100)+1;
  std::cout << " array "  << i << " : " << array[i] << "\n";
}
*/

std::ifstream InputFile;
InputFile.open("input2.txt", std::ios::in);
for (int i =0; i< sizeOfArray; i++){
  InputFile >> array[i] ;
  //std::cout << " array "  << i << " : " << array[i] << "\n";
}


int splitInvCount = 0;
std::cout << " Passing data to the MergeSort function ... " << std::endl;

MergeSort(array, 0, sizeOfArray-1, splitInvCount);

std::cout << " Done wtih the MergeSort function! " << std::endl;
for (int i = 0; i < sizeOfArray; i++){
  std::cout << " sorted "  << i << " : " << array[i] << "\n";
}

std::cout << " Number of inversions: " << splitInvCount << std::endl;

 return 0; 
}