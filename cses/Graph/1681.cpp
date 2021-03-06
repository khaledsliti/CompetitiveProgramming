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
const int Mod = 1e9 + 7;

int n;
vector<int> g[N];
int dp[N];

void dfs(int u) {
  if(dp[u] != -1)
    return;
  dp[u] = 0;
  for(int v: g[u]) {
    dfs(v);
    dp[u] = (dp[u] + dp[v]) % Mod;
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
  dp[n - 1] = 1;
  dfs(0);
  cout << dp[0] << endl;
  return 0;
}
