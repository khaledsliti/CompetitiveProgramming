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

ll n, sum;
ll ten[20];

int get(ll n) {
  int r = 0;
  while(n > 0) {
    r += n % 10;
    n /= 10;
  }
  return r;
}

void solve() {
  cin >> n >> sum;
  if(get(n) <= sum) {
    cout << 0 << endl;
    return;
  }
  ll best = 1e18;
  for(int i = 0; i < 19; i++) {
    ll x = n / ten[i] * ten[i] + ten[i];
    if(get(x) <= sum) {
      best = min(best, x - n);
    }
  }
  cout << best << endl;
}

int main()
{
  ten[0] = 1;
  for(int i = 1; i < 19; i++) {
    ten[i] = ten[i - 1] * 10;
  }
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
