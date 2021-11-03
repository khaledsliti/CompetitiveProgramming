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
  int idx[V], low[V], cur_idx;
  vector<Edge> bridges;
  int isArticulation[V];
  int root, children;

  void dfs(int u, int p) {
    idx[u] = low[u] = cur_idx++;
    for(auto e: getNeighbors(u)) {
      int v = e.to;
      if(idx[v] == -1) {
        dfs(v, u);
        if(u == root) {
          children++;
        }
        low[u] = min(low[u], low[v]);
        if(low[v] > idx[u]) bridges.push_back(e);
        if(low[v] >= idx[u]) isArticulation[u] = 1;
      } else if(v != p) {
        low[u] = min(low[u], idx[v]);
      }
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
  void calcBridgesAndArticulation() {
    cur_idx = 0;
    memset(idx, -1, n * sizeof(idx[0]));
    memset(isArticulation, 0, n * sizeof(isArticulation[0]));
    bridges.clear();
    for(int i = 0; i < n; i++) {
      if(idx[i] == -1) {
        root = i;
        children = 0;
        dfs(i, -1);
        isArticulation[i] = children > 1;
      }
    }
  }
  vector<Edge> getBridges() {
    return bridges;
  }
  vector<int> getArticulations() {
    vector<int> articulations;
    for(int i = 0; i < n; i++) {
      if(isArticulation[i]) {
        articulations.push_back(i);
      }
    }
    return articulations;
  }
};

const int N = 1e5 + 5;
const int E = 4e5 + 5;

int n, m;
Graph<N, E> g;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  g.init(n);
  while(m--) {
    int a, b;
    cin >> a >> b;
    g.addEdge({--a, --b});
    g.addEdge({b, a});
  }
  g.calcBridgesAndArticulation();
  auto articulations = g.getArticulations();
  cout << articulations.size() << endl;
  for(auto node: articulations) {
    cout << node + 1 << " ";
  }
  cout << endl;
  return 0;
}
