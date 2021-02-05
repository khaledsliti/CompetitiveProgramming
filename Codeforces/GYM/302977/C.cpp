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

const int N = 1007;
const int Inf = 1e9;

int n;
int c[N];
int v[N];
int dp[N][8];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> c[i] >> s;
    for(auto c: s) {
      v[i] |= (1 << (c - 'A'));
    }
  }

  for(int i = 0; i <= n; i++) {
    for(int j = 0; j < 8; j++) {
      dp[i][j] = Inf;
    }
  }
  dp[0][0] = 0;

  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 8; j++) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      dp[i][j | v[i - 1]] = min(dp[i][j | v[i - 1]], c[i - 1] + dp[i - 1][j]);
    }
  }

  int ans = dp[n][7] >= Inf ? -1 : dp[n][7];

  cout << ans << endl;
  return 0;
}
