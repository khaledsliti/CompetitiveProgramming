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

const int N = 4e5 + 3;
const int INF = 1e9 + 4;

int n, m, k;
vector<pair<int, int>> g[N];
int dist[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    if(c == 0) {
      a += n;
      b += n;
    }
    g[a].push_back({b, 1});
    g[b].push_back({a, 1});
  }
  for(int i = 0; i < k; i++) {
    int v; cin >> v;
    v--;
    g[v].push_back({n + v, 0});
    g[n + v].push_back({v, 0});
  }

  // for(int i = 0; i < 2 * n; i++) {
  //   cout << i << ": ";
  //   for(auto e: g[i]) {
  //     cout << e.first << " ";
  //   }
  //   cout << endl;
  // }

  for(int i = 0 ; i < 2 * n; i++) {
    dist[i] = INF;
  }
  dist[0] = 0;
  priority_queue<pair<int, int>> q;
  q.push({0, 0});
  while(q.size()) {
    int u = q.top().second;
    q.pop();
    if (u == n - 1 || u == 2 * n - 1) {
      cout << dist[u] << endl;
      return 0;
    }
    for(auto e : g[u]) {
      int v = e.first;
      int c = e.second;
      if(dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        q.push({-dist[v], v});
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
