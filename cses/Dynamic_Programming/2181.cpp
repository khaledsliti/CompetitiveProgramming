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

const int N = 10, M = 1001;
const int Mod = 1e9 + 7;

int n, m;
int dp[M][N][1 << N];

bool is_set(int mask, int pos) {
  return (mask & (1 << pos)) != 0;
}

int solve(int i, int j, int mask) {
  if(i >= m) return 1;
  int& r = dp[i][j][mask];
  if(r != -1) return r;
  r = 0;
  if(j + 1 < n && !is_set(mask, j) && !is_set(mask, j + 1)) {
    r = (r + solve(i + (j + 2 >= n), (j + 2) % n, mask)) % Mod;
  }
  if(i + 1 < m && !is_set(mask, j)) {
    r = (r + solve(i + (j + 1 >= n), (j + 1) % n, mask ^ (1 << j))) % Mod;
  }
  if(is_set(mask, j)) {
    r = (r + solve(i + (j + 1 >= n), (j + 1) % n, mask ^ (1 << j))) % Mod;
  }
  return r;
}

int main()
{
  cin >> n >> m;
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, 0) << endl;
  return 0;
}
