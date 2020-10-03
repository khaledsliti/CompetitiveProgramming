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

const int N = 102;

int n, k, mod;
int dp[N][N * N * N];
int acc[N];

int main()
{
  cin >> n >> k >> mod;
  dp[0][0] = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < i; j++)
      acc[j] = 0;
    int idx = -1;
    int mx = k * i * (i + 1) / 2;
    for(int j = 0; j <= mx; j++) {
      if(++idx == i) idx = 0;
      acc[idx] += dp[i - 1][j];
      if(acc[idx] >= mod) acc[idx] -= mod;
      if(j - (k + 1) * i >= 0) {
        acc[idx] -= dp[i - 1][j - (k + 1) * i];
        if(acc[idx] < 0) acc[idx] += mod;
      }
      dp[i][j] = acc[idx];
    }
  }

  int mx = k * n * (n + 1) / 2;
  for(int m = 1; m <= n; m++) {
    int ans = -1;
    for(int sum = 0; sum <= mx; sum++) {
      ans += 1LL * dp[m - 1][sum] * dp[n - m][sum] % mod * (k + 1) % mod;
      if(ans >= mod) ans -= mod;
    }
    cout << ans << endl;
  }

  return 0;
}
