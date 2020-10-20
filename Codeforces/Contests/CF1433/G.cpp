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

const int N = 1005;
const int Inf = 1e9;

int n, m, k;
int cost[N][N];
vector<pair<int, int>> g[N];
vector<pair<int, int>> paths;

void dij(int src) {
  for(int i = 0; i < n; i++) {
    cost[src][i] = Inf;
  }
  cost[src][src] = 0;
  priority_queue<pair<int, int>> pq;
  pq.push({0, src});
  while(pq.empty() == false) {
    int u = pq.top().second;
    pq.pop();
    for(auto e: g[u]) {
      int v = e.first;
      int c = e.second;
      if(cost[src][v] > cost[src][u] + c) {
        cost[src][v] = cost[src][u] + c;
        pq.push({-cost[src][v], v});
      }
    }
  }
}

ll get(int a, int b, int c) {
  ll r = 0;
  for(int i = 0; i < sz(paths); i++) {
    int fr = paths[i].first;
    int to = paths[i].second;
    int mn = min(cost[fr][to], cost[fr][a] + cost[to][b]);
    mn = min(mn, cost[fr][b] + cost[to][a]);
    r += mn;
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].pb({b, c});
    g[b].pb({a, c});
  }
  for(int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    paths.pb({--a, --b});
  }

  for(int i = 0; i < n; i++) {
    dij(i);
  }

  ll ans = LLONG_MAX;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < sz(g[i]); j++) {
      int t = g[i][j].first;
      int c = g[i][j].second;
      ans = min(ans, get(i, t, c));
    }
  }
  cout << ans << endl;
  return 0;
}
