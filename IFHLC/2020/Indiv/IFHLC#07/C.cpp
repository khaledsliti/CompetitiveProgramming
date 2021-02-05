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

const int N = 2e5 + 5;
const ll Inf = 1e18;

int n, m, T, s, t;
vector<pair<int, int>> g[N];
ll g_dist[N];

bool check(ll di) {
  vector<ll> dist(n, Inf);
  dist[s] = 0;
  priority_queue<pair<ll, int>> pq;
  pq.push({0LL, s});
  while(pq.empty() == false) {
    int u = pq.top().second;
    pq.pop();
    for(int i = 0; i < sz(g[u]); i++) {
      int v = g[u][i].first;
      if(g_dist[v] < di) continue;
      int cost = g[u][i].second;
      if(dist[u] + cost < dist[v]) {
        dist[v] = dist[u] + cost;
        pq.push({-dist[v], v});
      }
    }
  }
  return dist[t] <= T;
}

int main()
{
  scanf("%d%d%d", &n, &m, &T);
  for(int i = 0; i < m; i++) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    g[u].pb({v, d});
    g[v].pb({u, d});
  }
  scanf("%d%d", &s, &t);
  for(int i = 0; i < n; i++) {
    g_dist[i] = Inf;
  }
  priority_queue<pair<ll, int>> pq;
  int k; scanf("%d", &k);
  for(int i = 0; i < k; i++) {
    int u;
    scanf("%d", &u);
    pq.push({0, u});
    g_dist[u] = 0;
  }
  while(pq.empty() == false) {
    int u = pq.top().second;
    pq.pop();
    for(int i = 0; i < sz(g[u]); i++) {
      int v = g[u][i].first;
      int c = g[u][i].second;
      if(g_dist[v] > g_dist[u] + c) {
        g_dist[v] = g_dist[u] + c;
        pq.push({-g_dist[v], v});
      }
    }
  }

  // for(int i = 0; i < n; i++) {
  //   cout << g_dist[i] << " ";
  // }
  // cout << endl;

  // cout << check(0) << endl;
  // return 0;

  ll lo = 0, hi = min(g_dist[s], g_dist[t]), best;
  while(lo <= hi) {
    ll mid = lo + (hi - lo) / 2;
    if(check(mid)) {
      best = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  printf("%lld\n", best);
  return 0;
}
