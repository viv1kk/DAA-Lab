/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot element while another sub
array holds values greater than the pivot element. Pivot element should be selected randomly
from the array. Your program should also find number of comparisons and swaps required for
sorting the array.
*/

/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by dividing the array into two subarrays and combining these subarrays
after sorting each one of them. Your program should also find number of comparisons and
inversions during sorting the array.
*/

#include <stdio.h>
#include <stdlib.h>

int* takeInputArray(int*, int);
void printArray(int*, int);
void swap(int*, int, int);
void quickSort(int*, int, int);
int partition(int*, int, int);

int compr = 0;
int swaps = 0;

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

    quickSort(arr, 0, size-1);

    printArray(arr, size);
    printf("comparisions = %d\nswaps = %d\n", compr, swaps);
    free(arr);
    printf("\n");
  }
}

void quickSort(int* arr, int start, int end)
{
  // choose end as a pivot value
  if(start >= end)
    return;

  int pind = partition(arr, start, end);

  quickSort(arr, start, pind-1);
  quickSort(arr, pind+1, end);
  return;
}


int partition(int* arr, int start, int end)
{
  int p  = start;
  int pivotVal = arr[end];

  for(int i = start; i <= end-1; i++) // because end will be my pivot value to compare agaist
  {
    compr++;
    if(arr[i] < pivotVal)
    {
      swaps++;
      swap(arr, i, p);
      p++;
    }
  }
  swaps++;
  swap(arr, end, p);
  return p;
}

void swap(int* arr, int i1, int i2)
{
  int temp = arr[i1];
  arr[i1] = arr[i2];
  arr[i2] = temp;
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
