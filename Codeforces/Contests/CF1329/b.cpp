// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve() {
  int d, m;
  cin >> d >> m;
  int ans = 1;
  int len = 1;
  while(d > 0) {
    int cur = min(len, d);
    ans = (1LL * ans * (cur + 1)) % m;
    d -= len;
    len <<= 1;
  }
  ans = (ans + m - 1) % m;
  cout << ans << endl;
}

int main()
{
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
