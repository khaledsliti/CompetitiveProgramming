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
  int n, e;
  int head[V], nxt[E];
  Edge edgeData[E];
  bool initialized = false;
public:
  void init(int n) {
    e = 0;
    memset(head, -1, n * sizeof(head[0]));
    initialized = true;
  }
  void addEdge(Edge edge) {
    assert(initialized);
    nxt[e] = head[edge.from];
    head[edge.from] = e;
    edgeData[e] = edge;
    e++;
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
};

struct DSU {
  vector<int> par;
  void init(int n) {
    par.clear();
    par.resize(n);
    iota(par.begin(), par.end(), 0);
  }
  int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
      par[x] = y;
      return true;
    }
    return false;
  }
};

const int N = 2e5 + 5;

int n, m;
Graph<N, 2 * N> g;
int ans[N];
DSU dsu;
int comp;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  g.init(n);
  dsu.init(n);
  while(m--) {
    int a, b; cin >> a >> b; --a, --b;
    g.addEdge({a, b});
    g.addEdge({b, a});
  }
  comp = 0;
  for(int i = n - 1; i >= 0; i--) {
    ans[i] = comp;
    comp++;
    for(auto e: g.getNeighbors(i)) {
      int j = e.to;
      if(j > i && dsu.unite(i, j)) {
        comp--;
      }
    }
  }
  for(int i = 0; i < n; i++)
    cout << ans[i] << endl;
  return 0;
}
