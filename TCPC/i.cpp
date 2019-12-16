#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 101;
const int P = 2e4 + 5;
const long long oo = 1e18;

int n, m, k, p;
int a[2 * N];
long long dp[N][P];

long long solve(int cur, int rem)
{
  if(rem == 0)
    return 0;
  if(cur >= n)
    return oo;
  long long& r = dp[cur][rem];
  if(r != -1)
    return r;
  r = oo;
  for(int ch = 0 ; ch < min(m, rem) ; ch++){
    r = min(r, a[ch] + solve(cur + 1, rem - ch - 1));
  }
  return r;
}

int main()
{
  cin >> n >> m >> k >> p;
  for(int i = 0 ; i < m ; i++){
    cin >> a[i];
  }
  sort(a, a + m);
  for(int i = 1 ; i < m ; i++)
    a[i] += a[i - 1];
  for(int i = 0 ; i < p ; i++)
    a[i + m] = a[m - 1];
  m += p;
  memset(dp, -1, sizeof dp);
  int ans = 0;
  for(int i = 1 ; i <= n * m ; i++)
    if(solve(0, i) <= k)
      ans = i;
  cout << ans << endl;
  return 0;
}
