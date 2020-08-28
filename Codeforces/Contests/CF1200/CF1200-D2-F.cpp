#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1005;
const int M = 2520;

int n;
int k[N], m[N];
vector<int> g[N];
int vis[N][M + 2];
int dp[N][M + 2];

void calc(int u, int e)
{
  if(vis[u][e] == 2)
    return;
  vector<pair<int, int>> nodes;
  nodes.pb({u, e});
  vis[u][e] = 1;
  int cur = u;
  int cost = e;
  while(true){
    int nc = (cost + k[cur]) % M;
    int nxt = g[cur][nc % m[cur]];
    if(!vis[nxt][nc]){
      nodes.pb({nxt, nc});
      vis[nxt][nc] = 1;
      cur = nxt;
      cost = nc;
    }else if(vis[nxt][nc] == 1){
      unordered_set<int> cnt;
      for(int i = sz(nodes) - 1 ; i >= 0 ; i--){
        int node = nodes[i].first;
        int r = nodes[i].second;
        cnt.insert(node);
        if(node == nxt && r == nc)
          break;
      }
      while(nodes.size()){
        int node = nodes.back().first;
        int r = nodes.back().second;
        nodes.pop_back();
        dp[node][r] = sz(cnt);
        vis[node][r] = 2;
      }
    }else{
      while(nodes.size()){
        int node = nodes.back().first;
        int r = nodes.back().second;
        nodes.pop_back();
        dp[node][r] = dp[nxt][nc];
        vis[node][r] = 2;
      }
      break;
    }
  }
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", k + i);
    k[i] = ((k[i] % M) + M) % M;
  }
  for(int i = 0 ; i < n ; i++){
    cin >> m[i];
    for(int j = 0 ; j < m[i]; j++){
      int a;
      cin >> a;
      g[i].pb(--a);
    }
  }
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < M ; j++)
      calc(i, j);
  int q;
  scanf("%d", &q);
  while(q--){
    int x, y;
    scanf("%d%d", &x, &y);
    y = (y % M + M) % M;
    printf("%d\n", dp[--x][y]);
  }
  return 0;
}
