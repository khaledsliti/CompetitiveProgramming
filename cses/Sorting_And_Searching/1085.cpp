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

int n, k;
int arr[N];

int main()
{
  cin >> n >> k;
  ll l = 0, r = 1e18, best = 0;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    l = max(l, (ll)arr[i]);
  }
  while(l <= r) {
    ll mid = (l + r) / 2;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      cnt++;
      int j = i;
      ll cur_sum = 0;
      while(j < n && cur_sum + arr[j] <= mid)
        cur_sum += arr[j++];
      i = j - 1;
    }
    if(cnt <= k) {
      best = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << best << endl;
  return 0;
}
