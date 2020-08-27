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

const int N = 51;

int n, k;
int L[N], R[N];

ll calc(ll key) {
  ll cnt = 0;
  for(int i = 0; i < n; i++) {
    ll r = min(key - 1, (ll)R[i]);
    if(r >= L[i])
      cnt += r - L[i] + 1;
  }
  return cnt;
}

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> L[i] >> R[i];
  }
  ll lo = -2e9 - 5, hi = 2e9 + 5, best;
  while(lo <= hi) {
    ll mid = lo + (hi - lo) / 2;
    if(calc(mid) > k) {
      best = mid - 1;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << best << endl;
  return 0;
}
