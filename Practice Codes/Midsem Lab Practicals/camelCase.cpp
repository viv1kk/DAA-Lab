// find number of words in a string in camelCase

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string a;
  cin>>a;

  int count = 1;

  for(int i = 1; i < (int)a.length(); i++)
  {
    if(isupper(a[i]))
      count++;
  }
  cout<<count;
  return 0;
}
