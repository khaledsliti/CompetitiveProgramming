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

const int N = 2e3 + 3;
const int L = 11;

int n;
string s;
vector<int> g[N];
int adj[N][N];
int anc[N][L], lev[N];
int dp[N][N];

void dfs1(int u, int p) {
  anc[u][0] = p;
  for (int j = 1; j < L; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (v != p) {
      lev[v] = 1 + lev[u];
      dfs1(v, u);
    }
  }
}

int get_lca(int a, int b) {
  if (lev[a] < lev[b]) swap(a, b);
  int lg = 0;
  for (; (1 << lg) <= lev[a]; lg++)
    ;
  lg--;
  for (int i = lg; i >= 0; i--)
    if (lev[a] - (1 << i) >= lev[b]) a = anc[a][i];
  if (a == b) return a;
  for (int i = lg; i >= 0; i--)
    if (anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
  return anc[a][0];
}

int get_kth(int a, int k) {
  int lg = 0;
  for (; (1 << lg) <= k; lg++)
    ;
  lg--;
  for(int i = lg; i >= 0; i--) {
    if(k & (1 << i)) {
      a = anc[a][i];
    }
  }
  return a;
}

int to(int a, int b) {
  int lca = get_lca(a, b);
  if(lca == a) {
    return get_kth(b, lev[b] - lev[a] - 1);
  }
  return anc[a][0];
}

int solve(int i, int j) {
  if(i == j) {
    return 1;
  }
  if(adj[i][j]) {
    if (s[i] == s[j]) {
      return 2;
    }
    return 1;
  }
  int& r = dp[i][j];
  if(r != -1) {
    return r;
  }
  if(s[i] == s[j]) {
    return r = 2 + solve(to(i, j), to(j, i));
  }
  r = solve(to(i, j), j);
  r = max(r, solve(i, to(j, i)));
  return r;
}

void solve() {
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    g[i].clear();
    for(int j = 0; j < n; j++) {
      adj[i][j] = 0;
    }
  }
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
    adj[a][b] = adj[b][a] = 1;
  }
  dfs1(0, -1);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      dp[i][j] = -1;
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      ans = max(ans, solve(i, j));
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
