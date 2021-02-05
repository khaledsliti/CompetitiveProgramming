// RedStone
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

const int N = 2e5 + 5;
const int L = 18;

int n, m;
vector<int> g[N];
int idx[N], low[N], cur_idx;
vector<pair<int, int>> st;
vector<vector<int>> comp;
int anc[N][L], lev[N];

void dfs(int u, int p) {
  idx[u] = low[u] = cur_idx++;
  int children = 0;
  for(int v: g[u]) {
    if(idx[v] == -1) {
      children++;
      st.push_back({u, v});
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if(idx[u] == 0 && children > 1 || idx[u] > 0 && low[v] >= idx[u]) {
        comp.push_back(vector<int>());
        while(st.back().first != u || st.back().second != v) {
          comp.back().pb(st.back().first);
          comp.back().pb(st.back().second);
          st.pop_back();
        }
        comp.back().pb(st.back().first);
        comp.back().pb(st.back().second);
        st.pop_back();
      }
    } else if(v != p) {
      low[u] = min(low[u], idx[v]);
      if(idx[v] < idx[u]) {
        st.push_back({u, v});
      }
    }
  }
}

void dfs_lca(int u, int p) {
  idx[u] = 1;
  anc[u][0] = p;
  for(int j = 1 ; (1 << j) < n ; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  for(int i = 0 ; i < (int)g[u].size() ; i++){
    int v = g[u][i];
    if(v != p){
      lev[v] = 1 + lev[u];
      dfs_lca(v, u);
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

int main()
{
  scanf("%d%d", &n, &m);
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  memset(idx, -1, sizeof idx);
  for(int i = 0; i < n; i++) {
    if(idx[i] == -1) {
      cur_idx = 0;
      dfs(i, -1);
      if(st.size()) {
        comp.pb(vector<int>());
        while(st.size()) {
          comp.back().pb(st.back().first);
          comp.back().pb(st.back().second);
          st.pop_back();
        }
      }
    }
  }

  for(int i = 0; i < n; i++) {
    g[i].clear();
  }

  for(int i = 0; i < sz(comp); i++) {
    sort(all(comp[i]));
    comp[i].resize(unique(all(comp[i])) - begin(comp[i]));
    for(int u: comp[i]) {
      g[u].push_back(n + i);
      g[n + i].push_back(u);
    }
  }

  n += sz(comp);
  assert(n < N);

  memset(idx, -1, sizeof idx);
  for(int i = 0; i < n; i++) {
    lev[i] = 0;
    dfs_lca(i, -1);
  }
  
  int q;
  scanf("%d", &q);
  
  while(q--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    int lca = get_lca(a, b);
    int ans = lev[a] + lev[b] - 2 * lev[lca] + 2;
    ans = (ans + 1) / 2;
    printf("%d\n", ans);
  }

  return 0;
}
