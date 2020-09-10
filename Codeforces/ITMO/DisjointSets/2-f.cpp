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

const int N = 1e4 + 5;

struct DSU {
  vector<int> par;
  int cnt = 0;
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

int n, m;
vector<array<int, 3>> edge;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    --x, --y;
    edge.push_back({c, x, y});
  }


  sort(all(edge));
  const int Inf = 2e9 + 5;
  int diff = Inf;

  for(int i = 0; i < m; i++) {
    DSU d;
    d.init(n);
    int mx = -1e9 - 5;
    ll mst = 0;
    for(int j = i; j < m; j++) {
      int x = edge[j][1], y = edge[j][2], c = edge[j][0];
      if(d.find(x) == d.find(y)) continue;
      d.unite(x, y);
      mst += c;
      mx = c;
    }
    if(d.cnt != 1) continue;
    diff = min(diff, mx - edge[i][0]);
  }
  if(diff < Inf) cout << "YES\n" << diff << endl;
  else cout << "NO" << endl;
  return 0;
}
