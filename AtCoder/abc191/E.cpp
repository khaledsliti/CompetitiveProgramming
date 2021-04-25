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

const int N = 2007;
const int Inf = 1e9;

int n, m;
vector<pair<int, int>> g[N];
int dist[N][N];

void dij(int src) {
  for(int i = 0; i < n; i++) {
    dist[src][i] = Inf;
  }
  dist[src][src] = 0;
  priority_queue<pair<int, int>> pq;
  pq.push({0, src});
  while(pq.empty() == false) {
    int u = pq.top().second;
    int c = -pq.top().first;
    pq.pop();
    if(c > dist[src][u]) continue;
    for(auto e: g[u]) {
      int v = e.first;
      int co = e.second;
      if(dist[src][v] > dist[src][u] + co) {
        dist[src][v] = dist[src][u] + co;
        pq.push({-dist[src][v], v});
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].push_back({b, c});
  }
  // for(int i = 0; i < n; i++) {
  //   for(auto e: g[i]) {
  //     cout << e.first << " ";
  //   }
  //   cout << endl;
  // }
  for(int i = 0; i < n; i++) {
    dij(i);
  }
  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n; j++) {
  //     cout << dist[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  for(int i = 0; i < n; i++) {
    int mn = Inf;
    for(auto e: g[i]) {
      if(e.first == i) {
        mn = min(mn, e.second);
      }
    }
    for(int j = 0; j < n; j++) {
      if(i != j) {
        mn = min(mn, dist[i][j] + dist[j][i]);
      }
    }
    if(mn >= Inf) cout << -1 << endl;
    else cout << mn << endl;
  }
  return 0;
}
