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

int ask(int r, int c) {
  cout << "? " << r << " " << c << endl;
  int ret;
  cin >> ret;
  return ret;
}

void ans(int r, int c) {
  cout << "! " << r << " " << c << endl;
}

int n, m;


void Solve() {
  cin >> n >> m;
  int z = ask(1, 1);
  if (z == 0) {
    ans(1, 1);
    return;
  }
  z++;
  if (z > n) {
    int r = ask(n, z);
    ans(n - r, z);
    return;
  }
  if (z > m) {
    int r = ask(z, m);
    ans(z, m - r);
    return;
  }
  int r = ask(z, z);
  if (r == 0) {
    ans(z, z);
    return;
  }
  if (ask(z - r, z) == 0) {
    ans(z - r, z);
  } else {
    ans(z, z - r);
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
