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

const int N = 3e5 + 5;
const int A = 26;

int n, m;
set<int> g[N];
string s;
int col[N], dp[N][A];

bool dfs(int cur) {
  if(col[cur] == 1) return true;
  if(col[cur] == 2) return false;
  col[cur] = 1;
  for(int i = 0; i < A; i++)
    dp[cur][i] = 0;
  dp[cur][s[cur] - 'a'] = 1;
  for(int nxt: g[cur]) {
    if(dfs(nxt))
      return true;
    for(int i = 0; i < A; i++) {
      dp[cur][i] = max(dp[cur][i], (s[cur] - 'a' == i) + dp[nxt][i]);
    }
  }
  col[cur] = 2;
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  cin >> s;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[--a].insert(--b);
  }
  for(int i = 0; i < n; i++)
    if(dfs(i)) {
      cout << -1 << endl;
      return 0;
    }
  int ans = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < A; j++)
      ans = max(ans, dp[i][j]);
  cout << ans << endl;
  return 0;
}
