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

const int N = 2007;
const ll Inf = 1e18;

int n, k, p;
ll a[N], b[N];
ll dp[N][N];

ll cost(int i, int j) {
  return abs(a[i] - b[j]) + abs(b[j] - p);
}

int main()
{
  cin >> n >> k >> p;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for(int i = 0; i < k; i++) {
    cin >> b[i];
  }
  sort(b, b + k);

  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= k; j++) {
      if(i == j) dp[i][j] = max(dp[i - 1][j - 1], cost(i - 1, j - 1));
      else dp[i][j] = min(dp[i][j - 1], max(dp[i - 1][j - 1], cost(i - 1, j - 1)));
    }
  }

  cout << dp[n][k] << endl;
  return 0;
}
