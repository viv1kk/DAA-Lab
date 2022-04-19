/*
Given an unsorted array of integers, design an algorithm and a program to sort the array using
insertion sort. Your program should be able to find number of comparisons and shifts ( shifts total
number of times the array elements are shifted from their place) required for sorting the array.
*/

// 1
// 8
// -23 65 -31 76 46 89 45 32

#include <stdio.h>
#include <stdlib.h>

int* takeInputArray(int*, int);
void printArray(int*, int);
int* insertionSort(int*, int);

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
    arr = insertionSort(arr, size);
    printArray(arr, size);
    free(arr);
    printf("\n");
  }
}

int* insertionSort(int* arr, int size)
{
  int shifts = 0, compr = 0;
  int key = 0;
  for(int i = 1; i < size; i++)
  {
    key = arr[i];
    int j = i-1;
    while(j >= 0 && key < arr[j])
    {
      compr++;
      shifts++;
      arr[j+1] = arr[j];
      j--;
    }
    shifts++;
    arr[j+1] = key;
  }
  printf("shifts = %d\ncomparisions = %d", shifts, compr);
  return arr;
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
  printf("\n");
  for(int i = 0; i < size; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");
  return;
}
