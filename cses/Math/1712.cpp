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

const int Mod = 1e9 + 7;

ll mpow(ll a, ll b, ll mod) {
  ll r = 1;
  while(b) {
    if(b & 1) r = (r * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return r;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << mpow(a, mpow(b, c, Mod - 1), Mod) << endl;
  }
  return 0;
}
