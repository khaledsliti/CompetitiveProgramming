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

ll T(ll n) {
  return n * (n + 1) / 2;
}

ll P(ll n) {
  return n * (3 * n - 1) / 2;
}

ll H(ll n) {
  return n * (2 * n - 1);
}

bool isPentagonal(ll x) {
  ll n = (1 + sqrt(1 + 24 * x)) / 6;
  return P(n) == x;
}

bool isHexagonal(ll x) {
  ll n = (1 + sqrt(1 + 8 * x)) / 4;
  return H(n) == x;
}

bool check(int n) {
  return isPentagonal(T(n)) && isHexagonal(T(n));
}

int main()
{
  for(int i = 286; ; i++) {
    if(check(i)) {
      cout << T(i) << endl;
      break;
    }
  }
  return 0;
}
