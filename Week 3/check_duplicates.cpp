/*
Given an unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity = O(n log n))
*/

#include <iostream>
#include <algorithm>
using namespace std;

int* takeInputArray(int*, int);
void printArray(int*, int);
void search(int*, int);

int main()
{
  int cases;
   cin>>cases;

  int i;
  for(i = 0; i < cases; i++)
  {
    int size;
    cin>>size;

    int* arr = new int[size];
    arr = takeInputArray(arr, size);

    sort(arr, arr+size);
    printArray(arr, size);
    search(arr, size);
    delete[] arr;
    cout<<endl;;
  }
}

int* takeInputArray(int* arr, int size)
{
  for(int i = 0; i < size; i++)
  {
    cin>>arr[i];
  }
  return arr;
}

void printArray(int* arr, int size)
{
  for(int i = 0; i < size; i++)
  {
    cout<<arr[i]<<", ";
  }
  cout<<"\n";
  return;
}

void search(int* arr, int size)
{
  for(int i = 1; i < size; i++)
  {
    if(arr[i] == arr[i-1])
    {
      cout<<"Yes";
      return;
    }
  }
  cout<<"NO";
  return;
}

// 1
// 5
// 28 52 83 14 75

// 1
// 15
// 75 35 86 57 98 23 73 1 64 8 11 90 61 19 20

// 1
// 10
// 75 65 1 65 2 6 86 2 75 8
