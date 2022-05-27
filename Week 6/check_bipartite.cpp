#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool bfsFunc(vector<vector<int> > adj, int src)
{
  vector<int> bpt;
  queue<int> que;

  for(int i = 0; i < adj.size(); i++)
    bpt.push_back(-1);

  que.push(src);
  bpt[src] = 1;

  while(!que.empty())
  {
    int top = que.front();
    que.pop();

    if (adj[top][top] == 1)
        return false;
    for(int i = 0; i < adj.size(); i++)
    {
      if(adj[top][i] == 1 && bpt[i] == -1)
      {
        bpt[i] = (bpt[top] == 1)?0:1;
        que.push(i);
      }
      else if(adj[top][i] == 1 && bpt[top] == bpt[i])
        return false;
    }
  }
  return true;
}

int main()
{
  int s;
  cin>>s;

  vector<vector<int> > adj;
  for(int i = 0; i < s; i++)
  {
    vector<int> x;
    for(int j = 0; j < s; j++)
    {
      int inp;
      cin>>inp;
      x.push_back(inp);
    }
    adj.push_back(x);
  }

  bool isBip = bfsFunc(adj, 0);

  if(isBip == true)
    cout<<"Yes Bipartite\n";
  else
    cout<<"Not Bipartite\n";
  return 0;
}
