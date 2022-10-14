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

int n, m;
vector<int> g[N];
long long dp[N][4];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i = 0; i < n; i++) {
    queue<int> q;
    q.push(i);
    map<int, int> dist;
    dist[i] = 0;
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      if(dist[u] == 3) continue;
      for(int v: g[u]) {
        if(dist.count(v) == 0) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    for(auto x: dist) {
      dp[i][x.second] += x.first + 1;
    }
    for(int j = 1; j <= 3; j++) {
      dp[i][j] += dp[i][j - 1];
    }
  }
  int q;
  cin >> q;
  while(q--) {
    int u, k;
    cin >> u >> k;
    --u;
    cout << dp[u][k] << endl;
  }
  return 0;
}
