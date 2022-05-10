#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void createHeap(int*, int);
void printHeap(int*, int);
void heapify(int*, int, int);
void heapSort(int*, int);
void swap(int*, int, int);


int main()
{
  int arr[] = {1,3,90,5,4,6,13,10,9,8,15,17,};
  int s = sizeof(arr)/sizeof(arr[0]);

  // int *arr = (int*) malloc(s*sizeof(int));

  // for(int i = 0; i < s; i++)
  // {
  //   arr[i] = t[i];
  // }

  printHeap(arr, s);
  createHeap(arr, s);
  heapSort(arr, s);
  printHeap(arr, s);
  // free(arr);
}


void createHeap(int* arr, int s)
{
  int p = floor((s-1)/2.0)-1;
  for(int i = p; i >= 0; i--)
    heapify(arr, i, s);
}


void heapify(int* arr, int p, int s)
{
  int l = (2*p)+1;
  int r = (2*p)+2;

  int largest = p;

  if(l < s && arr[l] >= arr[largest])
    largest = l;

  if(r < s && arr[r] >= arr[largest])
    largest = r;

  if(largest != p)
  {
    swap(arr, p, largest);
    heapify(arr, largest, s);
  }
}

void swap(int* arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void heapSort(int* arr, int s)
{
  for(int i = s-1; i >= 0; i--)
  {
    swap(arr, 0, i);
    heapify(arr, 0, i);
  }
}

void printHeap(int* arr, int s)
{
  for(int i = 0; i < s; i++)
    printf("%d, ", arr[i]);
  printf("\n");
}
