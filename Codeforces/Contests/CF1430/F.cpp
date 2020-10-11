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

const int N = 2008;
const ll INF = 1e18;

int n, k;
ll a[N], L[N], R[N];
ll dp[N][N];

ll solve(int cur, int last, ll have) {
  if(cur >= n) {
    return 0;
  }
  ll& r = dp[cur][last];
  if(r != -1) return r;
  r = INF;
  if(have >= a[cur]) {
    r = min(r, a[cur] + solve(cur + 1, last, have - a[cur]));
    if(R[cur] > L[cur] || L[cur + 1] > R[cur]) {
      r = min(r, have + solve(cur + 1, cur + 1, k));
    }
  } else {
    ll rem = a[cur] - have;
    ll x = (rem + k - 1) / k;
    ll w = R[cur] - L[cur];
    if(x <= w) { // possible
      r = min(r, a[cur] + solve(cur + 1, last, x * k - rem));
      if(x < w || L[cur + 1] > R[cur]) {
        r = min(r, have + x * k + solve(cur + 1, cur + 1, k));
      }
    }
  }
  return r;
}

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> L[i] >> R[i] >> a[i];
  }
  memset(dp, -1, sizeof dp);
  L[n] = INF;
  ll ans = solve(0, 0, k);
  if(ans >= INF) ans = -1;
  cout << ans << endl;
  return 0;
}
