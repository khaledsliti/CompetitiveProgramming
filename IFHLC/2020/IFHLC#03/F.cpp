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

const int N = 405;
const long long Inf = 1e18;

int n;
int cost[N];
vector<pair<int, int>> g[N][4];
string tr = "ASRT";

void solve() {
  cin >> n;
  map<string, int> id;
  for(int i = 0; i < n; i++) {
    string t;
    cin >> t >> cost[i];
    id[t] = i;
    for(int j = 0; j < 4; j++) {
      g[i][j].clear();
    }
  }
  int m;
  cin >> m;
  while(m--) {
    string a, b, m;
    int c;
    cin >> a >> b >> m >> c;
    int x = id[a], y = id[b];
    for(int j = 0; j < 4; j++) {
      if(m[0] == tr[j]) {
        g[x][j].push_back({y, c});
        g[y][j].push_back({x, c});
        break;
      }
    }
  }
  ll dist[n][4];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 4; j++) {
      dist[i][j] = Inf;
    }
  }
  string a, b;
  cin >> a >> b;
  int src = id[a], dst = id[b];
  priority_queue<pair<ll, pair<int, int>>> pq;
  for(int j = 0; j < 4; j++) {
    dist[src][j] = 0;
    pq.push({0, {src, j}});
  }
  while(pq.empty() == false) {
    int u = pq.top().second.first;
    int t = pq.top().second.second;
    ll cost = -pq.top().first;
    pq.pop();
    if(cost > dist[u][t]) continue;
    for(int j = 0; j < 4; j++) {
      if(j != t && dist[u][j] > dist[u][t] + ::cost[u]) {
        dist[u][j] = dist[u][t] + ::cost[u];
        pq.push({-dist[u][j], {u, j}});
      }
    }
    for(auto e: g[u][t]) {
      int v = e.first, c = e.second;
      if(dist[v][t] > dist[u][t] + c) {
        dist[v][t] = dist[u][t] + c;
        pq.push({-dist[v][t], {v, t}});
      }
    }
  }
  ll mn = Inf;
  for(int j = 0; j < 4; j++) {
    mn = min(mn, dist[dst][j]);
  }
  cout << mn << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
