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

int dist(int a, int b, int c, int d) {
  return abs(a - c) + abs(b - d);
}

void solve() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  x--, y--;
  vector<pair<int, int>> pts {{0, 0}, {0, m - 1}, {n - 1, 0}, {n - 1, m - 1}};
  long long ans = -1;
  int x1, x2, y1, y2;
  for(int i = 0; i < pts.size(); i++) {
    for(int j = i; j < pts.size(); j++) {
      long long cur = dist(x, y, pts[i].first, pts[i].second);
      cur += dist(pts[i].first, pts[i].second, pts[j].first, pts[j].second);
      cur += dist(pts[j].first, pts[j].second, x, y);
      if(cur > ans) {
        ans = cur;
        x1 = pts[i].first;
        y1 = pts[i].second;
        x2 = pts[j].first;
        y2 = pts[j].second;
      }
      ans = max(ans, cur);
    }
  }
  cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
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
