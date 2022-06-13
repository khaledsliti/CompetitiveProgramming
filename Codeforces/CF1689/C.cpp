#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 3e5 + 5;

struct Node {
  int u, size;
  bool operator<(const Node& rhs) const {
    return size > rhs.size;
  }
};

int n;
vector<vector<int>> g;
int siz[N], par[N];
int dp[N];

void dfs(int u, int p) {
  par[u] = p;
  siz[u] = 0;
  for(int v: g[u]) {
    if(v != p) {
      dfs(v, u);
      siz[u] += 1 + siz[v];
    }
  }
}

int solve(int u) {
  if(dp[u] != -1) return dp[u];
  dp[u] = 0;
  vector<int> ch;
  for(int v: g[u]) {
    if(v != par[u]) {
      ch.push_back(v);
    }
  }
  if(sz(ch) == 1) {
    dp[u] = siz[ch[0]];
  } else if(sz(ch) == 2) {
    dp[u] = max(siz[ch[0]] + solve(ch[1]), siz[ch[1]] + solve(ch[0]));
  }
  return dp[u];
}

void solve() {
  cin >> n;
  g.clear(); g.resize(n);
  for(int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  for(int i = 0; i < n; i++) {
    dp[i] = -1;
  }
  cout << solve(0) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
