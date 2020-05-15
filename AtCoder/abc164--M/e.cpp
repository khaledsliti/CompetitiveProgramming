// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 51;
const int M = 105;
const int S = 10003;
const long long Inf = 1e18;

int n, m, s;
vector<pair<int, int>> g[N];
int to[M], A[M], B[M];
int C[N], D[N];
long long cost[N][S];

struct state {
  int u, s;
  bool operator<(const state& o) const {
    return u < o.u;
  }
};

int main()
{
  cin >> n >> m >> s;
  for(int i = 0 ; i < m ; i++) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    --u, --v;
    g[u].pb({i, v});
    g[v].pb({i, u});
    A[i] = a;
    B[i] = b;
  }
  for(int i = 0 ; i < n ; i++) {
    cin >> C[i] >> D[i];
  }
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < S ; j++)
      cost[i][j] = Inf;
  s = min(S - 1, s);
  cost[0][s] = 0;
  priority_queue<pair<long long, state>> pq;
  pq.push({0, {0, s}});
  while(!pq.empty()) {
    int u = pq.top().second.u;
    int h = pq.top().second.s;
    long long c = -pq.top().first;
    pq.pop();
    if(c > cost[u][h])
      continue;
    if(cost[u][min(S - 1, h + C[u])] > cost[u][h] + D[u]) {
      cost[u][min(S - 1, h + C[u])] = cost[u][h] + D[u];
      pq.push({- cost[u][min(S - 1, h + C[u])], {u, min(S - 1, h + C[u])}});
    }
    for(auto idx : g[u]) {
      int v = idx.second;
      int i = idx.first;
      if(h >= A[i] && cost[v][h - A[i]] > cost[u][h] + B[i]) {
        cost[v][h - A[i]] = cost[u][h] + B[i];
        pq.push({-cost[v][h - A[i]], {v, h - A[i]}});
      }
    }
  }
  for(int i = 1 ; i < n ; i++) {
    long long best = Inf;
    for(int j = 0 ; j < S ; j++)
      best = min(best, cost[i][j]);
    cout << best << endl;
  }
  return 0;
}
