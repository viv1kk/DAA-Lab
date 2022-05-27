/*
Given a (directed/undirected) graph, design an algorithm and implement it using a program to
find if a path exists between two given vertices or not. (Hint: use DFS)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// vector<int> dfsFunc(vector<vector<int> > adj, int s, int src, int dest)
bool dfsFunc(vector<vector<int> > adj, int s, int src, int dest)
{
  // vector<int> dfs;
  stack<int> sta;
  vector<int> vis;

  for(int i = 0; i < s; i++)
    vis.push_back(0);

  sta.push(src);
  while(!sta.empty())
  {
    int top = sta.top();
    sta.pop();
    if(vis[top-1] == 0)
    {
      // dfs.push_back(top);
      vis[top-1] = 1;
      if(top == dest)
        return true;
        // break;
      for(int i = 0; i < s; i++)
      {
        if(adj[top-1][i] == 1 && vis[i] == 0)
          sta.push(i+1);
      }

    }
  }
  // return dfs;
  return false;
}

int main()
{
  int v;
  cin>>v;

  // inputting the Adjacency Matrix
  vector<vector<int> > adj;
  for(int i = 0; i < v; i++){
    vector<int> x;
    for(int j = 0; j < v; j++){
      int n;
      cin>>n;
      x.push_back(n);
    }
    adj.push_back(x);
  }

  int s, d;
  cin>>s>>d;

  // vector<int> dfs = dfsFunc(adj, v, s, d);
  if(dfsFunc(adj, v, s, d) == true)
    cout<<"Yes Path Exists\n";
  else
    cout<<"No Such Path Exists\n";
  // for(auto it = dfs.begin(); it != dfs.end(); ++it)
  //   cout<<*it <<" --> ";

  return 0;
}
