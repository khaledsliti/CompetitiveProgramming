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
const int M = 101;
const int Mod = 1e9 + 7;

int n, m;
int x[N];
int dp[N][M];

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> x[i];
  
  if(x[0] == 0) {
    for(int i = 1; i <= m; i++)
      dp[1][i] = 1;
  } else {
    dp[1][x[0]] = 1;
  }
  
  for(int i = 2; i <= n; i++) {
    int cur = x[i - 1];
    for(int d = 1; d <= m; d++) {
      if(cur != 0 && cur != d) continue;
      if(d + 1 <= m) dp[i][d] = (dp[i][d] + dp[i - 1][d + 1]) % Mod;
      dp[i][d] = (dp[i][d] + dp[i - 1][d]) % Mod;
      if(d - 1 > 0) dp[i][d] = (dp[i][d] + dp[i - 1][d - 1]) % Mod;
    }
  }
  int ans = 0;
  for(int i = 1; i <= m; i++)
    ans = (ans + dp[n][i]) % Mod;
  cout << ans << endl;
  return 0;
}
