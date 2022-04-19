/*
Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array
or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
*/

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int*, int, int, short);
int* takeInputArray(int*, int);

int main()
{
  int cases;
  scanf("%d", &cases);

  for(int i = 0; i < cases; i++)
  {
    int size, target;
    scanf("%d", &size);

    int* arr = (int*) malloc(size*sizeof(int));
    arr = takeInputArray(arr, size);
    scanf("%d", &target);

    int start = binarySearch(arr, size, target, 0);
    int end = binarySearch(arr, size, target, 1);

    if(start == -1 || end == -1)
      printf("Key not Present");
    else
      printf("%d - %d", target, end-start+1);
  }
}

int binarySearch(int* arr, int size, int target, short isEnd)
{
  int start = 0, end = size-1, mid = 0, ind = -1;

  while(start <= end)
  {
    mid = start+(end-start)/2;

    if(arr[mid] < target)
      start = mid + 1;
    else if(arr[mid] > target)
      end = mid-1;
    else
    {
      ind = mid;
      if(isEnd)
        start = mid+1;
      else
        end = mid-1;
    }
  }
  return ind;
}


int* takeInputArray(int* arr, int size)
{
  for(int i = 0; i < size; i++)
    scanf("%d", &arr[i]);
  return arr;
}
// 1
// 15
// 1 2 2 3 3 5 5 5 25 75 75 75 97 97 97
// 75

// 1
// 10
// 235 235 278 278 763 764 790 853 981 981
// 981
