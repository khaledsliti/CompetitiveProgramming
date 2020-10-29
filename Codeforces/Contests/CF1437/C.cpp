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

const int N = 201;
const int INF = 1e9;

int n;
int t[N];
int dp[2 * N][N];

int solve(int tm, int idx) {
  if(idx >= n)  return 0;
  if(tm >= 2 * n) return INF;
  int& r = dp[tm][idx];
  if(r != -1) return r;
  r = solve(tm + 1, idx);
  r = min(r, abs(tm - t[idx]) + solve(tm + 1, idx + 1));
  return r;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> t[i];
    t[i]--;
  }
  sort(t, t + n);
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
