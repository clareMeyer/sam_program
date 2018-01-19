#include "Sorts.h"
#include "Shirts.h"
#include <iostream>
#include <string>
using namespace std;


template <typename T>
void Sorts<T>::mergeSort(T arr[], int size)//recursive sort
{
  if(size>1)//as long as your array exists
  {
    int middle=size/2;//the midde is the size divided by two

    T* left=arr;//set pointer to the start of the left array
    T* right=arr+((size/2));//set point to start of right array

    mergeSort(left, middle);//sort the left side
    mergeSort(right, size-middle);//sort the right side

    merge(left, right, middle, size-middle);//merge the left and right sides
  }
}

template <typename T>
void Sorts<T>::merge(T* a1, T* a2, int leftSize, int rightSize)
{//iterative helper function for mergeSort
  T* newArray[leftSize+rightSize];//buffer array

  int first1=0;//start of left array
  int first2=0;//start of right array
  int fill=0;//position to fill

  while(fill<(leftSize+rightSize))//while the array is not filled
  {
    if(first1==leftSize)//if the position of the left array is equal to the last value in the left side
    {
      newArray[fill]=(a2+first2);//fill array with value from right side
      first2++;//look at next value on right side
    }
    else if(first2==rightSize)//if the position of the right array is equal to the last value in the right side
    {
      newArray[fill]=(a1+first1);//fill array with value from left side
      first1++;//look at next value on left side
    }
    else if(*(a1+first1)< *(a2+first2))//if the value on the left side is less than the value on the right side
    {
      newArray[fill]=(a1+first1);//put value from left in the array
      first1++;//go to next value on left
    }
    else//if the value on the left side is greater than the value on the right side
    {
      newArray[fill]=(a2+first2);//put value from right in the array
      first2++;//go to next value on right
    }
    fill++;//go to the next position in the buffer array
  }
  for(int i=0; i<rightSize+leftSize; i++)
  {
    *(a1+i)=(*newArray[i]);//put values from buffer array in the original array
  }
}
