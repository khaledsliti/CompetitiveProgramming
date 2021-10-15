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

const int N = 2e5 + 5;
const int K = 11;

struct Edge {
  int from, to;
  friend ostream& operator<<(ostream& cout, const Edge& e) {
    cout << "(" << e.from << ", " << e.to << ")"; 
    return cout;
  }
};

template<typename T>
class Graph {
  bool initialized = false;
  int n;
  vector<int> head, nxt;
  vector<T> edgeData;
  vector<int> idx, low, compOf;
  stack<int> st;
  int ncomp, cur_idx;

  template<typename V>
  void resize(vector<V>& vec, int s, V v = V()) {
    vec.clear(); vec.resize(s, v);
  }
  void memset(vector<int>& v, int n, int val) {
    for(int i = 0; i < n; i++)
      v[i] = val;
  }

  void dfs(int u) {
    idx[u] = low[u] = ++cur_idx;
    st.push(u);
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
      while(true) {
        int t = st.top(); st.pop();
        compOf[t] = ncomp;
        if(t == u) break;
      }
      ncomp++;
    }
  }

public:
  Graph(int cap) {
    resize(head, cap, -1);
    nxt.clear();
    edgeData.clear();
    resize(idx, cap);
    resize(low, cap);
    resize(compOf, cap);
  }
  void init(int n) {
    this-> n = n;
    memset(head, n, -1);
    nxt.clear();
    edgeData.clear();
    initialized = true;
  }
  void addEdge(T e) {
    assert(initialized);
    nxt.push_back(head[e.from]);
    head[e.from] = nxt.size() - 1;
    edgeData.push_back(e);
  }
  vector<T> getNeighbors(int u) {
    vector<T> adj;
    for(int k = head[u]; ~k; k = nxt[k]) {
      adj.push_back(edgeData[k]);
    }
    return adj;
  }
  void print() {
    for(int i = 0; i < n; i++) {
      cout << i << ": ";
      for(T e: getNeighbors(i)) {
        cout << e << " ";
      }
      cout << endl;
    }
  }
  void scc() {
    memset(idx, n, -1);
    memset(compOf, n, -1);
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
  Graph<T> getDAG() {
    Graph<T> g(n);
    g.init(n);
    set<pair<int, int>> ed;
    for(int u = 0; u < n; u++) {
      for(auto e: getNeighbors(u)) {
        if(compOf[e.from] != compOf[e.to]) {
          ed.insert({compOf[e.from], compOf[e.to]});
        }
      }
    }
    for(auto e: ed) {
      g.addEdge({e.first, e.second});
    }
    return g;
  }
  int getHead(int u) const { return head[u]; }
  int getNxt(int e) const { return nxt[e]; }
  int getTo(int e) const { return edgeData[e].to; }
};

long long dp[N][K];
long long cost[N];

long long solve(const Graph<Edge>& g, int edge, int rem) {
  if(rem == 0 || edge == -1) return 0;
  long long& r = dp[edge][rem];
  if(r != -1) return r;
  r = solve(g, g.getNxt(edge), rem);
  for(int i = 1; i <= rem; i++) {
    int to = g.getTo(edge);
    r = max(r, cost[to] + solve(g, g.getHead(to), i) + solve(g, g.getNxt(edge), rem - i));
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  Graph<Edge> g(n);
  g.init(n);

  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g.addEdge({u, v});
  }

  vector<int> cost(n);
  for(int i = 0; i < n; i++) {
    cin >> cost[i];
  }

  g.scc();
  for(int i = 0; i < n; i++) {
    cost[g.getComp(i)] += cost[i];
  }

  Graph<Edge> dag = g.getDAG();
  memset(dp, -1, sizeof dp);

  int src = g.getComp(0);
  cout << solve(dag, dag.getHead(src), k) << endl;

  cout << cost[src] + solve(dag, dag.getHead(src), k) << endl;
  return 0;
}
