// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main()
{
  int t;
  cin >> t;
  while(t--) {
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = 1e18, ans = -1;
    while(l <= r) {
      ll mid = (l + r) / 2;
      ll cnt = mid - (mid / n);
      if(cnt >= k) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
