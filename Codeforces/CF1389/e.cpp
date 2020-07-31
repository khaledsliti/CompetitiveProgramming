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

int m, d, w;

void solve() {
  scanf("%d%d%d", &m, &d, &w);
  if(d == 1) {
    printf("%d\n", 0);
    return;
  }
  // vector<int> div;
  // for(int i = 1; i * i <= w; i++) {
  //   if(w % i == 0) {
  //     div.push_back(i);
  //     if(w / i != i)
  //       div.push_back(w / i);
  //   }
  // }
  int g = __gcd(w, d - 1);
  int mn = min(w, d);
  int q = w / g;
  ll ans = 0;
  for(ll i = q; i <= (mn - 1); i += q) {
    ans += mn - 1 - i + 1;
  }
  cout << ans << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
