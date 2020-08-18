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
const int L = 19;

int n, q;
vector<int> g[N];
int par[N][L], lev[N];

void dfs_lca(int u, int p) {
  par[u][0] = p;
  for(int i = 0 ; i < (int)g[u].size() ; i++){
    int v = g[u][i];
    if(v != p){
      lev[v] = 1 + lev[u];
      dfs_lca(v, u);
    }
  }
}

void pre_lca()
{
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; (1 << j) < n ; j++)
      par[i][j] = -1;
  lev[0] = 0;
  dfs_lca(0, -1);
  for(int j = 1 ; (1 << j) < n ; j++)
    for(int i = 0 ; i < n ; i++)
      if(par[i][j - 1] != -1)
        par[i][j] = par[par[i][j - 1]][j - 1];
}

int get_lca(int a, int b)
{
  if(lev[a] < lev[b])
    swap(a,b);
  int lg = 0;
  for(; (1 << lg) <= lev[a] ; lg++);
  lg--;
  for(int i = lg ; i >= 0 ; i--)
    if(lev[a] - (1 << i) >= lev[b])
      a = par[a][i];
  if(a == b) return a;
  for(int i = lg ; i >= 0 ; i--)
    if(par[a][i] != par[b][i])
      a = par[a][i], b = par[b][i];
  return par[a][0];
}


int main()
{
  scanf("%d%d", &n, &q);
  for(int i = 1 ; i < n ; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  pre_lca();
  while(q--) {
    int k;
    scanf("%d", &k);
    vector<int> v(k);
    for(int i = 0 ; i < k ; i++) {
      scanf("%d", &v[i]);
      --v[i];
    }
    int leaf = v[0];
    for(int i = 0 ; i < k ; i++)
      if(lev[v[i]] > lev[leaf])
        leaf = v[i];
    bool good = true;
    for(int i = 0 ; i < k ; i++) {
      int lca = get_lca(v[i], leaf);
      good &= lca == v[i] || lca == par[v[i]][0];
    }
    puts(good ? "YES" : "NO");
  }
  return 0;
}
