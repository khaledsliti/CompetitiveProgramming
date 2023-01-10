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

const int N = 1e4 + 4;

int s, cap, r0;
int f[N], r[N];
long long dp[N][N];

long long solve(int i, int c) {
  if(i > s) return 0;
  long long& ret = dp[i][c];
  if(ret != -1) return ret;
  ret = 1e18;
  // continue
  if (f[i] <= c) {
    ret = min(ret, solve(i + 1, c - f[i]));
  }
  // fill
  int need = cap - c;
  ret = min(ret, 500 * (i > 1) + 1LL * r[i - 1] * need + solve(i + 1, cap - f[i]));
  return ret;
}

void solve() {
  cin >> s >> cap >> r[0];
  for(int i = 1; i <= s; i++) {
    cin >> f[i] >> r[i];
  }
  for(int i = 0; i <= s; i++) {
    for(int j = 0; j <= cap; j++) {
      dp[i][j] = -1;
    }
  }
  cout << solve(1, 0) << endl;
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
