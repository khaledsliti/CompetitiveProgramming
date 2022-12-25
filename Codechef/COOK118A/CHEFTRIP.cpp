#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 100001;
const int L = 18;

int n, q;
vector<int> g[N];
int val[N];
int anc[N][L], lev[N];
int incr[N], decr[N];

void dfs1(int u, int p) {
  anc[u][0] = p;
  for(int j = 1 ; (1 << j) < n ; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  for(int i = 0 ; i < (int)g[u].size() ; i++){
    int v = g[u][i];
    if(v != p){
      lev[v] = 1 + lev[u];
      incr[v] = val[v] < val[u] ? incr[u] : v;
      decr[v] = val[v] > val[u] ? decr[u] : v;
      dfs1(v, u);
    }
  }
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
      a = anc[a][i];
  if(a == b) return a;
  for(int i = lg ; i >= 0 ; i--)
    if(anc[a][i] != anc[b][i])
      a = anc[a][i], b = anc[b][i];
  return anc[a][0];
}

bool check(int u, int v) {
  int lca = get_lca(u, v);
  for(int i = 0; i < 2; i++) {
    if(lev[incr[u]] <= lev[lca] && lev[decr[incr[v]]] <= lev[lca])
      return true;
    swap(u, v);
  }
  return false;
}

void solve() {
  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++)
    g[i].clear();
  for(int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", &val[i]);
  }
  incr[0] = decr[0] = 0;
  lev[0] = 0;
  dfs1(0, -1);
  while(q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    printf("%d", check(u, v));
  }
  puts("");
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
