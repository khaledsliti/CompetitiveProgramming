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

const int N = 404;

int n, m;
string s[N];
int dp[N][N];

int get(int i, int j, int k, int l) {
  int ans = dp[k][l];
  if(i > 0) ans -= dp[i - 1][l];
  if(j > 0) ans -= dp[k][j - 1];
  if(i > 0 && j > 0) ans += dp[i - 1][j - 1];
  return ans;
}

int calc(int i, int j, int k) {
  int ans = 0;
  ans += k - i + 1 - 2 - get(i + 1, j, k - 1, j);
  ans += k - k + 1 - 2 - get(i + 1)
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      dp[i][j] = s[i][j] == '1';
      if(i > 0) dp[i][j] += dp[i - 1][j];
      if(j > 0) dp[i][j] += dp[i][j - 1];
      if(i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
    }
  }
  int best = n * m;
  for(int i = 0; i + 5 <= n; i++) {
    for(int k = i + 4; k < n; k++) {
      for(int j = 0; j + 4 <= m; j++) {
        best = min(best, calc(i, j, k));
      }
    }
  }
  cout << best << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
