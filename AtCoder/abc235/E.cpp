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

const int N = 2e5 + 5;

struct Edge {
  int u, v, c, index;
  bool operator<(const Edge& rhs) const {
    return c < rhs.c;
  }
};

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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<Edge> edges(m);
  for(int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v;
    edges[i] = {u, v, c, 0};
  }
  sort(all(edges));
  DSU dsu;
  dsu.init(n);
  vector<bool> ans(q);
  vector<Edge> queries(q);
  for(int i = 0; i < q; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v;
    queries[i] = {u, v, c, i};
  }
  sort(all(queries));
  int e_idx = 0;
  for(int i = 0; i < q; i++) {
    while(e_idx < m && edges[e_idx].c < queries[i].c) {
      dsu.unite(edges[e_idx].u, edges[e_idx].v);
      e_idx++;
    }
    ans[queries[i].index] = dsu.find(queries[i].u) != dsu.find(queries[i].v);
  }

  for(int i = 0; i < q; i++) {
    cout << (ans[i] ? "Yes" : "No") << endl;
  }

  return 0;
}
