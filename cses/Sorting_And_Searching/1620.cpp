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

const int N = 2e5 + 5;
const ll Inf = 1e18;

int n, t;
int k[N];

ll calc(ll mx_time) {
  ll sum = 0;
  for(int i = 0; i < n; i++) {
    sum = min(Inf, sum + mx_time / k[i]);
  }
  return sum;
}

int main()
{
  cin >> n >> t;
  for(int i = 0; i < n; i++)
    cin >> k[i];
  ll l = 0, r = 1e18, ans = 0;
  while(l <= r) {
    ll mid = (l + r) / 2;
    if(calc(mid) >= t) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
