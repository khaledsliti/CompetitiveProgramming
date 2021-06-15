// RedStone
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

const int N = 66;

int n, s;
ll dp[N][N][2];

ll solve() {
  if(s > n) return 0;
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
      for(int t = 0; t <= 1; t++)
        dp[i][j][t] = 0;
  dp[0][0][1] = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
      dp[i][j][1] = dp[i - 1][j][0] + (j > 0 ? dp[i - 1][j - 1][1] : 0);
    }
  }
  return dp[n][s][0] + dp[n][s][1];
}

int main()
{
  while(cin >> n >> s) {
    if(n <= -1 && s <= -1) break;
    cout << solve() << endl;
  }
  return 0;
}
