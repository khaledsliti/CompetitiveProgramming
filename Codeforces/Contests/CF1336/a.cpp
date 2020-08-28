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

int n, k;
vector<int> g[N];
int sub[N], lev[N];
int good[N];

void dfs(int u, int p) {
  sub[u] = 0;
  for(int v : g[u]) {
    if(v != p) {
      lev[v] = 1 + lev[u];
      dfs(v, u);
      sub[u] += sub[v] + 1;
    }
  }
}

long long dfs2(int u, int p, int lev) {
  long long ans = 0;
  if(!good[u]) ans += lev;
  for(int v : g[u]) {
    if(v != p) {
      ans += dfs2(v, u, lev + good[u]);
    }
  }
  return ans;
}

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n - 1 ; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[--a].pb(--b);
    g[b].pb(a);
  }
  lev[0] = 0;
  dfs(0, -1);
  vector<int> node(n);
  for(int i = 0 ; i < n ; i++)
    node[i] = i;
  sort(all(node), [&](int a, int b) {
    return lev[a] - sub[a] < lev[b] - sub[b];
  });
  for(int i = 0 ; i < n - k ; i++)
    good[node[i]] = 1;
  cout << dfs2(0, -1, 0) << endl;
  return 0;
}
