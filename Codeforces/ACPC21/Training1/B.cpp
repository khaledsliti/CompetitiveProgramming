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
  long long cost;
  friend ostream& operator<<(ostream& cout, const Edge& e) {
    cout << "(" << e.from << ", " << e.to << ")"; 
    return cout;
  }
};

const long long INF = 1e18;
const int K = 104;

template<int V, int E>
class Graph {
  int n, e;
  int head[V], nxt[E];
  Edge edgeData[E];
  bool initialized = false;

  long long dp[E][K];

  long long solve(int k, int rem) {
    if(k == -1) {
      return rem == 0 ? 0 : -INF;
    }
    long long& r = dp[k][rem];
    if(r != -1) {
      return r;
    }
    long long cost = edgeData[k].cost;
    int to = edgeData[k].to;
    r = solve(nxt[k], rem);
    for(int take = 1; take <= rem; take++) {
      r = max(r, cost + solve(head[to], take - 1) + solve(nxt[k], rem - take));
    }
    return r;
  }

public:
  void init(int n) {
    e = 0;
    this->n = n;
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
  long long solve(int k) {
    for(int i = 0; i < e; i++) {
      for(int j = 0; j <= k; j++) {
        dp[i][j] = -1;
      }
    }
    long long best = -1;
    for(int i = 0; i < n; i++) {
      best = max(best, solve(head[i], k - 1));
    }
    return best;
  }
};

const int N = 1004;

int n, k;
Graph<N, N> g;
vector<pair<int, int>> adj[N];

void dfs(int u, int p) {
  for(auto e: adj[u]) {
    if(e.first != p) {
      g.addEdge({u, e.first, e.second});
      dfs(e.first, u);
    }
  }
}

void solve() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    adj[i].clear();
  }
  for(int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    adj[a].pb({b, c});
    adj[b].pb({a, c});
  }
  g.init(n);
  dfs(0, -1);
  cout << g.solve(k) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifndef LOCAL
  freopen("hackathon.in", "r", stdin);
#endif

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}