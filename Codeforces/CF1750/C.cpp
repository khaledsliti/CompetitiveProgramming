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
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int o = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      o++;
    }
  }

  if (o < n && o > 0) {
    cout << "NO" << endl;
    return;
  }

  vector<pair<int, int>> sol;
  for (int i = 0; i < n; i++) {
    if (a[i] == '0') {
      sol.push_back({i, i});
    }
  }

  if (sz(sol) & 1) {
    o = n - o;
  }

  if (o == 0) {
    sol.push_back({0, 0});
    sol.push_back({1, n - 1});
  } else {
    sol.push_back({0, n - 1});
  }

  cout << "YES" << endl;
  cout << sz(sol) << endl;
  for (auto x : sol) {
    cout << x.first + 1 << " " << x.second + 1 << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
