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

int main()
{
  int n;
  cin >> n;
  ll ans = -1e18, cur = 0;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cur += a;
    ans = max(ans, cur);
    if(cur < 0) cur = 0;
  }
  cout << ans << endl;
  return 0;
}
