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

const int N = 2e5 + 5;

int n, k;
int deg[N];
Graph<N, 2 * N> g;

void bfs(const vector<int>& src, vector<int>& dist) {
  for(int i = 0; i < n; i++) {
    dist[i] = -1;
  }
  queue<int> q;
  for(int s: src) {
    dist[s] = 0;
    q.push(s);
  }
  while(!q.empty()) {
    int a = q.front(); q.pop();
    for(auto e: g.getNeighbors(a)) {
      int v = e.to;
      if(dist[v] == -1) {
        dist[v] = 1 + dist[a];
        q.push(v);
      }
    }
  }
}

void solve() {
  cin >> n >> k;
  g.init(n);
  memset(deg, 0, n * (sizeof deg[0]));
  vector<int> fr;
  for(int i = 0; i < k; i++) {
    int a; cin >> a; --a;
    fr.push_back(a);
  }
  for(int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    --a, --b;
    g.addEdge({a, b});
    g.addEdge({b, a});
    deg[a]++, deg[b]++;
  }
  vector<int> dist1(n), dist2(n);
  bfs({0}, dist1), bfs(fr, dist2);
  for(int i = 1; i < n; i++) {
    if(deg[i] == 1 && dist1[i] < dist2[i]) {
      cout << -1 << endl;
      return;
    }
  }
  int ans = 0;
  queue<int> q;
  q.push(0);
  vector<int> vis(n, 0);
  vis[0] = 1;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    if(dist1[u] >= dist2[u]) {
      ans++;
      continue;
    }
    for(auto e: g.getNeighbors(u)) {
      int v = e.to;
      if(!vis[v]) {
        vis[v] = 1;
        q.push(v);
      }
    }
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
