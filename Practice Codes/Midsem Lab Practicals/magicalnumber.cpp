#include <iostream>
using namespace std;

int* ans  = NULL;
int* comp = NULL;
int n = 0;

void binarySearch(int* arr, int size, int target)
{
  ans[n] = 0;
  comp[n] = 0;

  int start = 0, end = size-1;
  while(start <= end)
  {
    comp[n]++;

    int mid = start+(end-start)/2;
    if(arr[mid] < target)
    {
      start = mid+1;
    }
    else if(arr[mid] > target)
    {
      end = mid-1;
    }
    else
    {
      ans[n] = 1;
      break;
    }
  }
  n++;
  return;
}

int main()
{
  int cases;
  cin>>cases;

  ans = new int[cases];
  comp = new int[cases];

  for(int i = 0; i < cases; i++)
  {
    int size;
    cin>>size;
    int *arr = new int[size];

    for(int j = 0; j < size; j++)
      cin>>arr[j];

    int target;
    cin>>target;

    binarySearch(arr, size, target);
    delete[] arr;
  }

  for(int i = 0; i < cases; i++)
  {
    if(ans[i])
      cout<<"YES"<<comp[i]<<endl;
    else
      cout<<"NO\n"<<endl;
  }
  delete[] ans;
  delete[] comp;
}
