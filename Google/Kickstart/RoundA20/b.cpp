// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 50;

int n, k, p;
int a[N][N];
int dp[N][N * N];

void solve() {
  cin >> n >> k >> p;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < k ; j++)
      cin >> a[i][j];
  
  for(int i = 0 ; i <= p ; i++)
    dp[0][i] = 0;
  for(int i = 1 ; i <= n ; i++) {
    for(int j = 0 ; j <= p ; j++) {
      dp[i][j] = dp[i - 1][j];
      int sum = 0;
      for(int t = 1 ; t <= min(j, k) ; t++) {
        sum += a[i - 1][t - 1];
        dp[i][j] = max(dp[i][j], sum + dp[i - 1][j - t]);
      }
    }
  }
  cout << dp[n][p] << endl;
}

int main()
{
  int T, tc = 1;
  cin >> T;
  while(T--) {
    cout << "Case #" << tc++ << ": ";
    solve();
  }
  return 0;
}
