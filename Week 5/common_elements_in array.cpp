/*
You have been given two sorted integer arrays of size m and n. Design an algorithm and
implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))
*/

#include <iostream>
#include <algorithm>

using namespace std;

int* takeInputArray(int*, int);
void findDuplicates(int*, int, int*, int);
void printArray(int*, int);

int main()
{
  int size1;
  int size2;

  cin>>size1;
  int* arr1 = new int[size1];
  arr1 = takeInputArray(arr1, size1);

  cin>>size2;
  int* arr2 = new int[size2];
  arr2 = takeInputArray(arr2, size2);

  sort(arr1, arr1+size1);
  int i = 0, j = 0;
  cout<<endl;
  while(i < size1 && j < size2)
  {
    if(arr1[i] < arr2[j])
      i++;
    else if(arr1[i] > arr2[j])
      j++;
    else
    {
      cout<<arr1[i]<<", ";
      i++;
      j++;
    }
  }
  cout<<endl;
  return;
}

void printArray(int* arr, int size)
{
  cout<<"\n";
  for(int i = 0; i < size; i++)
  {
    cout<<arr[i]<<", ";
  }
  cout<<"\n";
  return;
}

int* takeInputArray(int* arr, int size)
{
  for(int i = 0; i < size; i++)
  {
    cin>>arr[i];
  }
  return arr;
}
