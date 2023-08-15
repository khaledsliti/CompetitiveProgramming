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

const int N = 1e5 + 67;

int n, m;
vector<int> ks;

void Solve() {
  cin >> n >> m;
  ks.clear();
  for (int i = 0; i < n; i++) {
    int cur_k;
    cin >> cur_k;
    ks.push_back(cur_k);
  }
  sort(all(ks));

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (1LL * a * c < 0) {
      cout << "NO" << endl;
      continue;
    }
    long long target = floor(b - sqrt(4LL * a * c));
    int idx = upper_bound(all(ks), target) - begin(ks);
    if (idx >= sz(ks)) {
      cout << "NO" << endl;
      continue;
    }
    int k = ks[idx];
    if (k >= b + sqrt(4LL * a * c)) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    cout << ks[idx] << endl;
  }
  cout << endl;
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
