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

int dist(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> pts = {{0, 0}, {0, m - 1}, {n - 1, 0}, {n - 1, m - 1}};
  int r = n / 2, c = m / 2;
  vector<pair<int, int>> v;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m ; j++) {
      v.push_back({i, j});
    }
  }
  sort(all(v), [&](pair<int, int>a, pair<int, int> b) {
    return dist(a, {r, c}) < dist(b, {r, c});
  });
  vector<int> ans;
  for(int i = 0; i < sz(v); i++) {
    auto cur = v[i];
    int a = 0;
    for(auto x: pts) {
      a = max(a, dist(cur, x));
    }
    ans.push_back(a);
  }
  sort(all(ans));
  for(int i = 0; i < sz(ans); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
