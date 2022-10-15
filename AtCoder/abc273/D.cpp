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



int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int h, w;
  cin >> h >> w;
  int x, y; cin >> x >> y;
  --x, --y;
  int n; cin >> n;
  map<int, vector<int>> row, col;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    row[x].push_back(y);
    col[y].push_back(x);
  }

  for(auto& x : row) {
    sort(all(x.second));
  }
  for(auto& y : col) {
    sort(all(y.second));
  }

  auto go = [&](int x, int y, char d, int l) -> pair<int, int> {
    if (d == 'L' || d == 'R') {
      auto& r = row[x];
      if (d == 'L') {
        auto it = lower_bound(all(r), y);
        if (it == r.begin()) {
          return mp(x, max(0, y - l));
        }
        --it;
        return mp(x, max(*it + 1, y - l));
      } else {
        auto it = lower_bound(all(r), y);
        if(it == r.end()) {
          return mp(x, min(w - 1, y + l));
        }
        return mp(x, min(*it - 1, y + l));
      }
    } else {
      auto& c = col[y];
      if (d == 'U') {
        auto it = lower_bound(all(c), x);
        if (it == c.begin()) {
          return mp(max(0, x - l), y);
        }
        --it;
        return mp(max(*it + 1, x - l), y);
      } else {
        auto it = lower_bound(all(c), x);
        if(it == c.end()) {
          return mp(min(h - 1, x + l), y);
        }
        return mp(min(*it - 1, x + l), y);
      }
    }
  };

  int q; cin >> q;
  while(q--) {
    char d;
    int l;
    cin >> d >> l;
    tie(x, y) = go(x, y, d, l);
    cout << x + 1 << " " << y + 1 << endl;
  }
  return 0;
}
