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

struct DSU {
  vector<int> par;
  int cnt;
  void init(int n) {
    par.clear();
    par.resize(n);
    cnt = n;
    iota(par.begin(), par.end(), 0);
  }
  int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
      par[x] = y;
      cnt--;
      return true;
    }
    return false;
  }
};


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edges;
  for(int i = 0; i < m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    edges.push_back({c, --x, --y});
  }
  int l = 0, r = 1e4, ans = 0;
  while(l <= r) {
    int mid = (l + r) >> 1;
    DSU d;
    d.init(n);
    for(int i = 0; i < m && d.cnt > 1; i++) {
      int c = edges[i][0], x = edges[i][1], y = edges[i][2];
      if(c > mid) continue;
      d.unite(x, y);
    }
    if(d.cnt == 1) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
