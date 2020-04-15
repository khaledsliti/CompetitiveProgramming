// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 100006;
const int Mod = 1e9 + 7;

namespace TLE {
  int n;
  int dp[N][10];
  int dp2[N][10];
  int po[N];

  int calc(int s, int e, int rem) {
    if(s > e)
      return rem == 0;
    int& r = dp[s][rem];
    if(r != -1) return r;
    r = 0;
    for(int d = 1 ; d < 10 ; d++) {
      int nxt_rem = (rem + d + (s < e ? d : 0)) % 9;
      int v = calc(s + 1, e - 1, nxt_rem);
      r = (r + v) % Mod;
    }
    return r;
  }

  int solve(int s, int e, int rem) {
    if(s > e)
      return 0;
    int &r = dp2[s][rem];
    if(r != -1) return r;
    r = 0;
    for(int d = 1 ; d < 10 ; d++) {
      int nxt_rem = (rem + d + (s < e ? d : 0)) % 9;
      int val = 1LL * d * (po[s] + (s < e ? po[e] : 0)) % Mod;
      int cnt = calc(s + 1, e - 1, nxt_rem);
      r = (r + 1LL * val * cnt % Mod) % Mod;
      r = (r + solve(s + 1, e - 1, nxt_rem)) % Mod;
    }
    return r;
  }
  void solve_pb() {
    po[0] = 1;
    for(int i = 1 ; i < N ; i++)
      po[i] = po[i - 1] * 10LL % Mod;
    int T;
    scanf("%d", &T);
    while(T--) {
      scanf("%d", &n);
      for(int i = 0 ; i < n ; i++)  
        for(int j = 0 ; j < 10 ; j++)
          dp[i][j] = dp2[i][j] = -1;
      printf("%d\n", solve(0, n - 1, 0));
    }
  }
};

namespace AC {
  int n;
  long long dp[N][10];
  long long sum[N][10];

  int mpo(int a, int b) {
    if(!b) return 1;
    int r = mpo(a, b >> 1);
    r = (1LL * r * r) % Mod;
    if(b & 1) r = (1LL * r * a) % Mod;
    return r;
  }

  void solve() {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    int len = n / 2;
    if(n & 1) {
      ans = 0;
      for(int d = 1 ; d < 10 ; d++) {
        for(int r = 0 ; r < 9 ; r++) {
          if((r + r + d) % 9 == 0) {
            ans = (ans + sum[len][r] * (1 + mpo(10, len + 1)) % Mod + (dp[len][r] * d % Mod * mpo(10, len) % Mod) % Mod) % Mod;
          }
        }
      }
    } else {
      ans = sum[len][0] * (1 + mpo(10, len)) % Mod;
    }
    printf("%d\n", ans);
  }

  void init() {
    dp[0][0] = 1;
    for(int i = 1 ; i < N ; i++) {
      for(int r = 0 ; r < 9 ; r++) {
        dp[i][r] = 0;
        sum[i][r] = 0;
        for(int d = 1 ; d <= 9 ; d++) {
          int prv = (r - d + 9) % 9;
          dp[i][r] = (dp[i][r] + dp[i - 1][prv]) % Mod;
          sum[i][r] = (sum[i][r] + sum[i - 1][prv] * 10 % Mod + dp[i - 1][prv] * d % Mod) % Mod;
        }
      }
    }
  }

  void solve_pb() {
    init();
    int T;
    scanf("%d", &T);
    while(T--) {
      solve();
    }
  }
};


int main()
{
  AC::solve_pb();
  // TLE::solve_pb();
  return 0;
}
