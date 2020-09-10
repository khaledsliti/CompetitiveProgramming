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

const int N = 150'001;

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

int n, m, k;
set<array<int, 2>> edge;
array<int, 3> qr[N];
vector<int> ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if(x > y) swap(x, y);
    edge.insert({--x, --y});
  }
  for(int i = 0; i < k; i++) {
    string t;
    int u, v;
    cin >> t >> u >> v;
    --u, --v;
    if(u > v) swap(u, v);
    if(t[0] == 'c') {
      edge.erase({u, v});
      qr[i] = {0, u, v};
    } else {
      qr[i] = {1, u, v};
    }
  }

  DSU d;
  d.init(n);
  for(auto e: edge) {
    d.unite(e[0], e[1]);
  }

  for(int i = k - 1; i >= 0; i--) {
    int t = qr[i][0], u = qr[i][1], v = qr[i][2];
    if(t == 0) {
      d.unite(u, v);
    } else {
      ans.push_back(d.find(u) == d.find(v));
    }
  }

  reverse(all(ans));
  for(int i = 0; i < sz(ans); i++) {
    if(ans[i]) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
