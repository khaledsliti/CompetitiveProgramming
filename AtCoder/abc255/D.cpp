// RedStone
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

const int N = 2e5 + 5;

int n, q;
int arr[N];
ll pref[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for(int i = 0; i < n; i++) {
    pref[i] = arr[i];
    if(i > 0) {
      pref[i ] += pref[i - 1];
    }
  }
  while(q--) {
    int x; cin >> x;
    int idx = lower_bound(arr, arr + n, x) - arr;
    ll ans = 0;
    if(idx > 0) {
      ans += 1LL * x * idx - pref[idx - 1];
    }
    if(idx < n) {
      ans += (pref[n - 1] - (idx > 0 ? pref[idx - 1] : 0)) - 1LL * (n - idx) * x;
    }
    cout << ans << endl;
  }
  return 0;
}
