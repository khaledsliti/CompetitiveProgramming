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

const int N = 1e5 + 5, E = 4e5 + 5;
const int Mod = 1e9 + 7;

int n, m;
Graph<N, E> g;
int vis[N];

int dfs(int u, int p) {
  vis[u] = 1;
  int cnt = 0;
  for(auto e: g.getNeighbors(u)) {
    int v = e.to;
    if(v != p) {
      if(!vis[v]) cnt += dfs(v, u);
      else if(vis[v] == 1) cnt++;
    }
  }
  vis[u] = 2;
  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  g.init(n);
  memset(vis, 0, sizeof vis);
  while(m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g.addEdge({a, b});
    g.addEdge({b, a});
  }
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      cnt += dfs(i, -1);
    }
  }
  int ans = 1;
  while(cnt--) ans *= 2, ans %= Mod;
  cout << ans << endl;
  return 0;
}
