/*
Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k].
*/

#include <stdio.h>
#include <stdlib.h>

int* takeInputArray(int*, int);
void printArray(int*, int);
void findSequence(int*, int);
int binarySearch(int*, int, int);

int main()
{
  int cases;
  scanf("%d", &cases);

  int i;
  for(i = 0; i < cases; i++)
  {
    int size;
    scanf("%d", &size);

    int *arr = (int*) malloc(size*sizeof(int));
    arr = takeInputArray(arr, size);

    findSequence(arr, size);

    free(arr);
    printf("\n");
  }
}
void findSequence(int* arr, int size)
{
  for(int i = 0; i < size-1; i++)
  {
    for(int j = i+1; j < size; j++)
    {
      int k = binarySearch(arr, size, arr[i]+arr[j]);
      if(k != -1)
      {
        printf("%d, %d, %d", i, j, k);
        return;
      }
    }
  }
  printf("No Sequence Found.");
  return;
}

int binarySearch(int* arr, int size, int target)
{
  int start = 0, end = size-1, mid = 0;

  while(start <= end)
  {
    mid = start+(end-start)/2;

    if(arr[mid] < target)
      start = mid + 1;
    else if(arr[mid] > target)
      end = mid-1;
    else
      return mid;
  }
  return -1;
}

int* takeInputArray(int* arr, int size)
{
  for(int i = 0; i < size; i++)
    scanf("%d", &arr[i]);
  return arr;
}

void printArray(int* arr, int size)
{
  for(int i = 0; i < size; i++)
    printf("%d, ", arr[i]);
  printf("\n");
  return;
}

// 1
// 5
// 1 5 84 209 341

// 1
// 10
// 24 28 48 71 86 89 92 120 194 201
