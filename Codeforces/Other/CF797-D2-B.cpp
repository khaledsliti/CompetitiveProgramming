// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int n;
  cin >> n;
  int ans = 0, mn = 1e9, mx = -1e9;
  for(int i = 0 ; i < n ; i++) {
    int a; 
    cin >> a;
    if(a >= 0) ans += a;
    if(a > 0 && a % 2 == 1) mn = min(mn, a);
    else if(a < 0 && a % 2 == -1) mx = max(mx, a);
  }
  if(ans % 2 == 0)
    ans -= min(mn, -mx);
  cout << ans << endl;
  return 0;
}
