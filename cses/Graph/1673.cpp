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

const int N = 2501, M = 5001;
const ll Inf = 1e18;

int n, m;
vector<pair<int, int>> g[N];
ll dist[N];
int vis[2][N];

int main()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[--a].push_back({--b, -c});
  }
  for(int i = 0; i < n; i++)
    dist[i] = Inf, vis[0][i] = vis[1][i] = 0;
  dist[0] = 0;
  vis[0][0] = vis[1][n - 1] = 1;
  for(int it = 0; it < n; it++) {
    for(int i = 0; i < n; i++) {
      for(auto e : g[i]) {
        int j = e.first, c = e.second;
        vis[1][i] |= vis[1][j];
        vis[0][j] |= vis[0][i];
        dist[j] = min(dist[j], dist[i] + c);
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(auto e : g[i]) {
      int j = e.first, c = e.second;
      if(vis[0][i] && vis[1][j] && dist[j] > dist[i] + c) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << -dist[n - 1] << endl;
  return 0;
}
