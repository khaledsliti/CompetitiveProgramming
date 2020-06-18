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

const int N = 5001;

int n, m;
string a, b;
int dp[N][N];

int main()
{
  cin >> a >> b;
  n = sz(a), m = sz(b);
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      if(i == 0 || j == 0) dp[i][j] = i + j;
      else if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
      else dp[i][j] = min(min(1 + dp[i - 1][j], 1 + dp[i - 1][j - 1]), 1 + dp[i][j - 1]);
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
