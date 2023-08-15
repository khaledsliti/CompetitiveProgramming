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

void Solve() {
  int n, m;
  cin >> n >> m;
  pair<int, int> a, b;
  cin >> a.first >> a.second;
  cin >> b.first >> b.second;
  if (n == 1 || m == 1) {
    cout << 1 << endl;
    return;
  }
  int ans = 4;
  for (auto p : {a, b}) {
    if (p == mp(1, 1) || p == mp(1, m) || p == mp(n, 1) || p == mp(n, m)) {
      ans = min(ans, 2);
    }
    if (p.first == 1 || p.first == n || p.second == 1 || p.second == m) {
      ans = min(ans, 3);
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    Solve();
  }
  return 0;
}
