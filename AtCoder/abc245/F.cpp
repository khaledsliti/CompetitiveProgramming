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

struct Edge {
  int from, to;
  friend ostream& operator<<(ostream& cout, const Edge& e) {
    cout << "(" << e.from << ", " << e.to << ")"; 
    return cout;
  }
};

template<int V, int E>
struct Graph {
  bool initialized = false;
  int n, e;
  int head[V], nxt[E];
  Edge edgeData[E];
  int idx[V], low[V], compOf[V];
  vector<int> st;
  int ncomp, cur_idx;
  int good[V];

  void dfs(int u) {
    idx[u] = low[u] = ++cur_idx;
    st.push_back(u);
    for(int k = head[u]; ~k; k = nxt[k]) {
      int v = edgeData[k].to;
      if(idx[v] == -1) { // Gray to White
        dfs(v);
        low[u] = min(low[u], low[v]);
      } else if(compOf[v] == -1) { // Gray to gray
        low[u] = min(low[u], low[v]);
      }
    }
    if(low[u] == idx[u]) {
      int c_sz = 0;
      while(true) {
        c_sz++;
        int t = st.back(); st.pop_back();
        compOf[t] = ncomp;
        if(t == u) break;
      }
      good[ncomp] = c_sz > 1;
      ncomp++;
    }
  }
  void init(int n) {
    this-> n = n;
    e = 0;
    memset(head, -1, n * sizeof(head[0]));
    initialized = true;
  }
  void addEdge(Edge edge) {
    assert(initialized);
    nxt[e] = head[edge.from];
    head[edge.from] = e;
    edgeData[e++] = edge;
  }
  void scc() {
    memset(idx, -1, n * sizeof(idx[0]));
    memset(compOf, -1, n * sizeof(compOf[0]));
    ncomp = cur_idx = 0;
    for(int i = 0 ; i < n ; i++) {
      if(idx[i] == -1) {
        dfs(i);
      }
    }
  }
};

int n, m, e;
Graph<N, N> g;
int nn;
set<int> tree[N];
int in[N];
int dp[N];

int dfs(int u) {
  if (dp[u] != -1) return dp[u];
  dp[u] = g.good[u];
  for(int v: tree[u]) {
    if (dfs(v)) {
      dp[u] = 1;
    }
  }
  return dp[u];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  g.init(n);
  while(m-- > 0) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g.addEdge({a, b});
  }
  g.scc();

  nn = g.ncomp;
  for(int i = 0; i < n; i++) {
    for(int k = g.head[i]; ~k; k = g.nxt[k]) {
      int j = g.edgeData[k].to;
      int a = g.compOf[i], b = g.compOf[j];
      if(a != b) {
        tree[a].insert(b);
        in[b] = 1;
      }
    }
  }

  memset(dp, -1, sizeof dp);
  for(int i = 0; i < nn; i++) {
    if(in[i] == 0) {
      dfs(i);
    }
  }

  int cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt += dp[g.compOf[i]];
  }
  cout << cnt << endl;

  return 0;
}
