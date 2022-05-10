#include <stdio.h>
#include <stdlib.h>

void cycleSort(int*, int, int);
int findRange(int*, int);
void printArray(int*, int);

int main()
{
  int arr[] = {4,2,1,6,7,5,9,3,8};
  int s = sizeof(arr)/sizeof(int);

  int range = findRange(arr, s);

  printArray(arr, s);
  cycleSort(arr, s, range);
  printArray(arr, s);
}

void cycleSort(int* arr, int s, int r)
{
  int i = 0;

  while(i < s)
  {
    if(arr[i] != i+1 && arr[i] < r)
    {
      int temp = arr[i];
      arr[i] = arr[temp-1];
      arr[temp-1] = temp;
    }
    else
    {
      i++;
    }
  }
}

int findRange(int* arr, int s)
{
  int range = arr[0];

  for(int i = 0; i < s; i++)
  {
    if(range < arr[i])
      range = arr[i];
  }
  return range;
}

void printArray(int *arr, int s)
{
  for(int i = 0; i < s; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n\n");
}
