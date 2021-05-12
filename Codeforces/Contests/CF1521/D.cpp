// Guess Who's Back
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

const int N = 1e5 + 5;

int n;
vector<int> g[N];
int dp[N][2];
int par[N], deg[N];
vector<int> to_keep[N][3];
vector<pair<int, int>> to_remove, to_add;
vector<int> end_point[N];

int fs(int x) { return par[x] == x ? x : par[x] = fs(par[x]); }

void uni(int a, int b) {
  a = fs(a), b = fs(b);
  if(a == b) return;
  par[a] = b;
}

void dfs(int u, int par) {
  vector<int> children;
  for(int v: g[u]) {
    if(v != par) {
      children.push_back(v);
      dfs(v, u);
    }
  }
  int len = sz(children);
  vector<vector<int>> mini(len + 1, vector<int>(3));
  mini[len][0] = mini[len][1] = mini[len][2] = 0;
  for(int i = len - 1; i >= 0; i--) {
    int v = children[i];
    for(int j = 0; j <= 2; j++) {
      mini[i][j] = mini[i + 1][j] + 1 + dp[v][0];
      if(j > 0) mini[i][j] = min(mini[i][j], mini[i + 1][j - 1] + dp[v][1]);
    }
  }
  dp[u][0] = mini[0][2];
  dp[u][1] = mini[0][1];

  int can = 2;
  for(int i = 0; i < len; i++) {
    if(mini[i][can] != 1 + dp[children[i]][0] + mini[i + 1][can]) {
      can--;
      to_keep[u][0].push_back(children[i]);
    }
  }

  can = 1;
  for(int i = 0; i < len; i++) {
    if(mini[i][can] != 1 + dp[children[i]][0] + mini[i + 1][can]) {
      can--;
      to_keep[u][1].push_back(children[i]);
    }
  }
}

void trace(int u, int par, int hasPar) {
  // debug(u, hasPar);
  for(int v: g[u]) {
    if(v == par) continue;
    bool should_keep = find(all(to_keep[u][hasPar]), v) != end(to_keep[u][hasPar]);
    // debug(u, v, should_keep);
    if(should_keep) {
      deg[u]++;
      deg[v]++;
      uni(u, v);
      trace(v, u, 1);
    } else {
      to_remove.push_back({u + 1, v + 1});
      trace(v, u, 0);
    }
  }
}

void init() {
  for(int i = 0; i < n; i++) {
    g[i].clear(); end_point[i].clear();
    par[i] = i;
    deg[i] = 0;
    for(int j = 0; j < 3; j++) {
      to_keep[i][j].clear();
    }
  }
  to_add.clear();
  to_remove.clear();
}

void solve() {
  scanf("%d", &n);
  init();
  for(int it = 0; it < n - 1; it++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);

  // for(int i = 0; i < n; i++) {
  //   cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
  //   debug(to_keep[i][0]);
  //   debug(to_keep[i][1]);
  // }

  trace(0, -1, 0);

  // for(int i = 0; i < n; i++) {
  //   debug(i, deg[i]);
  // }

  for(int i = 0; i < n; i++) {
    if(deg[i] <= 1) {
      end_point[fs(i)].push_back(i);
    }
    if(deg[i] <= 0) {
      end_point[fs(i)].push_back(i);
    }
  }
  vector<int> nodes;
  for(int i = 0; i < n; i++) {
    if(fs(i) == i && end_point[i].size() > 0) {
      nodes.push_back(i);
    }
  }

  while(sz(nodes) >= 2) {
    int u = nodes.back(); nodes.pop_back();
    int v = nodes.back();

    int a = end_point[u].back();
    end_point[u].pop_back();
    int b = end_point[v].back();
    end_point[v].pop_back();
    to_add.push_back({a + 1, b + 1});
  }

  assert(sz(to_remove) == sz(to_add));

  // for(int i = 0; i < sz(to_remove); i++)
  //   cout << to_remove[i].first << " " << to_remove[i].second << endl;

  printf("%d\n", sz(to_remove));
  for(int i = 0; i < sz(to_remove); i++) {
    printf("%d %d %d %d\n", to_remove[i].first, to_remove[i].second, to_add[i].first, to_add[i].second);
  }
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
