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
 
const int N = 3e5 + 5;
 
int n, k;
set<int> g[N];
long long ans;
int sub[N], lev[N];
 
void dfs(int u, int p) {
  sub[u] = 1;
  for(int v: g[u]) {
    if(v != p) {
      dfs(v, u);
      sub[u] += sub[v];
    }
  }
}
 
int getCentroid(int u, int p, int tot) {
  for(int v: g[u]) {
    if(v != p && 2 * sub[v] > tot) {
      return getCentroid(v, u, tot);
    }
  }
  return u;
}
 
void add(int u, int p, int cur_lev) {
  lev[cur_lev]++;
  for(int v: g[u]) {
    if(v != p) {
      add(v, u, cur_lev + 1);
    }
  }
}
 
void calc(int u, int p, int tot, int cur_lev, long long& ans) {
  if(cur_lev > k) {
    return;
  }
  int x = k - cur_lev;
  if(x < tot) {
    ans += lev[x];
  }
  for(int v: g[u]) {
    if(v != p) {
      calc(v, u, tot, cur_lev + 1, ans);
    }
  }
}
 
long long calcPaths(int root, int tot) {
  for(int i = 0; i < tot; i++) {
    lev[i] = 0;
  }
  long long ans = 0;
  for(int u: g[root]) {
    calc(u, root, tot, 1, ans);
    add(u, root, 1);
  }
  if(k < tot) {
    ans += lev[k];
  }
  return ans;
}
 
void solve(int node) {
  dfs(node, -1);
  int c = getCentroid(node, -1, sub[node]);
  // cout << "centroid = " << c + 1 << endl;
  ans += calcPaths(c, sub[node]);
  // cout << "ans = " << ans << endl;
  vector<int> nxt(g[c].begin(), g[c].end());
  for(int u: nxt) {
    g[c].erase(u);
    g[u].erase(c);
    solve(u);
  }
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  cin >> n >> k;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].insert(b);
    g[b].insert(a);
  }
  solve(0);
  cout << ans << endl;
  return 0;
}
