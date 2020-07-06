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
int depth[N], dp[N];
vector<int> g[N];

void dfs(int u, int p) {
  depth[u] = 0;
  vector<int> ch;
  for(int v : g[u]) {
    if(v != p) {
      dfs(v, u);
      depth[u] = max(depth[u], 1 + depth[v]);
      ch.push_back(1 + depth[v]);
    }
  }
  dp[u] = depth[u];
  sort(rall(ch));
  if(sz(ch) >= 2) {
    dp[u] = ch[0] + ch[1];
  }
}

int main()
{
  cin >> n;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  int ans = 0;
  for(int i = 0; i < n; i++)
    ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
}
