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

const int N = 2007, D = 4;
const int Mod = 1e9 + 7;

int n, m;
string s[N];
int dp[N][N][D];
int dx[D] = {0, 0, 1, 1};
int dy[D] = {0, 1, 1, 0};

bool in(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int solve(int x, int y, int last) {
  if(!in(x, y)) return 0;
  if(x == n - 1 && y == m - 1) return 1;
  int& r = dp[x][y][last];
  if(r != -1) return r;
  r = 0;
  if(s[x][y] == '#') return r;
  if(last != 0) {
    r = solve(x + dx[last], y + dy[last], last);
  }
  for(int d = 1; d < D; d++) {
    r = (r + solve(x + dx[d], y + dy[d], d)) % Mod;
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, 0) << endl;
  return 0;
}
