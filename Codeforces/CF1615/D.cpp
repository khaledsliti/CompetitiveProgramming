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

const int N = 2e5 + 5, E = 4e5 + 5;
const int L = 20;

int n, m, e;
vector<pair<int, int>> g[N];
int head[N], nxt[E], to[E], idx[E], cost[E];
int dfs_idx;
int anc[N][L], lev[N];
vector<int> edges;

void init() {
  e = 0;
  memset(head, -1, sizeof(head));
}

void addEdge(int f, int t, int c, int i) {
  nxt[e] = head[f];
  head[f] = e;
  to[e] = t;
  cost[e] = c;
  idx[e] = i;
  e++;
}

void dfs(int u, int p) {
  anc[u][0] = p;
  for(int j = 1 ; (1 << j) < n ; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  for(auto e: g[u]) {
    int v = e.first;
    int c = e.second;
    if(v != p) {
      addEdge(u, v, dfs_idx++);
      lev[v] = 1 + lev[u];
      dfs(v, u);
    } 
  }
}

int get_lca(int a, int b) {
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  init();
  dfs(0, -1);

  return 0;
}
