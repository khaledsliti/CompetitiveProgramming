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
  ll n, w, h;
  cin >> w >> h >> n;
  ll l = max(w, h), r = n * max(w, h), ans = -1;
  while(l <= r) {
    ll mid = (l + r) / 2;
    ll a = mid / h;
    ll b = mid / w;
    if((n % b == 0 && a >= n / b) || a > n / b) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  assert(ans != -1);
  cout << ans << endl;
  return 0;
}
