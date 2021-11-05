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

const int N = 1e5 + 4, E = 2e5 + 5;

int n, tot;
int arr[N], sub[N];
Graph<N, E> g;

int dfs(int u, int p) {
  int best = INT_MAX;
  sub[u] = arr[u];
  for(auto e: g.getNeighbors(u)) {
    int v = e.to;
    if(v != p) {
      best = min(best, dfs(v, u));
      best = min(best, abs(tot - 2 * sub[v]));
      sub[u] += sub[v];
    }
  }
  return best;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    tot += arr[i];
  }
  g.init(n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g.addEdge({a, b});
    g.addEdge({b, a});
  }
  
  cout << dfs(0, -1) << endl;

  return 0;
}
