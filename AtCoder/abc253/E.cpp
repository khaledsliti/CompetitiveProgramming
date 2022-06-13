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

const int Mod = 998244353;
const int N = 1007, M = 5007;

int n, m, k;
int dp[N][M];
int pref[M];

int get(int l, int r) {
  if(l > r) return 0;
  int s = pref[r];
  if(l > 0) {
    s -= pref[l - 1];
  }
  return s % Mod;
}

int main()
{
  cin >> n >> m >> k;
  for(int j = 1; j <= m; j++) {
    dp[0][j] = 1;
    pref[j] += pref[j - 1] + dp[0][j];
    pref[j] %= Mod;
  }
  for(int i = 1; i < n; i++) {
    for(int j = 1; j <= m; j++) {
      dp[i][j] = 0;
      dp[i][j] = (dp[i][j] + get(1, max(0, j - k))) % Mod;
      dp[i][j] = (dp[i][j] + get(min(m + 1, j + k), m)) % Mod;
      if (k == 0) {
        dp[i][j] = (dp[i][j] - dp[i - 1][j]) % Mod;
      }
    }
    for(int j = 1; j <= m; j++) {
      pref[j] = pref[j - 1] + dp[i][j];
      pref[j] %= Mod;
    }
  }
  // for(int i = 0; i < n; i++) {
  //   for(int j = 1; j <= m; j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  int ans = 0;
  for(int k = 1; k <= m; k++) {
    ans += dp[n - 1][k];
    ans %= Mod;
  }
  cout << (ans + Mod) % Mod << endl;
  return 0;
}
/*

dp[i][j] = dp[i - 1][j - k] + ... dp[i - 1][j + k]

*/