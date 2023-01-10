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

int main() {
  long long n;
  int k;
  cin >> n >> k;
  vector<long long> p(k);
  for (int i = 0; i < k; i++) {
    cin >> p[i];
  }

  long long ans = 0;
  for (int mask = 1; mask < (1 << k); mask++) {
    long long num = 1;
    int s = 0;
    bool good = true;
    for (int i = 0; i < k; i++) {
      if (mask & (1 << i)) {
        if (num > n / p[i]) {
          good = false;
          break;
        }
        num *= p[i];
        s++;
      }
    }
    if (!good) {
      continue;
    }
    long long cnt = n / num;
    if (s & 1) {
      ans += cnt;
    } else {
      ans -= cnt;
    }
  }
  cout << ans << endl;
  return 0;
}
