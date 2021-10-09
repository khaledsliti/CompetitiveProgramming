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

const int N = 5e5 + 5;

int n;
int par[N], siz[N];
int nodes = 0;
map<int, int> id, rev_id;
vector<pair<int, int>> edges;
vector<vector<int>> g;
vector<int> color;

int getNode(int x) {
  if(id.count(x) == 0) {
    rev_id[nodes] = x;
    id[x] = nodes++;
  }
  return id[x];
}

int fs(int x) { return x == par[x] ? x : par[x] = fs(par[x]); }

void un(int a, int b) {
  a = fs(a), b = fs(b);
  if(a != b) {
    par[a] = b;
    siz[b] += siz[a];
  }
}

int getSize(int x) {
  return siz[fs(rev_id[x])];
}

bool bad;
void dfs(int u, int& a, int& b, int t) {
  color[u] = t;
  if(t == 0) {
    a += getSize(u);
  } else {
    b += getSize(u);
  }
  for(int v: g[u]) {
    if(color[v] == -1) {
      dfs(v, a, b, t ^ 1);
    } else if(color[v] == color[u]) {
      bad = true;
    }
  }
}

void solve() {
  int m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    par[i] = i;
    siz[i] = 1;
  }
  nodes = 0;
  id.clear();
  rev_id.clear();
  edges.clear();
  while(m--) {
    int a, b;
    string s;
    cin >> a >> b >> s;
    if(s[0] == 'i') {
      edges.push_back({--a, --b});
    } else {
      un(--a, --b);
    }
  }
  for(int i = 0; i < n; i++) {
    if(fs(i) == i) {
      getNode(i);
    }
  }
  g.clear();
  g.resize(nodes);
  for(int i = 0; i < sz(edges); i++) {
    int a = edges[i].first;
    int b = edges[i].second;
    a = fs(a), b = fs(b);
    if(a == b) {
      cout << -1 << endl;
      return;
    }
    a = getNode(a), b = getNode(b);
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for(int i = 0; i < nodes; i++) {
    sort(all(g[i]));
    g[i].resize(unique(all(g[i])) - begin(g[i]));
  }
  int ans = 0;
  color.clear(); color.resize(nodes, -1);
  bad = false;
  for(int i = 0; i < nodes; i++) {
    if(color[i] == -1) {
      int a = 0, b = 0;
      dfs(i, a, b, 0);
      ans += max(a, b);
    }
  }
  if(bad) {
    ans = -1;
  }
  cout << ans << endl;
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
