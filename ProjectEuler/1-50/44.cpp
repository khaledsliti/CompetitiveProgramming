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

ll P(ll n) {
  return n * (3 * n - 1) / 2;
}

bool isPentagonal(ll x) {
  ll e = (1.0 + sqrt(1 + 24 * x)) / 6.0;
  return P(e) == x;
}

int main()
{
  ll best = 1e18;
  for(int i = 1; i <= 5000 ; i++) {
    for(int j = 1; j < i; j++) {
      ll a = P(j), b = P(i);
      if(isPentagonal(b - a) && isPentagonal(a + b)) {
        best = min(best, b - a);
      }
    }
  }
  cout << best << endl;
  return 0;
}
