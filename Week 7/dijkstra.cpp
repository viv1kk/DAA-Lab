#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int searchInd(vector<pair<int,int>> dist, int s)
{
  for(auto it = dist.begin(); it != dist.end(); ++it)
  {
    if((*it).first == s)
      return it-dist.begin();
  }
  return 0;
}

vector<pair<int, int>> dijkstra(vector<vector<int>> adj, int src, int d)
{
  int s = adj.size();
  vector<int> vis;
  vector<pair<int,int>> dist, ans;

  priority_queue< pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>> > pq;

  for(int i = 0; i < s; i++)
  {
    vis.push_back(0);
    dist.push_back(make_pair(INT_MAX, i));
  }
  pq.push(dist[src]); // set the weight source node to 0

  while(!pq.empty())
  {
    pair<int, int> f = pq.top();
    int front = (pq.top()).second;
    pq.pop();

    if(front == d)
    {
      ans.push_back(f);
      return ans;
    }

    if(!vis[front])
    {
      vis[front] = 1;
      ans.push_back(f);

      int min = INT_MAX;
      for(int i = 0; i < s; i++)
      {
        if(adj[front][i] != 0 && !vis[i] &&dist[i].first > dist[front].first+adj[front][i])
        {
          dist[i].first = dist[front].first+adj[front][i];
          min = (dist[i].first < min)?dist[i].first:min;
        }
      }
      if(min == INT_MAX)
        continue;
      pq.push(dist[searchInd(dist, min)]);
    }
  }
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
  vector<pair<int, int>> ans = dijkstra(adj, 0, 4);

  for(auto it = ans.begin(); it != ans.end(); it++)
    cout<<(*it).second<<", ";
  return 0;
}
