// Guess Who's Back
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

const int N = 1e5 + 5;
const long long INF = 2e18;

int n, q;
ll arr[N];

bool check(ll val, ll k) {
  int idx = lower_bound(arr, arr + n, val + 1) - arr;
  if(val - idx >= k) return true;
  return false;
}

ll solve(ll k) {
  ll lo = 1, hi = INF, ans;
  while(lo <= hi) {
    ll mid = lo + (hi - lo) / 2;
    if(check(mid, k)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}

int main()
{
  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
  sort(arr, arr + n);
  while(q--) {
    ll k;
    scanf("%lld", &k);
    printf("%lld\n", solve(k));
  }
  return 0;
}
