// We only fail when we stop trying
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <bitset>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 100006;
const int L = 18;
const int INF = 1000000000;

int n, q;
vector<vector<int>> g;
int sub[N], ok[N], par[N];
int lev[N], st[N], en[N];

int dfs_num;
pair<int, int> sparce[(N << 1) + 2][L + 1];
int ans[N];

void get_sz(int u, int p) {
  sub[u] = 1;
  for(int v : g[u]) {
    if(v != p && ok[v]) {
      get_sz(v, u);
      sub[u] += sub[v];
    }
  }
}

int find_centroid(int u, int p, int tot) {
  for(int v : g[u])
    if(v != p && ok[v] && sub[v] > tot / 2)
      return find_centroid(v, u, tot);
  return u;
}

void decompose(int u, int p) {
  get_sz(u, -1);
  int c = find_centroid(u, -1, sub[u]);
  par[c] = p;
  ok[c] = 0;
  for(int v : g[c]) {
    if(ok[v])
      decompose(v, c);
  }
}

void centroid_decomp() {
  for(int i = 0 ; i < n ; i++)
    ok[i] = 1;
  decompose(0, -1);
}

void add_node(int u) {
  sparce[dfs_num][0] = { lev[u], u };
  for(int j = 1 ; dfs_num - (1 << j) >= -1 ; j++) 
    sparce[dfs_num][j] = min(sparce[dfs_num][j - 1], sparce[dfs_num - (1 << (j - 1))][j - 1]);
  dfs_num++;
}

void dfs1(int u, int p) {
  add_node(u);
  st[u] = dfs_num - 1;
  for(int v : g[u]){
    if(v != p){
      lev[v] = 1 + lev[u];
      dfs1(v, u);
      add_node(u);
    }
  }
  en[u] = dfs_num - 1;
}

int get_lca(int a, int b) {
  if(st[a] > st[b]) swap(a, b);
  if(en[a] >= en[b]) return a;
  int i = en[a], j = st[b];
  int lg = 31 - __builtin_clz(j - i + 1);
  return min(sparce[j][lg], sparce[i + (1 << lg) - 1][lg]).second;
}

int get_distance(int u, int v) {
  int lca = get_lca(u, v);
  return lev[u] + lev[v] - 2 * lev[lca];
}

void add_red(int u) {
  int cur = u;
  while(~cur) {
    ans[cur] = min(ans[cur], get_distance(cur, u));
    cur = par[cur];
  }
}

int find(int u) {
  int mn = INF;
  int cur = u;
  while(~cur) {
    mn = min(mn, get_distance(cur, u) + ans[cur]);
    cur = par[cur];
  }
  return mn;
}


int main()
{
  scanf("%d%d", &n, &q);
  g.clear(); g.resize(n);
  for(int i = 1 ; i < n ; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  lev[0] = 0;
  dfs1(0, -1);
  centroid_decomp();
  for(int i = 0 ; i < n ; i++)
    ans[i] = INF;
  add_red(0);
  while(q--) {
    int t, v;
    scanf("%d%d", &t, &v); --v;
    if(t == 1) add_red(v);
    else printf("%d\n", find(v));
  }
  return 0;
}
