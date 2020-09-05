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
  int a, b, x, y, n;
  cin >> a >> b >> x >> y >> n;
  ll best = 1e18;
  for(int it = 0; it < 2; it++) {
    if(a - x >= n) {
      best = min(best, 1LL * (a - n) * b);
    } else {
      int c = max(y, b - (n - (a - x)));
      best = min(best, 1LL * x * c);
    }
    swap(a, b);
    swap(x, y);
  }
  cout << best << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
