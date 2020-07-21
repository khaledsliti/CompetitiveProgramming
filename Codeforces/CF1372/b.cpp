// We only fail when we stop trying
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

int n;

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    ll best = 1e18;
    ll a, b;
    for(int d = 1; d * d <= n; d++) {
      if(n % d == 0) {
        ll cur_a = d, cur_b = n - cur_a;
        ll lcm = cur_a / __gcd(cur_a, cur_b) * cur_b;
        if(lcm < best )  {
          best = lcm;
          a = cur_a, b = cur_b;
        }
        if(n / d != d && d != 1) {
          cur_a = n / d, cur_b = n - cur_a;
          ll lcm = cur_a / __gcd(cur_a, cur_b) * cur_b;
          if(lcm < best )  {
            best = lcm;
            a = cur_a, b = cur_b;
          }
        }
      }
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
