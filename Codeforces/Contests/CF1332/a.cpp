// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

bool solve(int x1, int x2, int x, int l, int r) {
  if(l + r <= 0) return true;
  if(x1 == x2) return false;
  int v = min(l, r);
  l -= v; r -= v;
  return x - l >= x1 && x + r <= x2;
}

void solve() {
  int a, b, c, d;
  int x, x1, x2, y, y1, y2;
  cin >> a >> b >> c >> d;
  cin >> x >> y >> x1 >> y1 >> x2 >> y2;
  if(solve(x1, x2, x, a, b) && solve(y1, y2, y, c, d)) cout << "Yes" << endl;
  else cout << "No" << endl;
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
