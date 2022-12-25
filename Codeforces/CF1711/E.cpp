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
const int Mod = 998244353;

string n;
int dp[N][2][2][2][2][2][2][2][2][2];

int solve(int i, int ok_a, int ok_b, int ok_c, int bc_gt_ab, int bc_gt_ac, int sum_gt_bc, int need_ones, int ac_1, int ab_1) {
  if(i >= sz(n)) return sum_gt_bc && !need_ones && ab_1 && ac_1;
  int& r = dp[i][ok_a][ok_b][ok_c][bc_gt_ab][bc_gt_ac][sum_gt_bc][need_ones][ab_1][ac_1];
  if(r != -1) return r;
  r = 0;
  int bit = n[i] - '0';
  for(int msk = 0; msk < 8; msk++) {
    int ab = (msk >> 2) & 1;
    int ac = (msk >> 1) & 1;
    int bc = msk & 1;
    if(!bc_gt_ab && ab > bc) continue;
    if(!bc_gt_ac && ac > bc) continue;
    int nw_sum_gt_bc;
    int nw_need_ones;
    if(need_ones) {
      if (!ab || !ac) continue;
      if(bc) {
        nw_need_ones = 1;
      } else {
        nw_need_ones = 0;
      }
      nw_sum_gt_bc = 0;
    } else {
      if(sum_gt_bc) {
        nw_sum_gt_bc = 1;
        nw_need_ones = 0;
      } else {
        if(ab + ac > bc) {
          nw_sum_gt_bc = 1;
          nw_need_ones = 0;
        } else if(ab + ac == bc) {
          nw_sum_gt_bc = 0;
          nw_need_ones = 0;
        } else {
          nw_sum_gt_bc = 0;
          nw_need_ones = 1;
        }
      }
    }
    int nw_bc_gt_ab = bc_gt_ab || (bc > ab);
    int nw_bc_gt_ac = bc_gt_ac || (bc > ac);
    for(int abc = 0; abc < 8; abc++) {
      int a = (abc >> 2) & 1;
      int b = (abc >> 1) & 1;
      int c = abc & 1;
      if((a ^ b != ab) || (a ^ c != ac) || (b ^ c != bc)) continue;
      bool poss = (ok_a || a <= bit) && (ok_b || b <= bit) && (ok_c || c <= bit);
      if(!poss) continue;
      r = (r + solve(i + 1, (ok_a || a < bit), ok_b || b < bit, ok_c || c < bit,
        nw_bc_gt_ab, nw_bc_gt_ac, nw_sum_gt_bc, nw_need_ones, ab_1 || ab, ac_1 || ac)) % Mod;
    }
  }
  return r;
}

void solve() {
  cin >> n;
  memset(dp, -1, sizeof dp);
  int ans = 3LL * solve(0, 0, 0, 0, 0, 0, 0, 0, 0, 0) % Mod;
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  while(T--) {
    solve();
  }
  return 0;
}
