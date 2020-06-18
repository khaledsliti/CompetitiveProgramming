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

const int N = 501;

int a, b;
int dp[N][N];

int main()
{
  cin >> a >> b;

  for(int i = 1; i <= a; i++) {
    for(int j = 1; j <= b; j++) {
      if(i == j) dp[i][j] = 0;
      else {
        dp[i][j] = 1e9;
        for(int k = 1; k < i; k++) {
          dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
        }
        for(int k = 1; k < j; k++)
          dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
      }
    }
  }
  cout << dp[a][b] << endl;
  return 0;
}
