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

const int N = 1e5;
const int E = 1e6;
const int oo = 1e9;

struct MinCostFlow {
  int n, e;
  int head[N], to[E], nxt[E], cap[E], cost[E];
  int src, snk;
  int pre[N], mem[N];
  int dist[N];

  void init(int _n) {
    n = _n;
    e = 0;
    memset(head, -1, n * (sizeof head[0]));
  }

  void addEdge(int f, int t, int _cap,int _cost)
  {
    nxt[e] = head[f];
    head[f] = e;
    cap[e] = _cap;
    cost[(e)] = _cost;
    to[e++] = t;
  }

  void addAugEdge(int f, int t, int _cap,int _cost)
  {
    addEdge(f, t, _cap, _cost);
    addEdge(t, f, 0, -_cost);
  }

  int cur_flow;

  int bellman()
  {
    for(int i = 0; i < n; i++)
      dist[i] = oo;
    dist[src] = 0;
    bitset<N> inq;
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      inq[u] = false;
      for(int k = head[u]; ~k ; k = nxt[k]) {
        int v = to[k];
        if(cap[k] > 0 && dist[v] > dist[u] + cost[k]) {
          dist[v] = dist[u] + cost[k];
          pre[v] = u, mem[v] = k;
          if(!inq[v]) {
            inq[v] = true;
            q.push(v);
          }
        }
      }
    }
    if(dist[snk] == oo)
      return -1;
    cur_flow = oo;
    for(int cur = snk; cur != src; cur = pre[cur]){
      ll ri = mem[cur];
      cur_flow = min(cur_flow, cap[ri]);
    }
    for(int cur = snk; cur != src; cur = pre[cur]){
      ll ri = mem[cur];
      cap[ri] -= cur_flow;
      cap[ri^1] += cur_flow;
    }
    return dist[snk];
  }

  int maxFlow()
  {
    int c;
    int cost = 0, flow = 0;
    while((c=bellman()) != -1){
      cost += c;
      flow += cur_flow;
    }
    return cost;
  }
};

MinCostFlow graph;

int main()
{
  freopen("fans.in", "r", stdin);
  freopen("fans.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a[3];
  vector<int> h(n);
  for(int i = 0; i < n; i++) {
    int t;
    cin >> h[i] >> t;
    a[t].push_back(h[i]);
  }
  int f = 0;
  int ans = 0;
  for(int idx: {1, 0, 2}) {
    vector<int> x, y;
    for(int i = 0; i < sz(a[idx]); i++) {
      x.push_back(a[idx][i]);
      y.push_back(h[f++]);
    }
    int _n = sz(x) + sz(y) + 2;
    
    graph.init(_n);
    for(int i = 0; i < sz(x); i++) {
      for(int j = 0; j < sz(y); j++) {
        graph.addAugEdge(i + 1, sz(x) + 1 + j, 1, x[i] > y[j] ? x[i] : 0);
      }
    }
    for(int i = 0; i < sz(x); i++) {
      graph.addAugEdge(0, i + 1, 1, 0);
    }
    for(int i = 0; i < sz(y); i++) {
      graph.addAugEdge(sz(x) + 1 + i, _n - 1, 1, 0);
    }
    graph.src = 0;
    graph.snk = _n - 1;

    int cur = graph.maxFlow();

    ans += cur;
  }

  cout << ans << endl;
  return 0;
}
