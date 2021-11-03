#pragma GCC target("popcnt")

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
      while(true) {
        int t = st.back(); st.pop_back();
        compOf[t] = ncomp;
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
    initialized = true;
  }
  void addEdge(Edge edge) {
    assert(initialized);
    nxt[e] = head[edge.from];
    head[edge.from] = e;
    edgeData[e++] = edge;
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
};

const int N = 5e4 + 2;
const int E = 1e5 + 3;


int n, m;
Graph<N, E> g, dag;
bitset<N> ans[N];
int in[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int qt;
  cin >> n >> m >> qt;
  g.init(n);
  while(m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g.addEdge({a, b});
  }

  g.scc();
  dag.init(g.getNumbOfComp());

  for(int i = 0; i < n; i++) {
    for(auto e: g.getNeighbors(i)) {
      int j = e.to;
      int a = g.getComp(i), b = g.getComp(j);
      if(a != b) {
        dag.addEdge({b, a});
        in[a]++;
      }
    }
  }

  queue<int> q;
  for(int i = 0; i < g.getNumbOfComp(); i++) {
    ans[i].set(i);
    if(in[i] == 0) {
      q.push(i);
    }
  }

  while(q.size()) {
    int u = q.front();
    q.pop();
    for(auto e: dag.getNeighbors(u)) {
      int v =  e.to;
      ans[v] |= ans[u];
      in[v]--;
      if(in[v] == 0) {
        q.push(v);
      }
    }
  }

  while(qt--) {
    int a, b;
    cin >> a >> b;
    a = g.getComp(--a);
    b = g.getComp(--b);
    if(ans[a][b]) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}
