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

int solve(int n, int k) {
  if (n == 1) {
    return 1;
  }
  if (k <= (n + 1) / 2) {
    if (2 * k > n) {
      return 1;
    }
    return 2 * k;
  }
  int ret = solve(n >> 1, k - (n + 1) / 2);
  if (n & 1) {
    return 2 * ret + 1;
  }
  return 2 * ret - 1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
  }
  return 0;
}
