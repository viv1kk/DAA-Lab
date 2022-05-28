/*
 Given a directed graph, design an algorithm and implement it using a program to find whether
cycle exists in the graph or not.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


bool checkCycle(vector<vector<int> > adj, vector<int> gVis, vector<int> vis, int node)
{
  vis[node] = 1;
  gVis[node] = 1;

  for(int i = 0; i < adj.size(); i++)
  {
    if(adj[node][i] && !vis[i])
    {
        if(checkCycle(adj, vis, gVis, i))
          return true;
    }
    else if(adj[node][i] && vis[i] && gVis[i])
      return true;
  }
  gVis[node] = 0;
  return false;
}


bool detectCycle(vector<vector<int> > adj)
{
  vector<int> vis, gvis;

  for(int i = 0; i < adj.size(); i++)
  {
    vis.push_back(0);
    gvis.push_back(0);
  }

  for(int i = 0; i < adj.size(); i++)
  {
    if(!vis[i])
      if(checkCycle(adj, vis, gvis, i))
        return true;
  }
  return false;
}

int main()
{
  int n;
  cin>>n;

  vector<vector<int> > adj;
  for(int i = 0; i < n; i++) // taking input as adj mat
  {
    vector<int> x;
    for(int j = 0; j < n; j++)
    {
      int num;
      cin>>num;
      x.push_back(num);
    }
    adj.push_back(x);
  }
  (detectCycle(adj))?cout<<"Yes Cycle Exists\n":cout<<"No Cycle Exists\n";
  return 0;
}
