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
const int Inf = 1e9;

int n, dp[N], nxt[N];
vector<int> g[N];


void dfs(int u) {
  if(dp[u] != -1)
    return;
  dp[u] = -Inf;
  for(int v : g[u]) {
    dfs(v);
    if(dp[v] + 1 > dp[u]) {
      dp[u] = 1 + dp[v];
      nxt[u] = v;
    }
  }
}

int main()
{
  int m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    g[--a].pb(--b);
  }
  memset(dp, -1, sizeof dp);
  memset(nxt, -1, sizeof nxt);
  dp[n - 1] = 1;
  nxt[n - 1] = -1;
  dfs(0);
  if(dp[0] < 0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << dp[0] << endl;
  int cur = 0;
  vector<int> path;
  while(~cur) {
    cout << cur + 1 << " ";
    cur = nxt[cur];
  }
  cout << endl;
  return 0;
}
