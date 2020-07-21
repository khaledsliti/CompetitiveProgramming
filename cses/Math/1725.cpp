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

const int N = 601;

int n, a, b;
double dp[N][N];

double solve(int cur, int sum) {
  if(cur == n) {
    if(sum >= a && sum <= b) return 1.0;
    else return 0.0;
  }
  double& r = dp[cur][sum];
  if(r == r) return r;
  r = 0.0;
  for(int i = 1; i <= 6; i++) {
    r += 1.0 / 6.0 * solve(cur + 1, sum + i);
  }
  return r;
}

int main()
{
  cin >> n >> a >> b;
  memset(dp, -1, sizeof dp);
  double r;
  memset(&r, -1, sizeof (&r));
  cout << r << endl;
  if(r == r) cout << "YEs" << endl;
  else cout << "No" << endl;
  cout << fixed << setprecision(6) << solve(0, 0) << endl;
  return 0;
}
