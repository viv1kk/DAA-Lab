/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input)
*/

#include <stdio.h>
#include <stdlib.h>

int* takeInputArray(int*, int);
void printArray(int*, int);
void binarySearch(int*, int, int);

int main()
{
  int cases;

  scanf("%d", &cases);

  int i;
  for(i = 0; i < cases; i++)
  {
    int size, target;
    scanf("%d", &size);

    int *arr = (int*) malloc(size*sizeof(int));
    arr = takeInputArray(arr, size);
    scanf("%d", &target);

    binarySearch(arr, size, target);

    free(arr);
    printf("\n");
  }
}

void binarySearch(int* arr, int size, int target)
{
  int start = 0, end = size-1, mid = 0;
  int count = 0;
  while(start <= end)
  {
    mid = start+(end-start)/2;
    count++;
    if(arr[mid] < target)
      start = mid + 1;
    else if(arr[mid] > target)
      end = mid-1;
    else
    {
      printf("Present %d", count);
      return;
    }
  }
  printf("Not Present %d", count);
  return;
}

int* takeInputArray(int* arr, int size)
{
  for(int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }
  return arr;
}

void printArray(int* arr, int size)
{
  for(int i = 0; i < size; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");
  return;
}
