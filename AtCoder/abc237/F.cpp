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

const int Mod = 998244353;
const int N = 1004;
const int M = 12;

int n, m;
int dp[N][M][M][M];

int solve(int i, int min_1, int min_2, int min_3) {
  if(i >= n) return min_3 <= m;
  int& r = dp[i][min_1][min_2][min_3];
  if(r != -1) return r;
  r = 0;
  for(int cur = 1; cur <= m; cur++) {
    if(cur > min_3) break;
    int nw_min_1 = min(min_1, cur);
    int nw_min_2 = min_2;
    if(cur > min_1) nw_min_2 = min(nw_min_2, cur);
    int nw_min_3 = min_3;
    if(cur > min_2) nw_min_3 = min(nw_min_3, cur);
    r = (r + solve(i + 1, nw_min_1, nw_min_2, nw_min_3)) % Mod;
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  memset(dp, -1, sizeof dp);
  cout << solve(0, m + 1, m + 1, m + 1) << endl;
  return 0;
}
