// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

struct Edge {
  int from, to, cost;
  friend ostream& operator<<(ostream& cout, const Edge& e) {
    cout << "(" << e.from << ", " << e.to << ", " << e.cost << ")"; 
    return cout;
  }
};

template<typename T>
struct Graph {
  int n, e;
  vector<int> head, nxt;
  vector<T> edgeData;
  Graph(int _n): n(_n), e(0) {
    head.resize(n, -1);
  }
  void addEdge(T e) {
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
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  Graph<Edge> g(n);
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g.addEdge({a, b, c});
  }
  vector<int> vis(n, 0);
  priority_queue<pair<ll, int>> pq;
  pq.push({0, 0});
  vector<long long> sol;
  while(!pq.empty()) {
    int u = pq.top().second;
    ll uc = -pq.top().first;
    pq.pop();
    if(vis[u] >= k) continue;
    vis[u]++;
    if(u == n - 1)
      sol.push_back(uc);
    for(auto e: g.getNeighbors(u)) {
      int v, cost;
      tie(v, cost) = {e.to, e.cost};
      if(vis[v] >= k) continue;
      pq.push({-uc - cost, v});
    }
  }
  for(auto x: sol)
    cout << x << " ";
  cout << endl;
  return 0;
}
