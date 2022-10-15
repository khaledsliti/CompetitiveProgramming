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

const int N = 3005;
const int INF = 1e9 + 5;
const long long LLINF = 1e18;

struct Item{
  int pos, idx;
  bool isWall;
};

int n, x;
Item a[N];
int target;
int keyPos[N];

long long dp[N][N][2];

long long solve(int l, int r, int onLeft) {
  if(target >= l && target <= r) {
    return 0;
  }
  long long& res = dp[l][r][onLeft];
  if(res != -1) {
    return res;
  }
  res = LLINF;
  int curPos = onLeft ? a[l].pos : a[r].pos;

  if (l > 0) {
    if(a[l - 1].isWall) {
      int wantKeyPos = keyPos[a[l - 1].idx];
      if(wantKeyPos >= a[l].pos && wantKeyPos <= a[r].pos) {
        res = min(res, curPos - a[l - 1].pos + solve(l - 1, r, 1));
      }
    } else {
      res = min(res, curPos - a[l - 1].pos + solve(l - 1, r, 1));
    }
  }

  if (r < 2 * n + 1) {
    if(a[r + 1].isWall) {
      int wantKeyPos = keyPos[a[r + 1].idx];
      if(wantKeyPos >= a[l].pos && wantKeyPos <= a[r].pos) {
        res = min(res, a[r + 1].pos - curPos + solve(l, r + 1, 0));
      }
    } else {
      res = min(res, a[r + 1].pos - curPos + solve(l, r + 1, 0));
    }
  }

  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    int p; cin >> p;
    a[i] = {p, i, 1};
  }
  for(int i = 0; i < n; i++) {
    int p; cin >> p;
    a[n + i] = {p, i, 0};
    keyPos[i] = p;
  }
  a[2 * n] = {x, n, 0};
  a[2 * n + 1] = {0, n, 0};
  
  sort(a, a + 2 * n + 2, [](const Item& a, const Item& b) {
    return a.pos < b.pos;
  });

  // for(int i = 0; i < 2 * n + 2; i++) {
  //   cout << a[i].pos << " " << a[i].isWall << " " << a[i].idx << endl;
  // } 

  int src;
  for(int i = 0; i < 2 * n + 2; i++) {
    if(a[i].pos == 0) {
      src = i;
    } else if(a[i].pos == x) {
      target = i;
    }
  }

  // cout << target << " " << src << endl;

  memset(dp, -1, sizeof dp);
  auto ans = solve(src, src, 0);
  if(ans >= LLINF) ans = -1;
  cout << ans << endl;

  return 0;
}
