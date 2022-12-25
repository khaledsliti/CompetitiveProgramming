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
const int N = 307;
const int M = 1e5 + 5;

int n, m;
int dx[3];
int dy[3];
set<pair<int, int>> pts;
int dp[N][N][N][2];

int solve(int f, int s, int t, ll x, ll y, int bad) {
  if(f + s + t >= n) {
    return !bad;
  }
  int& r = dp[f][s][t][bad];
  if(r != -1) return r;
  r = 0;
  for(int i = 0; i < 3; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    int n_bad = bad || pts.find({nx, ny}) != pts.end();
    r += solve(f + (i == 0), s + (i == 1), t + (i == 2), nx, ny, n_bad);
    if(r > Mod) {
      r -= Mod;
    }
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < 3; i++) {
    cin >> dx[i] >> dy[i];
  }
  for(int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    pts.insert({x, y});
  }

  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, 0, 0, 0, 0) << endl;
  return 0;
}
