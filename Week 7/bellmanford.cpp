#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> bellmanFord(vector<vector<int>> adj, int src, int dest)
{
  vector<pair<int, pair<int, int>>> ed;
  int s = adj.size();
  for(int i = 0; i < s; i++)
  {
    ed.push_back(make_pair(INT_MAX, make_pair(i,i)));
  }

  ed[src].first = 0;

  int k = adj.size();
  while(k--)
    for(int i = 0; i < s; i++)
      for(int j = 0; j < s; j++)
        if(adj[i][j] != 0 && ed[i].first + adj[i][j] < ed[j].first)
        {
          ed[j].first = ed[i].first + adj[i][j];
          (ed[j].second).first = i;
        }

  int f = 0;
  for(int i = 0; i < s; i++)
    for(int j = 0; j < s; j++)
      if(adj[i][j] != 0 && ed[i].first + adj[i][j] < ed[j].first)
      {
        cout<<"NEGATIVE CYCLE DETECTED\n";
        f = 1;
        break;
      }

  vector<pair<int, int>>ans;
  if(!f){
    int i = dest;
    do{
      ans.push_back(make_pair(ed[i].first, (ed[i].second).second));
      i = (ed[i].second).first;
    }while(i != src);
  }
  else
    ans.push_back(make_pair(-1,-1));

  return ans;
}

int main()
{
  int s;
  cin>>s;

  vector<vector<int>> adj;
  for(int i = 0; i < s; i++)
  {
    vector<int> x;
    for(int j = 0; j < s; j++)
    {
      int ip;
      cin>>ip;
      x.push_back(ip);
    }
    adj.push_back(x);
  }

cout<<endl;
 vector<pair<int, int>> path;
 for(int i = 0; i < s; i++)
 {
   path = bellmanFord(adj, 0, i);
   cout<<i+1<<" : ";
   for(auto it = path.begin(); it!= path.end(); ++it)
     cout<<(*it).second+1<<", ";
   cout<<" : "<<path[0].first<<endl;
 }
  return 0;
}
