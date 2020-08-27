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

const int N = 1e5;

ll n, k;
ll a[N], b[N];

ll calc(ll sum) {
  ll cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt += lower_bound(b, b + n, sum - a[i] + 1) - b;
  }
  return cnt;
}

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(b, b + n);
  ll lo = 2, hi = 2e9, best;
  while(lo <= hi) {
    ll mid = lo + (hi - lo) / 2;
    if(calc(mid) >= k) {
      best = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << best << endl;
  return 0;
}
