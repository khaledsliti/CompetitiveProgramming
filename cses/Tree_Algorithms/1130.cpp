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

const int N = 2e5 + 5;

int n;
vector<int> g[N];
int dp[N][2];

int dfs(int u, int p, int taken) {
  int& r = dp[u][taken];
  if(r != -1) return r;
  int sum = 0;
  for(int v: g[u]) {
    if(v != p) {
      sum += dfs(v, u, 0);
    }
  }
  r = sum;
  if(!taken) {
    for(int v: g[u]) {
      if(v != p) {
        int cur = sum - dfs(v, u, 0) + dfs(v, u, 1) + 1;
        r = max(r, cur);
      }
    }
  }
  return r;
}

int main()
{
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[--a].pb(--b);
    g[b].pb(a);
  }
  memset(dp, -1, sizeof dp);
  cout << dfs(0, -1, 0) << endl;
  return 0;
}
