// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n;
int a[3];
int dp[N][3];

int calc(int n, int r)
{
  return (n + r) / 3;
}

int main()
{
  int l, r;
  cin >> n >> l >> r;
  for(int i = 0 ; i < 3 ; i++) {
    a[i] = calc(r, i) - calc(l - 1, i);
  }
  dp[0][0] = 1;
  for(int i = 1 ; i <= n ; i++){
    for(int r = 0 ; r < 3 ; r++) {
      dp[i][r] = 0;
      for(int cur = 0 ; cur < 3 ; cur++) {
        dp[i][r] = (dp[i][r] + 1LL * a[cur] * dp[i - 1][(((r - cur) % 3) + 3) % 3]) % MOD;
      }
    }
  }
  cout << dp[n][0] << endl;
  return 0;
}
