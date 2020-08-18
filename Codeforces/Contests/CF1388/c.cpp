// We only fail when we stop trying
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

const int N = 1e5 + 5;

int n, m;
int p[N], h[N];
vector<int> g[N];
ll sub[N], a[N], b[N];
bool good;


void dfs(int u, int par) {
  sub[u] = p[u];
  for(int v : g[u]) {
    if(v != par) {
      dfs(v, u);
      sub[u] += sub[v];
    }
  }
}

void dfs2(int u, int par) {
  ll sa = 0, sb = 0;
  for(int v : g[u]) {
    if(v != par) {
      dfs2(v, u);
      sa += a[v], sb += b[v];
    }
  }
  if(a[u] + b[u] - p[u] != sa + sb || a[u] < sa)
    good = false;
}

void solve() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", p + i);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", h + i);
  }
  for(int i = 0; i < n; i++) {
    g[i].clear();
  }
  for(int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[--a].pb(--b);
    g[b].pb(a);
  }
  dfs(0, -1);
  for(int i = 0; i < n; i++) {
    ll hap = h[i], s = sub[i];
    if(((hap + s) % 2 == 1) || hap > s || hap + s < 0) {
      puts("NO");
      return;
    }
    a[i] = (hap + s) / 2;
    b[i] = (s - hap) / 2;
  }
  good = true;
  dfs2(0, -1);
  if(good) puts("YES");
  else puts("NO");
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
