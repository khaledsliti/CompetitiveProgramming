// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int L = 18;
const int Mod = 1e9 + 7;

int n, m, ncomp;
int comp[N], val[N];
int par[N][L], lev[N], sum[N];
vector<int> g[N];
vector<int> tr[N];
int po[N];

int cur_idx;
int num[N], low[N]; 
stack<int> st;

void dfs(int u, int p) {
  low[u] = num[u] = ++cur_idx;
  st.push(u);
  for(int i = 0 ; i < sz(g[u]) ; i++) {
    int v = g[u][i];
    if(num[v] == -1) {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    } else if(v != p) {
      low[u] = min(low[u], num[v]);
    }
  }
  if(low[u] == num[u]) {
    val[ncomp] = -1;
    while(true) {
      int t = st.top(); st.pop();
      comp[t] = ncomp;
      ++val[ncomp];
      if(t == u) break;
    }
    val[ncomp] = min(val[ncomp], 1);
    ncomp++;
  }
}

void build_tree() {
  for(int i = 0 ; i < n ; i++)
    for(int j : g[i])
      if(comp[i] != comp[j])
        tr[comp[i]].pb(comp[j]);
}

void dfs1(int u, int p) {
  par[u][0] = p;
  sum[u] = val[u] + (p >= 0 ? sum[p] : 0);
  for(int v : tr[u]) {
    if(v != p) {
      lev[v] = 1 + lev[u];
      dfs1(v, u);
    }
  }
}

void pre_lca() {
  for(int i = 0 ; i < ncomp ; i++)
    for(int j = 0 ; (1 << j) < ncomp ; j++)
      par[i][j] = -1;
  dfs1(0, -1);
  for(int j = 1 ; (1 << j) < ncomp ; j++)
    for(int i = 0 ; i < ncomp ; i++)
      if(par[i][j - 1] != -1)
        par[i][j] = par[par[i][j - 1]][j - 1];
}

int get_lca(int a, int b) {
  if(lev[a] < lev[b]) swap(a, b);
  int lg = 0;
  for(; (1 << lg) <= lev[a] ; lg++);
  lg--;
  for(int j = lg ; j >= 0 ; j--)
    if(lev[a] - (1 << j) >= lev[b])
      a = par[a][j];
  if(a == b) return a;
  for(int j = lg ; j >= 0 ; j--)
    if(par[a][j] != par[b][j])
      a = par[a][j], b = par[b][j];
  return par[a][0];
}

int solve(int u, int v) {
  u = comp[u], v = comp[v];
  int lca = get_lca(u, v);
  int tot = sum[u] + sum[v] - sum[lca] - (lca > 0 ? sum[par[lca][0]] : 0);
  return po[tot];
}

int main()
{
  po[0] = 1;
  for(int i = 1 ; i < N ; i++)
    po[i] = 2 * po[i - 1] % Mod;
  scanf("%d%d", &n, &m);
  for(int i = 0 ; i < m ; i++) {
    int a, b; scanf("%d%d", &a, &b); a--, b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  memset(comp, -1, n * sizeof(comp[0]));
  memset(num, -1, n * sizeof(num[0]));
  dfs(0, -1);
  build_tree();
  pre_lca();
  int q;
  scanf("%d", &q);
  while(q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    printf("%d\n", solve(u, v));
  }
  return 0;
}
