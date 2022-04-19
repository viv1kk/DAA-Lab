/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
find whether two elements exist such that their sum is equal to the given key element. (Time
Complexity = O(n log n))
*/

#include <iostream>
#include <algorithm>
using namespace std;

int* takeInputArray(int*, int);
void printArray(int*, int);
void searchPair(int*, int, int);


int main()
{
  int cases;
  scanf("%d", &cases);
  int i;
  for(i = 0; i < cases; i++)
  {
    int size;
    cin>>size;

    int *arr = new int[size];

    arr = takeInputArray(arr, size);
    sort(arr, arr+size);

    int target;
    cin>>target;

    searchPair(arr, size, target);
    delete [] arr;
  }
}

void searchPair(int* arr, int size, int target)
{
  int i = 0, j = size-1;

  while(i < j)
  {
    if(arr[i]+arr[j] < target)
      i++;
    else if(arr[i]+arr[j] > target)
      j--;
    else
    {
      printf("\n%d, %d\n", arr[i], arr[j]);
      return;
    }
  }
  printf("\nNo Such Element Exist\n");
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
