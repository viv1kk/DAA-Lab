/*
Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)
*/

#include <stdio.h>
#include <stdlib.h>

int* takeInputArray(int*, int);
void printArray(int*, int);
int linearSearch(int*, int, int);

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

    int ind = linearSearch(arr, size, target);
    if(ind == -1)
      printf("Not Present %d", ind+1);
    else
      printf("Present %d", ind+1);
    // printArray(arr, size);
    free(arr);
    printf("\n");
  }

}

int linearSearch(int* arr, int size, int target)
{
  int i = 0;
  for(i = 0; i < size; i++)
  {
    if(arr[i] == target)
      break;
  }
  return i;
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
