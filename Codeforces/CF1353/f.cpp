// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 105;
const ll Inf = 1e18;

int n, m;
ll a[N][N];
ll dp1[N][N], dp2[N][N];

void init() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      dp1[i][j] = dp2[i][j] = -1;
}

ll solve1(int x, int y, ll cur) {
  if(x == 0 && y == 0) {
    if(a[x][y] < cur) return Inf;
    return a[x][y] - cur;
  }
  ll& r = dp1[x][y];
  if(a[x][y] < cur) return r = Inf;
  if(r != -1) return r;
  if(x && y) r = abs(a[x][y] - cur) + min(solve1(x - 1, y, cur - 1), solve1(x, y - 1, cur - 1));
  else if(x) r = abs(a[x][y] - cur) + solve1(x - 1, y, cur - 1);
  else r = abs(a[x][y] - cur) + solve1(x, y - 1, cur - 1);
  return r;
}

ll solve2(int x, int y, ll cur) {
  if(x == n - 1 && y == m - 1) {
    if(a[x][y] < cur) return Inf;
    return a[x][y] - cur;
  }
  ll& r = dp2[x][y];
  if(r != -1) return r;
  if(a[x][y] < cur) return r = Inf;
  if(x + 1 < n && y + 1 < m) r = abs(a[x][y] - cur) + min(solve2(x + 1, y, cur + 1), solve2(x, y + 1, cur + 1));
  else if(x + 1 < n) r = abs(a[x][y] - cur) + solve2(x + 1, y, cur + 1);
  else r = abs(a[x][y] - cur) + solve2(x, y + 1, cur + 1);
  return r;
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> a[i][j];
  ll best = 4e18;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      init();
      best = min(best, solve1(i, j, a[i][j]) + solve2(i, j, a[i][j]));
    }
  cout << best << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
