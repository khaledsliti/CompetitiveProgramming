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

const int N = 1e5 + 5;

int n, m, k;
vector<pair<int, int>> g[N];
int vis[N];

int main()
{
  cin >> n >> m >> k;
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    g[--a].push_back({--b, c});
  }
  memset(vis, 0, sizeof vis);
  priority_queue<pair<ll, int>> pq;
  pq.push({0, 0});
  while(!pq.empty()) {
    int u = pq.top().second;
    ll uc = -pq.top().first;
    pq.pop();
    if(vis[u] >= k) continue;
    vis[u]++;
    if(u == n - 1)
      cout << uc << " ";
    for(auto e: g[u]) {
      int v, cost;
      tie(v, cost) = e;
      if(vis[v] >= k) continue;
      pq.push({-uc - cost, v});
    }
  }
  cout << endl;
  return 0;
}
