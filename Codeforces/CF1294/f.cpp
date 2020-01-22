#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
vector<int> adj[N];
int par[N];
int path[N];

void dfs(int u, int p, int& mx, int& node, int dist)
{
  par[u] = p;
  if(dist > mx){
    mx = dist;
    node = u;
  }
  for(int v : adj[u]){
    if(v != p){
      dfs(v, u, mx, node, dist + 1);
    }
  }
}

int main()
{
  scanf("%d", &n);
  for(int i = 1 ; i < n ; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  int mx = 0, node = 0;
  int sum = 0;
  vector<int> nodes;
  dfs(0, -1, mx, node, 0);
  nodes.pb(node + 1);
  mx = 0;
  dfs(node, -1, mx, node, 0);
  nodes.pb(node + 1);
  sum = mx;
  while(node != -1){
    path[node] = true;
    node = par[node];
  }
  mx = 0;
  for(int i = 0 ; i < n ; i++)
    if(path[i])
      for(int j : adj[i])
        if(!path[j]){
          dfs(j, i, mx, node, 1);
        }
  if(mx == 0)
    for(int i = 0 ; i < n ; i++)
      if(i != nodes[0] - 1 && i != nodes[1] - 1){
        node = i;
        break;
      }
  nodes.pb(node + 1);
  cout << sum + mx << endl;
  for(auto x : nodes)
    cout << x << " ";
  return 0;
}
