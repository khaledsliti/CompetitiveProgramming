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

const int L = 41;

ll x, y, l, r;

ll f(ll x, ll y, ll z) {
  return (x & z) * (y & z);
}

void maxi(ll& cur, ll z, ll& ans) {
  ll newVal = f(x, y, z);
  if(newVal > cur || newVal == cur && ans > z) {
    cur = newVal;
    ans = z;
  }
}

ll get(ll v, int r) {
  if(r < 0) return 0;
  return v & ((1LL << (r + 1)) - 1);
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> x >> y >> l >> r;
    ll best = f(x, y, l);
    ll At = l;
    maxi(best, r, At);
    for(int i = L; i >= 0; i--) {
      if(!((l >> i) & 1) && (1LL << i) <= r) {
        ll lo = (l & ~((1LL << i) - 1)) | (1LL << i);
        ll hi = lo | ((1LL << i) - 1);
        if(lo > r) continue;
        maxi(best, lo, At);
        if(hi <= r) {
          ll z = lo | get(x | y, i - 1);
          maxi(best, z, At);
        } else {
          for(int j = i - 1; j >= 0; j--) {
            if(r & (1LL << j)) {
              ll z = (r & ~((1LL << (j + 1)) - 1)) | get(x | y, j - 1);
              maxi(best, z, At);
              best = max(best, f(x, y, z));
            }
          }
        }
      }
    }
    cout << At << endl;
  }
  return 0;
}
