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

struct DSU {
  vector<int> par;
  void init(int n) {
    par.clear();
    par.resize(n);
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
      return true;
    }
    return false;
  }
};

int e, n;
map<string, int> id;
vector<array<int, 4>> edges;
vector<bool> ok;
vector<int> up;
DSU dsu;

int solve(int msk) {
  int ret = 0;
  vector<int> good(n, 0);
  for(int i = 0; i < sz(up); i++) {
    if(msk & (1 << i)) {
      good[up[i]] = 1;
      ret += 10'000;
    }
  }
  dsu.init(n);
  int g = n;
  for(int i = 0; i < e; i++) {
    int a = edges[i][1];
    int b = edges[i][2];
    int c = edges[i][0];
    int h = edges[i][3];
    if(h && !good[a] && !good[b]) {
      continue;
    }
    if (dsu.unite(a, b)) {
      ret += c;
      g--;
    }
  }
  if (g > 1) {
    return INT_MAX;
  }
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> e;
  for(int i = 0; i < e; i++) {
    string a, b;
    int c, h;
    cin >> a >> b >> c >> h;
    if(!id.count(a)) {
      id[a] = n++;
    }
    if(!id.count(b)) {
      id[b] = n++;
    }
    edges.push_back({c, id[a], id[b], h});
    if (h) {
      up.push_back(id[a]);
      up.push_back(id[b]);
    }
  }

  sort(all(up));
  up.resize(unique(all(up)) - begin(up));

  sort(all(edges));

  int ans = INT_MAX;
  for (int msk = 0; msk < (1 << sz(up)); msk++) {
    ans = min(ans, solve(msk));
  }
  cout << ans << endl;
  return 0;
}
