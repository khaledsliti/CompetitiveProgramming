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

array<ll, 2> get(ll x) {
  ll a = -1, b = 10;
  while(x > 0) {
    a = max(a, x%10);
    b = min(b, x%10);
    x /= 10;
  }
  return {a, b};
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    ll a, k;
    cin >> a >> k;
    --k;
    while(k--) {
      auto x = get(a);
      auto t = a + x[0] * x[1];
      if(t == a) break;
      a = t;
    }
    cout << a << endl;
  }
  return 0;
}
