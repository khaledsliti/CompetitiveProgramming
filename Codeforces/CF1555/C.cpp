// Guess Who's Back
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

const int N = 1e5 + 5;

int n;
int arr[2][N];
int dp[2][N];

void solve() {
  cin >> n;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
      dp[i][j] = arr[i][j];
      if(j > 0) {
        dp[i][j] += dp[i][j - 1];
      }
    }
  }
  int ans = INT_MAX;
  for(int i = 0; i < n; i++) {
    int bob = 0;
    if(i > 0) {
      bob = max(bob, dp[1][i - 1]);
    }
    if(i + 1 < n) {
      bob = max(bob, dp[0][n - 1] - dp[0][i]);
    }
    ans = min(ans, bob);
  }
  cout << ans << endl;
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
