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

const int N = 401;
const long long Inf = 4e18;

int n;
int a[N];
long long dp[N][N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> a[i];
  for(int i = 0 ; i < n ; i++)
    dp[i][i] = 0;
  for(int len = 2; len <= n; len++) {
    for(int i = 0; i + len <= n ; i++) {
      int j = i + len - 1;
      long long sum = 0;
      for(int k = i; k <= j; k++)
        sum += a[k];
      dp[i][j] = Inf;
      for(int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], sum + dp[i][k] + dp[k + 1][j]);
      }
    }
  }
  cout << dp[0][n - 1] << endl;
  return 0;
}
