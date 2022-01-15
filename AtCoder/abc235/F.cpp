#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int Mod = 998244353;
const int N = 10007;

string s;
int msk_d;
int dp[N][2][2][1 << 10];
int dp2[N][2][2][1 << 10];
int tenp[N];
int dtp[10][N];

void add(int& r, int v) {
  r += v;
  if(r >= Mod) r -= Mod;
}

int calc(int i, int gtz, int ltn, int mask) {
  int& r = dp[i][gtz][ltn][mask];
  if (r != -1) return r;
  if(i >= sz(s)) {
    if(!gtz) return r = 0;
    return r = ((msk_d & mask) == msk_d);
  }
  r = 0;
  for(int d = 0; d < 10; d++) {
    int can = ltn || (s[i] - '0' >= d);
    if(can) {
      int nxt_mask = mask;
      if(d > 0 || gtz) {
        nxt_mask |= (1 << d);
      }
      add(r, calc(i + 1, gtz || d > 0, ltn || d < (s[i] - '0'), nxt_mask));
    }
  }
  return r;
}

int solve(int i, int gtz, int ltn, int mask) {
  if(i >= sz(s)) return 0;
  int& r = dp2[i][gtz][ltn][mask];
  if (r != -1) return r;
  r = 0;
  for(int d = 0; d < 10; d++) {
    int can = ltn || (s[i] - '0' >= d);
    if(can) {
      int nxt_mask = mask;
      if(d > 0 || gtz) {
        nxt_mask |= (1 << d);
      }
      ll cnt = calc(i + 1, gtz || d > 0, ltn || d < (s[i] - '0'), nxt_mask);
      int add = dtp[d][sz(s) - i - 1] * cnt % Mod;
      ::add(r, add);
      ::add(r, solve(i + 1, gtz || d > 0, ltn || d < (s[i] - '0'), nxt_mask));
    }
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s;
  int m; cin >> m;
  while(m--) {
    int d; cin >> d;
    msk_d |= (1 << d);
  }

  for(int i = 0; i < N; i++) {
    tenp[i] = i > 0 ?  10LL * tenp[i - 1] % Mod : 1;
    for(int d = 0; d < 10; d++) {
      dtp[d][i] = 1LL * d * tenp[i] % Mod;
    }
  }
  memset(dp, -1, sizeof dp);
  memset(dp2, -1, sizeof dp2);
  cout << solve(0, 0, 0, 0) << endl;

  return 0;
}
