// RedStone
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
const long long INF = 1e18;

int n, m;
int h[N];
vector<int> g[N];
long long dist[N];

int cost(int u, int v) {
  if(h[u] >= h[v]) return h[u] - h[v];
  return 2 * (h[u] - h[v]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> h[i];
  }
  while(m--) {
    int a, b; cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  priority_queue<pair<long long, int>> pq;
  pq.push({0, 0});
  for(int i = 1; i < n; i++) {
    dist[i] = INF;
  }
  dist[0] = 0;
  while(!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for(int v: g[u]) {
      if(dist[v] > dist[u] - cost(u, v)) {
        dist[v] = dist[u] - cost(u, v);
        pq.push({-dist[v], v});
      }
    }
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    ans = max(ans, -dist[i]);
  }
  cout << ans << endl;
  return 0;
}
