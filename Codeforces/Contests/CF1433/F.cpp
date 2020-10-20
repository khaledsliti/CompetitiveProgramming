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

const int N = 72;
const int Inf = 2e9;

int n, m, k;
int a[N][N];
int dp[N][N][N / 2][N];

int solve(int i, int j, int cnt, int rem) {
  if(i >= n) {
    return rem == 0 ? 0 : -Inf;
  }
  int& r = dp[i][j][cnt][rem];
  if(r != -1) return r;
  r = solve(i + (j + 1) / m, (j + 1) % m, j + 1 == m ? 0 : cnt, rem);
  if((cnt + 1) * 2 <= m) {
    r = max(r, a[i][j] + solve(i + (j + 1) / m, (j + 1) % m, j + 1 == m ? 0 : cnt + 1, (rem + a[i][j]) % k));
  }
  return r;
}

int main()
{
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, 0, 0) << endl;

  return 0;
}
