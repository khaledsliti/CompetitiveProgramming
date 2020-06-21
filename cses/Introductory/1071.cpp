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



int main()
{
  int t;
  cin >> t;
  while(t--) {
    ll x, y;
    cin >> x >> y;
    ll mx = max(x, y);
    ll val = mx * (mx - 1) + 1;
    if(x < y) { // up
      int mult = (y & 1) ? 1 : -1;
      val += mult * (y - x);
    } else if(x > y) { // left
      int mult = (x & 1) ? -1 : 1;
      val += mult * (x - y);
    }
    cout << val << endl;
  }
  return 0;
}
