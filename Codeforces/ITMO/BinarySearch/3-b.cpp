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

const int N = 1e5 + 5;

int n, k;
int a[N];

bool check(ll sum) {
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] > sum) return false;
    ll cur = 0;
    int j = i;
    while(j < n && cur + a[j] <= sum) {
      cur += a[j++];
    }
    i = j - 1;
    cnt++;
  }
  return cnt <= k;
}

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n ; i++) {
    cin >> a[i];
  }
  ll lo = 0, hi = 1e16, best = -1;
  while(lo <= hi) {
    ll mid = lo + (hi - lo) / 2;
    if(check(mid)) {
      best = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << best << endl;
  return 0;
}
