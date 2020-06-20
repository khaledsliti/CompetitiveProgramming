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

const int N = 501;
const ll Inf = 1e18;

int n;
vector<pair<int, int>> g[N];
ll dist[N][N];

int main()
{
  int m, q;
  cin >> n >> m >> q;
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].pb({b, c});
    g[b].pb({a, c});
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      dist[i][j] = i == j ? 0 : Inf;
    for(auto j : g[i])
      dist[i][j.first] = min(dist[i][j.first], (ll)j.second);
  }
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  }
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(dist[i][j] >= Inf)
        dist[i][j] = -1;
  while(q--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    cout << dist[a][b] << endl;
  }
  return 0;
}
