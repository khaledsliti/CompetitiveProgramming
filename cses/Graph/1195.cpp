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

const int N = 1e5 + 5, E = 2e5 + 5;
const ll Inf = 1e18;

int n, m, e;
int head1[N], nxt1[E], to1[E], cost1[E];
int head2[N], nxt2[E], to2[E], cost2[E];
ll dist1[N], dist2[N];

void init() {
  e = 0;
  memset(head1, -1, n * (sizeof(head1[0])));
  memset(head2, -1, n * (sizeof(head2[0])));
}

void addEdge(int a, int b, int c, int* head, int* nxt, int* to, int* cost) {
  nxt[e] = head[a];
  head[a] = e;
  to[e] = b;
  cost[e] = c;
}

void addEdge(int a, int b, int c) {
  addEdge(a, b, c, head1, nxt1, to1, cost1);
  addEdge(b, a, c, head2, nxt2, to2, cost2);
  e++;
}

void dijkstra(int src, ll* dist, int* head, int* nxt, int* to, int* cost) {
  for(int i = 0; i < n; i++)
    dist[i] = Inf;
  dist[src] = 0;
  priority_queue<pair<ll, int>> pq;
  pq.push({0, src});
  while(!pq.empty()) {
    int u = pq.top().second;
    int cu = -pq.top().first;
    pq.pop();
    if(cu > dist[u]) continue;
    for(int k = head[u]; ~k; k = nxt[k]) {
      int v = to[k], c = cost[k];
      if(dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        pq.push({-dist[v], v});
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  init();
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    addEdge(--a, --b, c);
  }
  dijkstra(0, dist1, head1, nxt1, to1, cost1);
  dijkstra(n - 1, dist2, head2, nxt2, to2, cost2);
  ll best = 1e18;
  for(int i = 0; i < n; i++) {
    for(int k = head1[i]; ~k; k = nxt1[k]) {
      int j = to1[k], c = cost1[k];
      ll cur = dist1[i] + c / 2 + dist2[j];
      best = min(best, cur);
    }
  }
  cout << best << endl;
  return 0;
}
