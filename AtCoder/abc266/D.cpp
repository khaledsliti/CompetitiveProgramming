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

const int N = 1e5 + 5;

int n;
long long A[5][N];
long long dp[5][N];

long long solve(int x, int t) {
  if (x >= 5 || x < 0) return 0;
  if(t >= N) return 0;
  long long& r = dp[x][t];
  if (r != -1) return r;
  r = solve(x, t + 1);
  r = max(r, solve(x - 1, t + 1));
  r = max(r, solve(x + 1, t + 1));
  r += A[x][t];
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    int t, x, a; cin >> t >> x >> a;
    A[x][t] += a;
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << endl;
  return 0;
}
