#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfs(int n, vector<int> adj[], vector<int> &vis, stack<int> &stk)
{
  vis[n] = 1;
  for(int i = 0; i < adj[i].size(); i++)
  {
    if(adj[n][i] && !vis[i])
      dfs(i, adj, vis, stk);
  }
  stk.push(n);
}
vector<int> topologicalSort(vector<int> adj[])
{
  vector<int> vis;
  stack<int> stk;

  for(int i = 0; i < adj[0].size(); i++)
    vis.push_back(0);

  for(int i = 0; i < adj[0].size(); i++)
    if(!vis[i])
      dfs(i, adj, vis, stk);

  vector<int> ans;
  while(!stk.empty())
  {
    ans.push_back(stk.top());
    stk.pop();
  }
  return ans;
}


int main()
{
  int nodes;
  cin>>nodes;

  vector<int> adj[nodes];
  for(int i  = 0; i < nodes; i++)
  {
    for(int j = 0; j < nodes; j++)
    {
      int t;
      cin>>t;
      adj[i].push_back(t);
    }
  }

  vector<int> ans = topologicalSort(adj);
  for(auto it = ans.begin(); it != ans.end(); ++it)
  {
    cout<<*it<<", ";
  }
  cout<<endl;
  return 0;
}
