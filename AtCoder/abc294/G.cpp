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

// Region Debug
string to_string(const string &s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template<typename A, typename B>
string to_string(const pair<A, B>& p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template<typename T>
string to_string(const vector<T>& v) {
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (i > 0)
      res += ", ";
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first)
      res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template<typename A, typename B>
string to_string(const pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// End Region

const int N = 2e5 + 5;

struct segTree {
  int n;
  vector<long long> st;
  segTree(const vector<long long>& vals) {
    n = sz(vals);
    st.resize(sz(vals) * 4);
    build(0, 0, n - 1, vals);
  }
  void build(int cur, int s, int e, const vector<long long>& vals) {
    if (s == e) {
      st[cur] = vals[s];
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    build(l, s, mid, vals);
    build(r, mid + 1, e, vals);
    st[cur] = st[l] + st[r];
  }
  void update(int cur, int s, int e, int i, long long w) {
    if (s > i || e < i) { 
      return;
    }
    if (s == e) {
      st[cur] = w;
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    update(l, s, mid, i, w);
    update(r, mid + 1, e, i, w);
    st[cur] = st[l] + st[r];
  }
  long long query(int cur, int s, int e, int i, int j) {
    if (s > j || e < i) {
      return 0;
    }
    if (s >= i && e <= j) {
      return st[cur];
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    return query(l, s, mid, i, j) + query(r, mid + 1, e, i, j);
  }
  long long query(int i, int j) {
    return query(0, 0, n - 1, i, j);
  }
};

int n;
int par[N], subsz[N], lev[N];
int cost[N];
vector<int> g[N];

int chainNo = 0;
int chainHead[N], chainPos[N], chainInd[N], chainSize[N];
vector<vector<int>> chain;
vector<segTree> trees;

int headOf(int u) {
  return chainHead[chainInd[u]];
}

void pre_dfs(int u, int p) {
  par[u] = p;
  subsz[u] = 1;
  for (int v : g[u]) {
    if (v != p) {
      lev[v] = 1 + lev[u];
      pre_dfs(v, u);
      subsz[u] += subsz[v];
    }
  }
}

void hld(int u, int p) {
  if (chainHead[chainNo] == -1) {
    chainHead[chainNo] = u;
    chain.push_back(vector<int>());
  }
  chainInd[u] = chainNo;
  chainPos[u] = chainSize[chainNo]++;
  chain.back().push_back(u);
  int M = 0, At = -1;
  for (int v : g[u]) {
    if (v != p && subsz[v] > M) {
      M = subsz[v];
      At = v;
    }
  }
  if (At != -1) {
    hld(At, u);
  }
  for (int v : g[u]) {
    if (v != p && v != At) {
      chainNo++;
      hld(v, u);
    }
  }
}

void update(int u, int w) {
  int ch = chainInd[u];
  int idx = chainPos[u];
  trees[ch].update(0, 0, chainSize[ch] - 1, idx, w);
}

long long query(int u, int v) {
  long long ret = 0;
  for (; headOf(u) != headOf(v); v = par[headOf(v)]) {
    if (lev[headOf(u)] > lev[headOf(v)]) {
      swap(u, v);
    }
    ret += trees[chainInd[v]].query(chainPos[headOf(v)], chainPos[v]);
  }
  if (lev[u] > lev[v]) {
    swap(u, v);
  }
  if (chainPos[u] != chainPos[v]) {
    ret += trees[chainInd[u]].query(chainPos[u] + 1, chainPos[v]);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<vector<int>> edges;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    edges.push_back({u, v, w});
    g[u].push_back(v);
    swap(u, v);
    g[u].push_back(v);
  }

  pre_dfs(0, -1);
  for (int i = 0; i < n - 1; i++) {
    if (edges[i][0] != par[edges[i][1]]) {
      swap(edges[i][0], edges[i][1]);
    }
    cost[edges[i][1]] = edges[i][2];
  }
  memset(chainHead, -1, sizeof chainHead);
  hld(0, -1);
  for(int i = 0; i < sz(chain); i++) {
    vector<long long> vals;
    for (int u : chain[i]) {
      vals.push_back(cost[u]);
    }
    trees.push_back(segTree(vals));
  }

  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, w;
      cin >> x >> w;
      int u = edges[--x][1];
      update(u, w);
      continue;
    }
    int u, v;
    cin >> u >> v;
    cout << query(--u, --v) << endl;
  }
  return 0;
}
