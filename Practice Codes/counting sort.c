#include <stdio.h>
#include <stdlib.h>

typedef struct rng
{
  int lb;
  int ub;
}Range;

int* takeInputArray(int*, int);
void printArray(int*, int);
void countingSort(int*, int, Range);
Range findRange(int*, int);

int main()
{
  printf("Enter the size of Array : ");
  int size;
  scanf("%d", &size);

  int* arr = (int*) malloc(size*sizeof(int));
  printf("Enter the elements of the array :\n");
  arr = takeInputArray(arr, size);

  Range r = findRange(arr, size);
  countingSort(arr, size, r);
  printArray(arr, size);
  free(arr);
}

void countingSort(int* arr, int size, Range r)
{
  int* freq = (int*)calloc(r.ub+1, sizeof(int));
  int* ans = (int*)calloc(size, sizeof(int));

  //making frequency array
  for(int i = 0; i < size; i++)
    freq[arr[i]]++;

// taking cumulative sum
  for(int i = 1; i <= r.ub; i++)
    freq[i] += freq[i-1];

  for(int i = size-1; i >= 0; i--)
  {
    ans[freq[arr[i]]-1] = arr[i];
    freq[arr[i]]--;
  }

  for(int i = 0; i < size; i++)
    arr[i] = ans[i];

  free(freq);
  free(ans);
}

Range findRange(int* arr, int size)
{
  int min = 0, max = 0;

  for(int i = 0; i < size; i++)
  {
    if(arr[i] < min)
      min = arr[i];
    if(arr[i] > max)
      max = arr[i];
  }
  Range r;
  r.lb = min;
  r.ub = max;
  return r;
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
