#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 5, S = 1e3 + 5;

int n, nodes;
int order[S][S];
int idx[S][S];
vector<int> g[N];
int in[N];

int get_idx(int a, int b)
{
  if(a > b)
    swap(a, b);
  return idx[a][b];
}

void add_edge(int f, int t)
{
  in[t]++;
  g[f].pb(t);
}

void topo_sort()
{
  queue<int> q;
  int levels = 0, vis = 0;
  for(int i = 0 ; i < nodes ; i++)
    if(!in[i])
      q.push(i);
  while(!q.empty()){
    int s = q.size();
    levels++;
    while(s--){
      int u = q.front();
      q.pop();
      vis++;
      for(int i = 0 ; i < sz(g[u]) ; i++){
        int v = g[u][i];
        if(!--in[v]){
          q.push(v);
        }
      }
    }
  }
  if(vis < nodes)
    cout << -1 << endl;
  else
    cout << levels << endl;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n - 1 ; j++){
      int k;
      scanf("%d", &k);
      order[i][j] = --k;
    }
  }
  nodes = 0;
  for(int i = 0 ; i < n ; i++){
    for(int j = i + 1 ; j < n ; j++)
      idx[i][j] = nodes++;
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = 1 ; j < n - 1 ; j++){
      add_edge(get_idx(i, order[i][j - 1]), get_idx(i, order[i][j]));
    }
  }
  topo_sort();
  return 0;
}
