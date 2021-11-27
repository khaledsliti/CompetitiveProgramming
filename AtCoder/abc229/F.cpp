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

const int N = 2e5 + 5;

int n;
int a[N], b[N];
int col[N];
long long dp[N][2];

long long solve(int cur, int last_col) {
  if(cur == n) {
    return col[n] == last_col ? b[n - 1] : 0;
  }
  long long& r = dp[cur][last_col];
  if(r != -1) return r;
  r = solve(cur + 1, 0) + (last_col == 0 ? b[cur - 1] : 0);
  r = min(r, a[cur] + solve(cur + 1, 1) + (last_col == 1 ? b[cur - 1] : 0));
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  long long ans = LLONG_MAX;
  for(int i = 0; i < 2; i++) {
    col[1] = i;
    for(int j = 0; j < 2; j++) {
      col[n] = j;
      long long cur = 0;
      if(col[1] == 1) cur += a[1];
      if(col[n] == 1) cur += a[n];
      if(col[1] == col[n]) cur += b[n];
      memset(dp, -1, sizeof dp);
      cur += solve(2, col[1]);
      ans = min(ans, cur);
    }
  }

  cout << ans << endl;
  return 0;
}
