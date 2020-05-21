// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1005;
const int Mod = 1e9 + 7;

string s;
int k, n;
int dp[N][N][2];
int cost[N];

int main()
{
  cin >> s; n = sz(s);
  cin >> k;
  if(k == 0)
    return cout << 1 << endl, 0;
  if(k == 1)
    return cout << n - 1 << endl, 0;
  dp[0][0][0] = 1;
  dp[0][0][1] = 0;
  for(int i = 1 ; i <= n ; i++) {
    for(int j = 0 ; j <= i ; j++) {
      int d = s[i - 1] - '0';
      if(j >= d)
        dp[i][j][0]  = dp[i - 1][j - d][0];
      dp[i][j][1] = dp[i - 1][j][1];
      if(j > 0) dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j - 1][1]) % Mod;
      if(d) dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][0]) % Mod;
    }
  }
  // for(int len = 0 ; len <= n ; len++)
  //   cout << dp[n][len][0] + dp[n][len][1] << endl;
  cost[1] = 0;
  for(int i = 2 ; i <= n ; i++) {
    cost[i] = 1 + cost[__builtin_popcount(i)];
  }
  int ans = 0;
  for(int len = 2 ; len <= n ; len++) {
    int op = 1 + cost[len];
    if(op == k)
      ans = ((ans + dp[n][len][0]) % Mod + dp[n][len][1]) % Mod;
  }
  cout << ans << endl;
  return 0;
}
