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

struct Data {
  int node, depth, from;
  bool operator<(const Data& rhs) const {
    return depth > rhs.depth;
  }
};

int n;
vector<int> g[N];
int anc[N][L], lev[N];
vector<Data> dp[N];
vector<pair<int, int>> qr[N];
int ans[N];

void dfs1(int u, int p) {
  anc[u][0] = p;
  for(int j = 1 ; (1 << j) < n ; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  for(int i = 0 ; i < (int)g[u].size() ; i++){
    int v = g[u][i];
    if(v != p){
      lev[v] = 1 + lev[u];
      dfs1(v, u);
      if(dp[v].size()) {
        Data tmp = dp[v][0];
        tmp.depth++;
        tmp.from = v;
        dp[u].push_back(tmp);
      } else {
        dp[u].push_back({v, 1, v});
      }
    }
  }
  sort(all(dp[u]));
  if(dp[u].size() > 2) {
    dp[u].resize(2);
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

int kth(int u, int k) {
  for(int l = L - 1; l >= 0; l--) {
    if(k & (1 << l)) {
      u = anc[u][l];
    }
  }
  return u;
}

int dist(int u, int v) {
  int lca = get_lca(u, v);
  if(lev[u] > lev[v]) {
    swap(u, v);
  }
  if(lca == u) {
    return lev[v] - lev[u];
  }
  return lev[u] + lev[v] - 2 * lev[lca];
}

void dfs(int u, int p, int f) {
  for(int i = 0; i < sz(qr[u]); i++) {
    int k = qr[u][i].second;
    int idx = qr[u][i].first;
    if(lev[u] >= k) {
      ans[idx] = kth(u, k);
    } else if(dp[u].size() && dp[u][0].depth >= k) {
      ans[idx] = kth(dp[u][0].node, dp[u][0].depth - k);
    } else if (f != -1) {
      int lca = get_lca(u, f);
      int d = dist(u, f);
      if(d >= k) {
        ans[idx] = kth(f, d - k);
      }
    }
  }
  for(int v: g[u]) {
    if (v == p) continue;
    int best = f;
    if (best == -1) {
      best = u;
    }
    int other = -1;
    for(auto d: dp[u]) {
      if(d.from != v) {
        other = d.node;
        break;
      }
    }
    if(dist(v, best) < dist(v, other)) {
      best = other;
    }
    dfs(v, u, best);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n - 1; i ++) {
    int a, b; cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs1(0, -1);

  int q; cin >> q;
  for(int i = 0; i < q; i++) {
    int u, k;
    cin >> u >> k;
    --u;
    qr[u].push_back({i, k});
  }

  memset(ans, -1, sizeof ans);
  dfs(0, -1, -1);

  for(int i = 0; i < q; i++) {
    if(ans[i] != -1) ans[i]++;
    cout << ans[i] << endl;
  }
  return 0;
}
