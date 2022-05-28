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

const int N = 51 * 50;
const int Mod = 998244353;

int n, m, k;
int dp[N][N];

int main()
{
  cin >> n >> m >> k;
  for(int i = 0; i <= k; i++) {
    dp[0][i] = 1;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= k; j++) {
      // 
      for(int v = 1; v <= m; v++) {
        if(j >= v) {
          dp[i][j] += dp[i - 1][j - v];
          dp[i][j] %= Mod;
        }
      }
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}
