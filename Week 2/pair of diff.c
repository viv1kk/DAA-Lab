/*
Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.
*/


#include <stdio.h>
#include <stdlib.h>

int* takeInputArray(int*, int);
void printArray(int*, int);
int countPairs(int*, int, int);

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
    printf("%d\n", countPairs(arr, size, target));
  }
}

int countPairs(int* arr, int size, int target)
{
  int count = 0;

  for(int i = 0; i < size-1; i++)
  {
    for(int j = i+1; j < size; j++)
    {
      int diff = abs(arr[i]-arr[j]);
      if(diff == target)
      count++;
    }
  }
  return count;
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
}

// 1
// 10
// 24 71 16 92 12 28 48 14 20 22
// 4
