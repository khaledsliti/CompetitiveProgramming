#include <iostream>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)



int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    if(__builtin_popcount(n) == 1) {
      cout << -1 << endl;
      continue;
    }
    long long ans = 0;
    int cur = 1;
    while(n > 0) {
      ans += 1LL * (n + 1) / 2 * cur;
      cur <<= 1;
      n >>= 1;
    }
    cout << ans - 1 << endl;
  }
  return 0;
}
