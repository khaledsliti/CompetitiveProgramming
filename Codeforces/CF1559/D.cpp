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

const int N = 1007;

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

int n;
DSU a, b;

void solve() {
  int m1, m2;
  cin >> n >> m1 >> m2;
  a.init(n), b.init(n);
  while(m1--) {
    int u, v;
    cin >> u >> v;
    a.unite(--u, --v);
  }
  while(m2--) {
    int u, v;
    cin >> u >> v;
    b.unite(--u, --v);
  }
  vector<pair<int, int>> edges;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      bool ok = a.find(i) != a.find(j);
      ok &= b.find(i) != b.find(j);
      if(ok) {
        edges.push_back({i, j});
      }
    }
  }

  vector<pair<int, int>> ans;
  for(auto e: edges) {
    if(a.find(e.first) != a.find(e.second) && b.find(e.first) != b.find(e.second)) {
      a.unite(e.first, e.second);
      b.unite(e.first, e.second);
      ans.push_back(e);
    }
  }

  cout << sz(ans) << endl;
  for(auto e: ans) {
    cout << e.first + 1 << " " << e.second + 1 << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  while(T--) {
    solve();
  }
  return 0;
}
