#include <iostream>

using namespace std;

bool isLucky(int num)
{
  static int counter = 2;
  cout<<num<<", ";

  if(counter > num)
    return 1;
  if(num % counter == 0)
    return 0;
  int np = num - num/counter;
  counter++;
  return isLucky(np);
}

int main()
{
  int num;
  cin>>num;

  if(isLucky(num))
    cout<<"1";
  else
    cout<<"-1";

  return 0;
}
