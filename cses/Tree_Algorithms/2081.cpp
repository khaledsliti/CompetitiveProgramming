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

int n, k1, k2;
vector<int> g[N];
int gone[N];
int sub[N];
int suff_lev[N], lev[N];

void dfs(int u, int p) {
  sub[u] = 1;
  for (int v : g[u]) {
    if (v == p || gone[v]) {
      continue;
    }
    dfs(v, u);
    sub[u] += sub[v];
  }
}

int getCentroid(int u, int p, int nodes) {
  for (int v : g[u]) {
    if (v == p || gone[v]) {
      continue;
    }
    if (2 * sub[v] > nodes) {
      return getCentroid(v, u, nodes);
    }
  }
  return u;
}

void add(int u, int p, int cur_lev, int val) {
  lev[cur_lev] += val;
  for (int v : g[u]) {
    if (v == p || gone[v]) {
      continue;
    }
    add(v, u, cur_lev + 1, val);
  }
}

long long get(int i, int j, int limit) {
  if (i > j || i >= limit) return 0;
  long long ret = suff_lev[i];
  if (j + 1 < limit) {
    ret -= suff_lev[j + 1];
  }
  return ret;
}

long long calc(int u, int p, int tot, int cur_lev) {
  int mn = max(0, k1 - cur_lev);
  int mx = max(0, k2 - cur_lev);
  long long ret = get(mn, mx, tot);
  for (int v : g[u]) {
    if (v == p || gone[v]) {
      continue;
    }
    ret += calc(v, u, tot, cur_lev + 1);
  }
  return ret;
}

long long paths(int root) {
  long long ret = 0;
  dfs(root, -1);
  int nodes = sub[root];
  root = getCentroid(root, -1, nodes);
  dfs(root, -1);
  for (int u : g[root]) {
    if (gone[u]) {
      continue;
    }
    ret += calc(u, root, nodes, 1);
    add(u, root, 1, 1);
    int s = 0;
    for (int i = sub[u]; i >= 0; i--) {
      s += lev[i];
      suff_lev[i] += s;
    }
    add(u, root, 1, -1);
  }
  ret += get(k1, k2, nodes);
  for (int i = 0; i < nodes; i++) {  // clean up
    suff_lev[i] = lev[i] = 0;
  }

  gone[root] = 1;
  for (int u : g[root]) {
    if (gone[u]) {
      continue;
    }
    ret += paths(u);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k1 >> k2;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }

  cout << paths(0) << endl;
  return 0;
}