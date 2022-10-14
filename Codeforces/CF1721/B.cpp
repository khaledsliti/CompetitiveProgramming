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

const int N = 1007;

int n, m;
int sx, sy;

void solve() {
  int d;
  cin >> n >> m;
  cin >> sx >> sy >> d;
  --sx, --sy;
  auto dist = [&](int x, int y) {
    return abs(x - sx) + abs(y - sy);
  };
  bool poss = true;
  for(int i = 0; i < n; i++) {
    if(dist(i, 0) <= d) {
      poss = false;
      break;
    }
  }
  for(int j = 0; j < m; j++) {
    if(dist(n - 1, j) <= d) {
      poss = false;
      break;
    }
  }
  if(poss) {
    cout << n + m - 2 << endl;
    return;
  }
  poss = true;
  for(int j = 0; j < m; j++) {
    if(dist(0, j) <= d) {
      poss = false;
      break;
    }
  }
  for(int i = 0; i < n; i++) {
    if(dist(i, m - 1) <= d) {
      poss = false;
      break;
    }
  }
  if(poss) cout << n + m - 2 << endl;
  else cout << -1 << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
