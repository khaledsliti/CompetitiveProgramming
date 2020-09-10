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

const int N = 4e5 + 5;

int n, q;
int arr[N][2];
vector<int> g[N];
int ans[N];

array<int, 2> qr[N];

struct DSU {
  vector<int> par, size;
  void init(int n) {
    par.clear(); size.clear();
    par.resize(n); size.resize(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  int find(int x) {
    return x == par[x] ? x : find(par[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(size[x] <= size[y]) {
      par[x] = y;
      g[y].push_back(x);
      size[y] += size[x];
    } else {
      par[y] = x;
      g[x].push_back(y);
      size[x] += size[y];
    }
    return true;
  }
};

DSU d;

void dfs(int u, int col) {
  ans[u] = col;
  for(int v: g[u]) {
    dfs(v, col);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  multiset<array<int, 2>> edge;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 2; j++) {
      cin >> arr[i][j];
      if(~arr[i][j]) {
        arr[i][j]--;
        edge.insert({min(i, arr[i][j]), max(i, arr[i][j])});
      }
    }
  }

  for(int i = 0; i < q; i++) {
    int u, t;
    cin >> u >> t;
    --u, --t;
    int v = arr[u][t];
    if(u > v) swap(u, v);
    qr[i] = {u, v};
    edge.erase(edge.find({u, v}));
  }

  d.init(n);

  for(auto e: edge) {
    d.unite(e[0], e[1]);
  }

  for(int i = 0; i < n; i++) {
    if(d.find(i) == d.find(0)) {
      ans[i] = -1;
    }
  }

  for(int i = q - 1; i >= 0; i--) {
    int u = qr[i][0], v = qr[i][1];
    int pu = d.find(u), pv = d.find(v);
    if(pu == pv) continue;
    if(pu == d.find(0)) {
      dfs(pv, i);
    } else if(pv == d.find(0)) {
      dfs(pu, i);
    }
    d.unite(u, v);
  }

  for(int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  
  return 0;
}
