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

void solve() {
  ll x, y;
  cin >> x >> y;
  ll c[9];
  for(int i = 1; i <= 6; i++) {
    cin >> c[i];
  }
  for(int it = 0; it < 100; it++) {
    c[6] = min(c[6], c[1] + c[5]);
    c[2] = min(c[2], c[1] + c[3]);
    c[3] = min(c[3], c[4] + c[2]);
    c[5] = min(c[5], c[4] + c[6]);
  }
  ll ans;
  if(x >= 0 && y <= 0) {
    ans = abs(x) * c[6] + abs(y) * c[5];
  } else if(x <= 0 && y >= 0) {
    ans = abs(x) * c[3] + abs(y) * c[2];
  } else if(x > 0 && y > 0) {
    ans = abs(x) * c[6] + abs(y) * c[2];
    if(abs(x) >= abs(y)) {
      ans = min(ans, abs(y) * c[1] + (abs(x) - abs(y)) * c[6]);
    } else {
      ans = min(ans, abs(x) * c[1] + (abs(y) - abs(x)) * c[2]);
    }
  } else {
    ans = abs(x) * c[3] + abs(y) * c[5];
    if(abs(x) >= abs(y)) {
      ans = min(ans, abs(y) * c[4] + (abs(x) - abs(y)) * c[3]);
    } else {
      ans = min(ans, abs(x) * c[4] + (abs(y) - abs(x)) * c[5]);
    }
  }

  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
