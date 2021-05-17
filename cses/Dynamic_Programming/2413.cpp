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

const int N = 1e6 + 5;
const int Mod = 1e9 + 7;

int dp[N][2][2];

int solve(int i, int start, int same_block) {
  if(i == 0) return 1;
  int& r = dp[i][start][same_block];
  if(r != -1) return r;
  r = 0;
  if(start) {
    r = (solve(i - 1, 0, 1) + solve(i - 1, 0, 0)) % Mod;
  } else {
    if(same_block) {
      r = (solve(i, 1, 0) + solve(i - 1, 0, 1)) % Mod;
    } else {
      r = (r + solve(i, 1, 0)) % Mod;
      r = (r + 3LL * solve(i - 1, 0, 0) % Mod) % Mod;
    }
  }
  return r;
}

int main()
{
  memset(dp, -1, sizeof dp);
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    cout << solve(n, 1, 0) << endl;
  }
  return 0;
}
