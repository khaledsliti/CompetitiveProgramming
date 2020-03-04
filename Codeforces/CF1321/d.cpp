// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, m;
vector<int> g[N], rev[N];
int k;
int path[N];
int dist[N];

void bfs(int src) {
  for(int i = 0 ; i < n ; i++)
    dist[i] = -1;
  dist[src] = 0;
  queue<int> q;
  q.push(src);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int i = 0 ; i < sz(rev[u]) ; i++) {
      int v = rev[u][i];
      if(dist[v] == -1) {
        dist[v] = 1 + dist[u];
        q.push(v);
      }
    }
  }
}

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0 ; i < m ; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[--a].pb(--b);
    rev[b].pb(a);
  }
  scanf("%d", &k);
  for(int i = 0 ; i < k ; i++) {
    scanf("%d", path + i);
    --path[i];
  }
  bfs(path[k - 1]);
  // for(int i = 0 ; i < n ; i++)
  //   cout << i + 1 << " " << dist[i] << endl;
  int mx = 0, mn = 0;
  for(int i = 0 ; i < k - 1 ; i++) {
    int cur = path[i];
    int nxt = path[i + 1];
    bool good = 0;
    for(int j = 0 ; j < sz(g[cur]) ; j++) {
      int v = g[cur][j];
      if(v == nxt) {
        mn += (1 + dist[nxt]) != dist[cur];
      } else if(!good) {
        good = (1 + dist[v] == dist[cur]);
      }
    }
    mx += good;
  }
  cout << mn << " " << mx << endl;
  return 0;
}
