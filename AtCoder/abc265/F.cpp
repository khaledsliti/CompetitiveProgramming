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

const int N = 104;
const int Mod = 998244353;

int n, d;
int p[N], q[N];
int dp[N][1008][1008];

int solve(int cur_d, int rem_q, int rem_p) {
  if(cur_d >= n) {
    return 1;
  }
  int& r = dp[cur_d][rem_q][rem_p];
  if(r != -1) {
    return r;
  }
  r = 0;
  for(int x = p[cur_d] - rem_p; x <= p[cur_d] + rem_p; x++) {
    int nw_rem_q = rem_q - abs(q[cur_d] - x);
    if(nw_rem_q >= 0) {
      r += solve(cur_d + 1, nw_rem_q, rem_p - abs(p[cur_d] - x));
      if(r > Mod) {
        r -= Mod;
      }
    }
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> d;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> q[i];
  }

  memset(dp, -1, sizeof dp);
  cout << solve(0, d, d) << endl;
  return 0;
}
