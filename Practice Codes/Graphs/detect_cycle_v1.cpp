#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void printAllEdges(vector<vector<int> > );
bool haveCycle(vector<vector<int> > );

int main()
{
  int n;
  cin>>n;

  vector<vector<int> > adj;
  for(int i = 0; i < n; i++)
  {
    vector<int> x;
    for(int j = 0; j < n ; j++)
    {
      int inp;
      cin>>inp;
      x.push_back(inp);
    }
    adj.push_back(x);
  }

  cout<<endl;
  printAllEdges(adj);
  cout<<endl;

  (haveCycle(adj))?cout<<"YES\n":cout<<"NO\n";
  return 0;
}

void printAllEdges(vector<vector<int> > adj)
{
  cout<<"All the Edges in Graph:"<<endl;
  for(int i = 0; i < adj.size(); i++)
    for(int j = 0; j < adj.size(); j++)
      if(adj[i][j])
        cout<<i<<" <---> "<<j<<endl;
}

bool haveCycle(vector<vector<int> > adj)
{
  vector<int> vis;
  queue<int>que;

  for(int i = 0; i < adj.size(); i++)
  {
    vis.push_back(0);
  }

  for(int n = 0; n < adj.size(); n++)
  {
    for(int i = 0; i < adj.size(); i++)
      vis[i] = 0;
    que.push(n);

    while(!que.empty())
    {
      int front = que.front();
      que.pop();

      if(!vis[front])
      {
        vis[front] = 1;
        for(int i = 0; i < adj.size(); i++)
          if(adj[front][i] && !vis[i])
            que.push(i);
          else if(adj[front][i] && i == n)
            return true;
      }
    }
  }
  return false;
}
