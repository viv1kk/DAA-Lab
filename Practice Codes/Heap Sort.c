#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void createHeap(int*, int, int);
void heapify(int*, int, int, int);
void heapSort(int*, int, int);

void printHeap(int*, int);
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

  int c;

  printf("Sort Ascending : (1/0) ");
  scanf("%d", &c);

  printHeap(arr, s);
  createHeap(arr, s, c);
  printHeap(arr, s);
  heapSort(arr, s, c);
  printHeap(arr, s);
  // free(arr);
}


void createHeap(int* arr, int s, int c)
{
  int p = floor((s-1)/2.0)-1;
  for(int i = p; i >= 0; i--)
    heapify(arr, i, s, c);
}


void heapify(int* arr, int p, int s, int c)
{
  int l = (2*p)+1;
  int r = (2*p)+2;


  if(c)  // Ascending Order -- max heap is created
  {
    int largest = p;
    if(l < s && arr[l] >= arr[largest])
    largest = l;

    if(r < s && arr[r] >= arr[largest])
    largest = r;

    if(largest != p)
    {
      swap(arr, p, largest);
      heapify(arr, largest, s, c);
    }
  }
  else  // Descending Order -- min heap is created
  {
    int smallest = p;

    if(l < s && arr[l] <= arr[smallest])
    smallest = l;

    if(r < s && arr[r] <= arr[smallest])
    smallest = r;

    if(smallest != p)
    {
      swap(arr, p, smallest);
      heapify(arr, smallest, s, c);
    }
  }
}

void swap(int* arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void heapSort(int* arr, int s, int c)
{
  for(int i = s-1; i >= 0; i--)
  {
    swap(arr, 0, i);
    heapify(arr, 0, i, c);
  }
}

void printHeap(int* arr, int s)
{
  for(int i = 0; i < s; i++)
    printf("%d, ", arr[i]);
  printf("\n");
}
