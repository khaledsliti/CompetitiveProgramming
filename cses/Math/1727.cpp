// We only fail when we stop trying
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

const int N = 105;

int n, k;
double dp[N][N];

double solve(int cur, int mx) {
  if(cur == n) return mx;
  double& r = dp[cur][mx];
  if(r == r) return r;
  r = 0.0;
  for(int i = 1; i <= k; i++) {
    r += 1.0 / k * solve(cur + 1, max(mx, i));
  }
  return r;
}

int main()
{
  cin >> n >> k;
  memset(dp, -1, sizeof dp);
  cout << fixed << setprecision(6) << solve(0, 0) << endl;
  return 0;
}
