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

const int N = 100005;
const long long Inf = 1LL << 60;

int n, k;
vector<pair<int, int>> g[N];
int bad[N];
long long dp[N][2];

void dfs(int u, int p) {
  dp[u][1] = 0;
  dp[u][0] = bad[u] ? Inf : 0;
  for(int i = 0; i < sz(g[u]); i++) {
    int v = g[u][i].first, c = g[u][i].second;
    if(v != p) {
      dfs(v, u);
      dp[u][1] = min(dp[u][0] + dp[v][1], dp[u][1] + min(dp[v][0], c + dp[v][1]));
      if(!bad[u]) dp[u][0] += min(dp[v][0], c + dp[v][1]);
    }
  }
}

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n - 1; i++) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    g[u].pb({v, c});
    g[v].pb({u, c});
  }
  for(int i = 0; i < k; i++) {
    int u; scanf("%d", &u);
    bad[u] = 1;
  }
  
  dfs(0, -1);

  cout << min(dp[0][1], dp[0][0]) << endl;
  return 0; 
}
