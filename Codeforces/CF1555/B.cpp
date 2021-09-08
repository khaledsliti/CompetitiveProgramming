// Guess Who's Back
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
  int W, H, w, h;
  int x1, x2, y1, y2;
  cin >> W >> H;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> w >> h;

  int dx = x2 - x1, dy = y2 - y1;
  if(W < w + dx && H < h + dy) {
    cout << -1 << endl;
    return;
  }
  int ans = INT_MAX;

  if(W >= w + dx) {
    ans = min(ans, max(0, -(x1 - w)));
    ans = min(ans, max(0, -W + (x2 + w)));
  }

  if(H >= h + dy) {
    ans = min(ans, max(0, -(y1 - h)));
    ans = min(ans, max(0, -H + (y2 + h)));
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
