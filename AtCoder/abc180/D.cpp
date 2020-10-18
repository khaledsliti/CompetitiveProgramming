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



int main()
{
  ll x, y, a, b;
  cin >> x >> y >> a >> b;
  ll ans = 0;
  for(int t = 0; ; t++) {
    ll v = (y - x - 1) / b;
    ans = max(ans, t + v);
    if(x < (y - 1) / a) {
      x *= a;
    } else {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
