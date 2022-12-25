// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 100006;
const int L = 17;

int n;
vector<int> g[N];
int anc[N][L], lev[N];
int sub[N], ok[N], par[N];
map<int, int> cnt[N];
int col[N];

void dfs1(int u, int p) {
  anc[u][0] = p;
  for(int j = 1 ; (1 << j) < n ; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  for(int i = 0 ; i < (int)g[u].size() ; i++){
    int v = g[u][i];
    if(v != p){
      lev[v] = 1 + lev[u];
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

int get_dist(int a, int b) {
  int lca = get_lca(a, b);
  return lev[a] + lev[b] - 2 * lev[lca];
}

void update(int u) {
  int cur = u;
  while(~cur) {
    int dist = get_dist(cur, u);
    if(col[u]) cnt[cur][dist]++;
    else if(!--cnt[cur][dist]) cnt[cur].erase(dist);
    cur = par[cur];
  }
}

int query(int u) {
  int ans = n;
  int cur = u;
  while(~cur) {
    int dist = get_dist(cur, u);
    if(cnt[cur].size())
      ans = min(ans, dist + cnt[cur].begin()->first);
    cur = par[cur];
  }
  if(ans == n) ans = -1;
  return ans;
}

int main()
{
  scanf("%d", &n);
  memset(col, 0, sizeof col);
  for(int i = 1 ; i < n ; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  lev[0] = 0;
  dfs1(0, -1);
  centroid_decomp();
  // for(int i = 0 ; i < n ; i++)
  //   cout << i + 1 << " " << par[i] + 1 << endl;
  int q;
  scanf("%d", &q);
  while(q--) {
    int t, u;
    scanf("%d%d", &t, &u);
    --u;
    if(t == 0) {
      col[u] ^= 1;
      update(u);
    } else {
      printf("%d\n", query(u));
    }
  }
  return 0;
}
