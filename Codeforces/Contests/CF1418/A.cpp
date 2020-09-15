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
  int T;
  cin >> T;
  while(T--) {
    ll x, y, k;
    cin >> x >> y >> k;
    ll t = (k - 1 + x - 2) / (x - 1);
    ll r = 1 + t * (x - 1) - k;
    if(r >= k * y) {
      cout << t + k << endl;
    } else {
      ll z = (k * y - r + x - 2) / (x - 1);
      cout << t + z + k << endl;
    }
  }
  return 0;
}
