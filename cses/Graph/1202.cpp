// We only fail when we stop trying
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

const int N = 1e5 + 5, E = 2e5 + 5;
const ll Inf = 1e18;
const int inf = 1e9;
const int Mod = 1e9 + 7;

int n, e;
int head[N], nxt[E], to[E], cost[E], good[E];
ll dist[N];
int dp1[N], dp2[N], dp3[N];


void init() {
  e = 0;
  memset(head, -1, n * sizeof(head[0]));
}

void addEdge(int f, int t, int c) {
  nxt[e] = head[f];
  head[f] = e;
  to[e] = t;
  cost[e] = c;
  e++;
}

void dfs(int u) {
  if(dp1[u] != -1)
    return;
  dp1[u] = 0;
  dp2[u] = inf;
  dp3[u] = -inf;
  for(int k = head[u]; ~k; k = nxt[k]) {
    if(!good[k]) continue;
    int v = to[k], c = cost[k];
    dfs(v);
    dp1[u] = (dp1[u] + dp1[v]) % Mod;
    dp2[u] = min(dp2[u], 1 + dp2[v]);
    dp3[u] = max(dp3[u], 1 + dp3[v]);
  }
}

int main()
{
  int m;
  cin >> n >> m;
  init();
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    addEdge(--a, --b, c);
  }
  for(int i = 0; i < n; i++)
    dist[i] = Inf;
  dist[0] = 0;
  priority_queue<pair<ll, int>> pq;
  pq.push({0, 0});
  while(!pq.empty()) {
    int u = pq.top().second;
    ll c = -pq.top().first;
    pq.pop();
    if(c > dist[u]) continue;
    for(int k = head[u]; ~k; k = nxt[k]) {
      int v = to[k], c = cost[k];
      if(dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        pq.push({-dist[v], v});
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int k = head[i]; ~k; k = nxt[k]) {
      int j = to[k], c = cost[k];
      if(dist[j] == dist[i] + c) {
        good[k] = 1;
      }
    }
  }
  memset(dp1, -1, sizeof dp1);
  memset(dp2, -1, sizeof dp2);
  memset(dp3, -1, sizeof dp3);
  dp1[n - 1] = 1;
  dp2[n - 1] = dp3[n - 1] = 0;
  dfs(0);

  cout << dist[n - 1] << " " << dp1[0] << " " << dp2[0] << " " << dp3[0] << endl;
  return 0;
}
