// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long double solve2() {
  ifstream cout("in.txt");
  int n, m, l, r, u, d;
  cin >> m >> n >> l >> u >> r >> d;
  --u, --d, --l, --r;
  vector<vector<double>> dp(n, vector<double>(m, 0));
  dp[0][0] = 1;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < m ; j++) {
      if(i >= u && i <= d && j >= l && j <= r)
        dp[i][j] = 0;
      if(i + 1 < n && j + 1 < m) {
        dp[i + 1][j] += 0.5 * dp[i][j];
        dp[i][j + 1] += 0.5 * dp[i][j];
      } else if(i + 1 < n) dp[i + 1][j] += dp[i][j];
      else if(j + 1 < m) dp[i][j + 1] += dp[i][j];
    }
  // for(int i = 0 ; i < n ; i++) {
  //   for(int j = 0 ; j < m ; j++)
  //     cout << dp[i][j] << " ";
  //   cout << endl;
  // }
  cout.close();
  return dp[n - 1][m - 1];
}

long double solve() {
  ifstream cout("in.txt");
  int n, m, l, r, u, d;
  cin >> m >> n >> l >> u >> r >> d;
  if(l == 1 && r == m || u == 1 && d == n)
    return 0;
  --u, --d, --l, --r;
  long double ans = 0;
  for(int it = 0 ; it < 2 ; it++) {
    if(l > 0) {
      long double p = 1;
      for(int j = 1 ; j < l ; j++)
        p /= 2;
      for(int i = 1 ; i <= u ; i++) {
        p *= (i + l - 1);
        p /= 2.0 * i;
      }
      for(int i = u ; i <= d ; i++) {
        ans += p * (i < n - 1 ? 0.5 : 1);
        p *= (i + l);
        p /= 2.0 * (i + 1);
      }
    }
    swap(l, u);
    swap(r, d);
    swap(n, m);
  }
  cout.close();
  return 1 - ans;
}

int main()
{
  int T, tc = 1;
  // cin >> T;
  T = 100;
  ofstream out("in.txt");
  while(T--) {
    int n = rand() % 100 + 1;
    int m = rand() % 100 + 1;
    int l = rand() % m + 1;
    int r = rand() % m + 1; if(l > r) swap(l, r);
    int u = rand() % n + 1;
    int d = rand() % n + 1; if(u > d) swap(u, d);
    out << m << " " << n << " " << l << " " << u << " " << r << " " << d << endl;
    long double ans1 = solve();
    long double ans2 = solve2();
    if(fabs(ans1 - ans2) > 1e-5) {
      cout << tc << " ---> " << fixed << setprecision(10) << ans1 << " " << ans2 << endl;
    }
    tc++;
    // cout << "Case #" << tc++ << ": " << fixed << setprecision(10) << solve() << endl;
  }
  out.close();
  cerr << "Done" << endl;
  return 0;
}
