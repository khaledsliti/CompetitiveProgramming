// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1e5 + 6;

int n;
vector<int> g[N];
int mx[N], lev[N];
int ans[N];
int sol[N];

void dfs(int u, int p) {
  mx[u] = 0;
  for (int v : g[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    mx[u] = max(mx[u], 1 + mx[v]);
  }
}

void dfs2(int u, int p, int fromPar) {
  ans[u] = max(mx[u], fromPar);
  vector<int> ch;
  for (int v : g[u]) {
    if (v == p) {
      ch.push_back(0);
      continue;
    }
    ch.push_back(mx[v]);
  }
  vector<int> left(sz(ch));
  for (int i = 0; i < sz(ch); i++) {
    left[i] = ch[i];
    if (i > 0) {
      left[i] = max(left[i - 1], left[i]);
    }
  }
  vector<int> right(sz(ch));
  for (int i = sz(ch) - 1; i >= 0; i--) {
    right[i] = ch[i];
    if (i + 1 < sz(ch)) {
      right[i] = max(right[i], right[i + 1]);
    }
  }
  for (int i = 0; i < sz(g[u]); i++) {
    int v = g[u][i];
    if (v == p) {
      continue;
    }
    int nw = fromPar + 1;
    if (i > 0) {
      nw = max(nw, 2 + left[i - 1]);
    }
    if (i + 1 < sz(ch)) {
      nw = max(nw, 2 + right[i + 1]);
    }
    dfs2(v, u, nw);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  dfs2(0, -1, 0);
  // for (int i = 0; i < n; i++) {
  //   cout << i + 1 << " " << ans[i] << endl;
  // }

  for (int i = 0; i < n; i++) {
    sol[ans[i] + 1]++;
  }

  sol[1] = 1;
  for (int i = 2; i <= n; i++) {
    sol[i] += sol[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cout << min(sol[i], n) << " ";
  }
  cout << endl;
  return 0;
}
