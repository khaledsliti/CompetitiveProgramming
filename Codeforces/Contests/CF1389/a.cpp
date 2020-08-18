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


void solve() {
  int l, r;
  scanf("%d%d", &l, &r);
  int ans = -1, ans2;
  for(int d = 1; d * d <= r; d++) {
    if(r % d == 0) {
      if(d >= l && d < r) ans = d, ans2 = r;
      else if(r / d >= l && r / d < r) ans = r / d, ans2 = r;
    }
  }
  r--;
  for(int d = 1; d * d <= r; d++) {
    if(r % d == 0) {
      if(d >= l && d < r) ans = d, ans2 = r;
      else if(r / d >= l && r / d < r) ans = r / d, ans2 = r;
    }
  }
  if(ans == -1) cout << "-1 -1" << endl;
  else cout << ans << " " << ans2 << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
