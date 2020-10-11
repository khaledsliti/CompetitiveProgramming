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

const int R = 507, N = 1e5 + 5;

int r, n;
int t[N], x[N], y[N];
int dp[N], mx[N];

int dist(int i, int j) {
  return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main()
{
  scanf("%d%d", &r, &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d%d%d", &t[i], &x[i], &y[i]);
  }
  t[0] = 0;
  x[0] = y[0] = 1;
  dp[n + 1] = 0;
  mx[n + 1] = 0;
  for(int i = n; i >= 0; i--) {
    dp[i] = 0;
    for(int j = i + 1; j <= n; j++) {
      if(t[i] + 2 * r <= t[j]) {
        dp[i] = max(dp[i], 1 + mx[j]);
        break;
      } else if(dist(i, j) <= t[j] - t[i]) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
    mx[i] = max(dp[i], mx[i + 1]);
  }

  cout << dp[0] << endl;
  return 0;
}
