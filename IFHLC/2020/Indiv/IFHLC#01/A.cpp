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

ll n, m, x, y;

bool check(ll take) {
  ll tot = (m - take) * y + n;
  // cout << tot << endl;
  ll q = (tot - x) / (x - y);
  q++;
  // cerr << q << endl;
  ll r = tot - q * (x - y);
  return q >= take;
}

void solve() {
  cin >> n >> m >> x >> y;
  if(x <= y) {
    cout << m << endl;
    return;
  }

  // cout << check(6) << endl;
  // return;

  ll l = 0, r = m, ans = 0;
  while(l <= r) {
    ll mid = l + (r - l) / 2;
    if(check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
