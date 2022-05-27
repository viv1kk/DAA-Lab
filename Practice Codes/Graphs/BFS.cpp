#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> bfsFunc(vector<vector<int> > adj, int src, int dest)
{
  vector<int> vis, trav;
  queue<int> que;

  for(int i = 0; i < adj.size(); i++)
    vis.push_back(0);

  que.push(src);

  while(!que.empty())
  {
    int top = que.front();
    que.pop();
    if(vis[top-1] == 0)
    {
      vis[top-1] = 1;
      trav.push_back(top);
      if(top == dest)
        return trav;
      for(int i = 0; i < adj.size(); i++)
      {
        if(adj[top-1][i] == 1 && vis[i] == 0)
          que.push(i+1);
      }
    }
  }
  return trav;
}

void printAllEdges(vector<vector<int> > adj)
{
  for(int i = 0; i < adj.size(); i++)
    for(int j = 0; j < i; j++)
      if(adj[i][j])
        cout<<j<<" <----->"<<i<<endl;
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
  int src, dest;
  cin>>src>>dest;

  vector<int> bfs = bfsFunc(adj, src, dest);
  cout<<endl;
  printAllEdges(adj);
  cout<<endl;

  for(auto it = bfs.begin(); it != bfs.end(); ++it)
    cout<<*it <<" --> ";
  return 0;
}
