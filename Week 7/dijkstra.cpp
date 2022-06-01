#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int searchInd(vector<pair<int,int>> dist, int s)
{
  for(auto it = dist.begin(); it != dist.end(); ++it)
  {
    if((*it).second == s)
      return it-dist.begin();
  }
  return 0;
}

vector<pair<int, int>> dijkstra(vector<vector<int>> adj, int src, int dest)
{
  int s = adj.size();
  vector<int> vis;
  vector<pair<int, pair<int, int>>> dist;
  vector<pair<int, int>> ans;

  priority_queue< pair<int, pair<int, int> > , vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

  for(int i = 0; i < s; i++)
  {
    vis.push_back(0);
    dist.push_back(make_pair(INT_MAX, make_pair(i,i)));
  }

  dist[src].first = 0;
  pq.push(dist[src]); // set the weight source node to 0

  while(!pq.empty())
  {
    pair<int, pair<int, int>> tp = pq.top();
    int w = tp.first;
    int n = ((tp.second).second);

    pq.pop();

    if(n == dest) break;
    if(!vis[n])
    {
      vis[n] = 1;
      for(int i = 0; i < s; i++)
        if(adj[n][i] > 0 && !vis[i] && (dist[i].first) > (w + adj[n][i]))
        {
          (dist[i].first) = w + adj[n][i];
          (((dist[i]).second).first) = n;
          pq.push(dist[i]);
        }
    }
  }

  int is = src;
  int id = dest;

  do
  {
    ans.push_back(make_pair(dist[id].first, ((dist[id]).second).second));
    id = (dist[id].second).first;
  }while(is != id);

  return ans;
}

int main()
{
  int n;
  cin>>n;
  vector<vector<int> > adj;
  for(int i = 0; i < n; i++)
  {
    vector<int> x;
    for(int j = 0; j < n; j++)
    {
      int a;
      cin>>a;
      x.push_back(a);
    }
    adj.push_back(x);
  }

  cout<<endl;
  for(int i = 0; i < n; i++)
  {
    vector<pair<int, int>> ans = dijkstra(adj, 0, i);
    cout<<i+1<<" : ";
    for(auto it = ans.begin(); it != ans.end(); it++)
    {
      cout<<(*it).second+1<<", ";
    }
    cout<<" --> "<<ans[searchInd(ans, i)].first;
    cout<<endl;
  }
  return 0;
}
