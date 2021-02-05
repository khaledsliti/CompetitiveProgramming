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

const int N = 50 + 50 + 5, E = 2 * (50 + 50 + 50 * 50) + 5;
const int oo = 1e9;

int n, m;
int a[50][50];

struct MaxFlow {
  int n, e;
  int head[N], to[E], nxt[E], cap[E], cost[E];
  int src,snk;
  int pre[N], mem[N];
  int dist[N];

  void init() {
    e = 0;
    memset(head, -1, n * (sizeof head[0]));
  }

  void addEdge(int f, int t, int _cap,int _cost)
  {
    nxt[e] = head[f];
    head[f] = e;
    cap[e] = _cap;
    cost[(e)] = -_cost;
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
      return oo;
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

  pair<int, int> maxFlow()
  {
    int c;
    int cost = 0, flow = 0;
    while((c=bellman()) != oo) {
      cost -= c;
      flow += cur_flow;
    }
    return {flow, cost};
  }
};

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int best = INT_MAX;
  for(int lim = 1; lim <= 200; lim++) {
    MaxFlow mf;
    mf.n = n + m + 2;
    mf.src = 0, mf.snk = n + m + 1;
    mf.init();

    for(int i = 0; i < n; i++) {
      mf.addAugEdge(0, i + 1, 1, 0);
    }
    for(int i = 0; i < m; i++) {
      mf.addAugEdge(n + 1 + i, n + m + 1, 1, 0);
    }
    
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(a[i][j] <= lim) {
          mf.addAugEdge(i + 1, n + 1 + j, 1, a[i][j]);
        }
      }
    }

    auto res = mf.maxFlow();
    if(res.first == n) {
      best = min(best, lim * n - res.second);
    }
  }

  cout << best << endl;
  return 0;
}
