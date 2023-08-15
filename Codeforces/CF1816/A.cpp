// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

void Solve() {
  int a, b;
  cin >> a >> b;
  if (__gcd(a, b) == 1) {
    cout << 1 << endl;
    cout << a << " " << b << endl;
  } else {
    cout << 2 << endl;
    cout << 1 << " " << b - 1 << endl;
    cout << a << " " << b << endl;
  }
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
