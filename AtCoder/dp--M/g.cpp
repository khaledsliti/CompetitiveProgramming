// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, m;
vector<int> g[N];
int dp[N];

int dfs(int u) {
  int& r = dp[u];
  if(r != -1) return r;
  r = 0;
  for(int v : g[u]) {
    r = max(r, 1 + dfs(v));
  }
  return r;
}

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < m ; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].pb(y);
  }
  memset(dp, -1, sizeof dp);
  int best = 0;
  for(int i = 0 ; i < n ; i++)
    best = max(best, dfs(i));
  cout << best << endl;
  return 0;
}
