#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
 
const int N = 5007;
 
int n;
vector<int> g[N];
int a, b;
 
int bfs(int src) {
  queue<int> q;
  q.push(src);
  vector<int> dist(n, 1e9);
  dist[src] = 1;
  while(q.empty() == false) {
    int u = q.front(); q.pop();
    if(u == b) return dist[b];
    for(int v : g[u]) {
      if(min(u, v) == a && max(u, v) == b) continue;
      if(dist[v] == 1e9) {
        dist[v] = 1 + dist[u];
        q.push(v);
      }
    }
  }
  return 1e9;
}
 
int main()
{
  int m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    a--, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
 
  int best = 1e9;
  for(int i = 0; i < n; i++) {
    for(int j : g[i]) {
      a = min(i, j), b = max(i, j);
      best = min(best, bfs(a));
    }
  }
  if(best >= 1e9) best = -1;
  cout << best << endl;
  return 0;
}