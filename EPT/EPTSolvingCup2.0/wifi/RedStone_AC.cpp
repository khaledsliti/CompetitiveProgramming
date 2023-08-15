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

void solve() {
  int n, d;
  cin >> n >> d;
  vector<pair<double, double>> v;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    double delta = sqrt(1LL * d * d - 1LL * y * y);
    v.push_back({x - delta, x + delta});
  }
  sort(all(v));
  int ans = 1;
  double right = v[0].second;
  for (int i = 1; i < n; i ++) {
    if (v[i].first <= right) {
      right = min(right, v[i].second);
      continue;
    }
    ans++;
    right = v[i].second;
  }
  cout << ans << endl;
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
