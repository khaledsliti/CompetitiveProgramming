/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/187/problem/C

  Idea:
    Suppose that t is an intersection with volunteers.
    Let the set of all intersections with volunteers be the source of the bfs algorithm.
    For each node, we have the distance to the nearest intersection with volunteers.
    We use binary search to find the result, and for a fixed of q we check if s and t are connected.

  Compexity:
    Time: O(M log(N))
    Memory: O(N + M)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

const int N = 2e5 + 5;

int n, k, m, s, t;
int vol[N], dist[N], src[N], par[N];
vector<int> g[N];
vector<pair<int, int>> edges;

int fs(int x){
  return x == par[x] ? x : par[x] = fs(par[x]);
}

bool check(int len)
{
  for(int i = 0 ; i < n ; i++)
    par[i] = i;
  for(int e = 0 ; e < (int)edges.size() ; e++){
    int u = edges[e].first;
    int v = edges[e].second;
    if(src[u] != -1 && src[v] != -1 && src[u] != src[v] && dist[u] + dist[v] + 1 <= len){
      u = fs(src[u]);
      v = fs(src[v]);
      if(u != v)
        par[u] = v;
    }
  }
  return fs(s) == fs(t);
}

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0 ; i < k ; i++){
    int a; scanf("%d", &a);
    vol[--a] = 1;
  }
  while(m--){
    int u, v;
    scanf("%d%d", &u, &v);
    g[--u].push_back(--v);
    g[v].push_back(u);
    edges.push_back(mp(u, v));
  }
  scanf("%d%d", &s, &t);
  --s, --t;
  assert(vol[s]);
  vol[t] = 1;
  queue<int> q;
  memset(dist, -1, n * sizeof(dist[0]));
  memset(src, -1, sizeof src);
  for(int i = 0 ; i < n ; i++){
    if(vol[i]){
      q.push(i);
      dist[i] = 0;
      src[i] = i;
    }
  }
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0 ; i < (int)g[u].size() ; i++){
      int v = g[u][i];
      if(dist[v] == -1){
        dist[v] = 1 + dist[u];
        src[v] = src[u];
        q.push(v);
      }
    }
  }
  int l = 1, r = n, ans = -1;
  while(l <= r){
    int mid = (l + r) / 2;
    if(check(mid)){
      ans = mid;
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
