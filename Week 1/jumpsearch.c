/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k
] and so on. Once the interval (arr[2k
]
< key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k
to find the element
key. (Complexity < O(n), where n is the number of elements need to be scanned for searching):
*/


// 1
// 8
// 12 39 40 45 51 54 68 72
// 12


// 1
// 5
// 12 23 36 39 41
// 41

// 1
// 10
// 101 246 438 561 796 869 899 4644 7999 8545
// 8545

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* takeInputArray(int*, int);
void printArray(int*, int);
void jumpSearch(int*, int, int);
void linearSearch(int*, int, int, int, int);

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

    jumpSearch(arr, size, target);

    free(arr);
    printf("\n");
  }
}

void jumpSearch(int* arr, int size, int target)
{
  int jump = sqrt(size);
  int start = 0;

  while(1)
  {
    if(arr[start] <= target && start < size)
    {
      start += jump;
      printf("%d, ", start);
    }
    else
    {
      linearSearch(arr, size, start-jump, start, target);
      break;
    }
  }
  return;
}

void linearSearch(int* arr,int size, int start, int end, int target)
{
  int i = start;
  printf("%d, %d",start, end);
  for(i = start; i < end && i < size; i++)
  {
    if(i < 0)
      continue;

    if(arr[i] == target)
    {
      printf("Present");
      return;
    }
  }
  printf("Not Present");
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
