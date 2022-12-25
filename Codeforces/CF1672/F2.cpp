#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
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

struct Edge {
  int from, to;
  friend ostream& operator<<(ostream& cout, const Edge& e) {
    cout << "(" << e.from << ", " << e.to << ")"; 
    return cout;
  }
};

template<int V, int E>
class Graph {
  bool initialized = false;
  int n, e;
  int head[V], nxt[E];
  Edge edgeData[E];
  int idx[V], low[V], compOf[V];
  vector<int> st;
  int ncomp, cur_idx;
  int comp_size[V];
  int cnt[V];

  void dfs(int u) {
    idx[u] = low[u] = ++cur_idx;
    st.push_back(u);
    for(auto e: getNeighbors(u)) {
      int v = e.to;
      if(idx[v] == -1) { // Gray to White
        dfs(v);
        low[u] = min(low[u], low[v]);
      } else if(compOf[v] == -1) { // Gray to gray
        low[u] = min(low[u], low[v]);
      }
    }
    if(low[u] == idx[u]) {
      comp_size[ncomp] = 0;
      while(true) {
        int t = st.back(); st.pop_back();
        compOf[t] = ncomp;
        comp_size[ncomp] += cnt[t];
        if(t == u) break;
      }
      ncomp++;
    }
  }

public:
  void init(int n) {
    this-> n = n;
    e = 0;
    memset(head, -1, n * sizeof(head[0]));
    memset(cnt, -1, n * sizeof(cnt[0]));
    initialized = true;
  }
  void addEdge(Edge edge) {
    assert(initialized);
    nxt[e] = head[edge.from];
    head[edge.from] = e;
    edgeData[e++] = edge;
    cnt[edge.from]++;
  }
  vector<Edge> getNeighbors(int u) {
    vector<Edge> adj;
    for(int k = head[u]; ~k; k = nxt[k]) {
      adj.push_back(edgeData[k]);
    }
    return adj;
  }
  void print() {
    for(int i = 0; i < n; i++) {
      cout << i << ": ";
      for(Edge e: getNeighbors(i)) {
        cout << e << " ";
      }
      cout << endl;
    }
  }
  void scc() {
    memset(idx, -1, n * sizeof(idx[0]));
    memset(compOf, -1, n * sizeof(compOf[0]));
    ncomp = cur_idx = 0;
    for(int i = 0 ; i < n ; i++)
      if(idx[i] == -1) {
        dfs(i);
      }
  }
  int getComp(int u) {
    return compOf[u];
  }
  int getNumbOfComp() {
    return ncomp;
  }
  int solve() {
    int ans = 0;
    for(int i = 0; i < ncomp; i++) {
      ans += comp_size[i] - 1;
    }
    for(int i = 0; i < n; i++) {
      ans -= cnt[i] - 1;
    }
    return ans;
  }
};

int n;
Graph<N, N> g;

struct Calc {
  int ans;
  Calc(const vector<int>&a, const vector<int>& b) {
    g.init(n);
    for(int i = 0; i < n; i++) {
      if(a[i] != b[i]) {
        g.addEdge({a[i] - 1, b[i] - 1});
      }
    }
    g.scc();
    ans = g.solve();
  }
};

void solve() {
  cin >> n;
  vector<int> a(n), deg(n + 1, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    deg[a[i]]++;
  }
  vector<int> b(n);
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> freq = deg;
  vector<int> nodes;
  for(int i = 1; i <= n; i++) {
    if(deg[i]) {
      nodes.push_back(i);
    }
  }
  vector<vector<int>> nxt(n + 1);
  while(sz(nodes)) {
    for(int i = 0; i < sz(nodes); i++) {
      int x = nodes[i], y = nodes[(i + 1) % sz(nodes)];
      nxt[x].push_back(y);
      deg[x]--;
    }
    vector<int> tmp;
    for(int x: nodes) {
      if(deg[x]) {
        tmp.push_back(x);
      }
    }
    swap(nodes, tmp);
  }
  vector<int> ans;
  for(int i = 0; i < n; i++) {
    if(sz(nxt[a[i]])) {
      ans.push_back(nxt[a[i]].back());
      nxt[a[i]].pop_back();
    } else {
      ans.push_back(a[i]);
    }
  }
  auto A = Calc(a, b);
  auto B = Calc(a, ans);
  if(A.ans == B.ans) cout << "AC" << endl;
  else cout << "WA" << endl;
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
