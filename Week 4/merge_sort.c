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
void mergeSort(int*, int);
void divide(int* , int, int);
void merge(int*, int, int, int);

int compr = 0;

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

    mergeSort(arr, size);
    printArray(arr, size);

    printf("%d", compr);
    free(arr);
    printf("\n");
  }
}

void mergeSort(int* arr, int size)
{
  divide(arr, 0, size-1);
  return;
}

void divide(int* arr, int start, int end)
{
  if(start >= end)
    return;

  int mid = start+(end-start)/2;

  divide(arr, start, mid);
  divide(arr, mid+1, end);

  merge(arr, start, mid, end);
}

void merge(int* arr, int start, int mid, int end)
{
  int* temp = (int*)malloc((end-start+1)*sizeof(int));
  // printf("%d, %d, %d\n", start, mid, end);
  int i = start;
  int j = mid+1;
  int k = 0;

  while(i <= mid && j <= end)
  {
    compr++;
    if(arr[i] <= arr[j])
    {
      temp[k] = arr[i];
      i++;
    }
    else
    {
      temp[k] = arr[j];
      j++;
    }
    k++;
  }
  while(i <= mid)
  {
    temp[k] = arr[i];
    i++;
    k++;
  }
  while(j <= end)
  {
    temp[k] = arr[j];
    j++;
    k++;
  }

  for(int u = start; u <= end; u++)
    arr[u] = temp[u-start];
  free(temp);
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
