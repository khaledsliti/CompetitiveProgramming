// RedStone
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

void Solve() {
  int w, d, h;
  cin >> w >> d >> h;
  int a, b, f, g;
  cin >> a >> b >> f >> g;
  int ans = INT_MAX;
  for (int it = 0; it < 2; it++) {
    ans = min(ans, h + abs(a - f) + min(b + g, 2 * d - b - g));
    swap(d, w);
    swap(a, b);
    swap(f, g);
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
    Solve();
  }
  return 0;
}
