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

const int N = 1e5 + 5;
const ll Inf = 1e18;

int n;
vector<pair<int, int>> g[N];
ll dist[N];

int main()
{
  int m;
  cin >> n >> m;
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].pb({b, c});
  }
  for(int i = 0; i < n; i++)
    dist[i] = Inf;
  dist[0] = 0;
  priority_queue<pair<ll, int>> pq;
  pq.push({0, 0});
  while(!pq.empty()) {
    int u = pq.top().second;
    ll cu = -pq.top().first;
    pq.pop();
    if(cu > dist[u]) continue;
    for(auto e : g[u]) {
      int v = e.first;
      int c = e.second;
      if(dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        pq.push({-dist[v], v});
      }
    }
  }
  for(int i = 0; i < n; i++)
    cout << dist[i] << " \n"[i == n - 1];
  return 0;
}
