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
const int Mod = 1e9 + 7;


int n;
vector<int> g[N];
int dp[N][2];

void dfs(int u, int p) {
  dp[u][0] = dp[u][1] = 1;
  for(int v : g[u]) {
    if(v != p) {
      dfs(v, u);
      dp[u][0] = (1LL * dp[u][0] * dp[v][1]) % Mod;
      dp[u][1] = (1LL * dp[u][1] * (dp[v][0] + dp[v][1])) % Mod;
    }
  }
}

int main()
{
  cin >> n;
  for(int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].pb(y);
    g[y].pb(x);
  }
  dfs(0, -1);
  int ans = (dp[0][0] + dp[0][1]) % Mod;
  cout << ans << endl;
  return 0;
}
