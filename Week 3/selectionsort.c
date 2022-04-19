/*
Given an unsorted array of integers, design an algorithm and implement a program to sort this
array using selection sort. Your program should also find number of comparisons and number of
swaps required.
*/

// 1
// 8
// -13 65 -21 76 46 89 45 12

#include <stdio.h>
#include <stdlib.h>

int* takeInputArray(int*, int);
void printArray(int*, int);
int* swap(int*, int, int, int);
int* selectionSort(int*, int);

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
    arr = selectionSort(arr, size);
    printArray(arr, size);
    free(arr);
    printf("\n");
  }
}

int* selectionSort(int* arr, int size)
{
  int compr = 0, swps = 0;

  for(int i = 0; i < size-1; i++)
  {
    int min = i;
    for(int j = i+1; j < size; j++)
    {
      compr++;
      if(arr[min] > arr[j])
        min = j;
    }
    swps++;
    arr = swap(arr, size, min, i);
  }
  printf("swaps = %d\ncomparisions = %d", swps, compr);
  return arr;
}

int* swap(int* arr, int size, int min, int i)
{
  int temp = arr[min];
  arr[min] = arr[i];
  arr[i] = temp;
  return arr;
}


int* takeInputArray(int* arr, int size)
{
  for(int i = 0; i < size; i++)
    scanf("%d", &arr[i]);
  return arr;
}

void printArray(int* arr, int size)
{
  printf("\n");
  for(int i = 0; i < size; i++)
    printf("%d, ", arr[i]);
  printf("\n");
  return;
}
