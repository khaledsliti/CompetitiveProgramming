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
  int n;
  cin >> n;
  vector<int> a(n);
  int x = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x ^= a[i];
  }
  if (x == 0) {
    cout << 0 << endl;
    return;
  }
  if (n % 2 == 0) {
    cout << -1 << endl;
    return;
  }
  cout << x << endl;
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
