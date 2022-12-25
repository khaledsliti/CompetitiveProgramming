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

const int N = 2e5 + 5;
const int E = 4e5 + 5;

#include <bits/stdc++.h>
using namespace std;

template<int N>
struct DSU {
  int n;
  int par[N], size[N];
  int comp;
  void init(int _n) {
    n = _n;
    for(int i = 0; i < n; i++) {
      par[i] = i;
      size[i] = 1;
    }
    comp = n;
  }
  int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
  }
  int getSize(int x) {
    return size[find(x)];
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
      par[x] = y;
      size[y] += size[x];
      comp--;
      return true;
    }
    return false;
  }
};


int n;
vector<int> g[N];
DSU<N> dsu, qr;
int vis[N], fr[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  dsu.init(n);
  int src, dst;
  for(int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if(dsu.unite(u, v)) {
      g[u].push_back(v);
      swap(u, v);
      g[u].push_back(v);
    } else {
      src = u, dst = v;
    }
  }
  queue<int> q;
  q.push(src);
  memset(vis, 0, sizeof vis);
  memset(fr, -1, sizeof fr);
  vis[src] = 1;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int v: g[u]) {
      if(vis[v] == 0) {
        fr[v] = u;
        vis[v] = 1;
        q.push(v);
      }
    }
  }
  set<pair<int, int>> notOk;
  while(dst != -1) {
    int p = fr[dst];
    if(p != -1) {
      notOk.insert({p, dst});
      notOk.insert({dst, p});
    }
    dst = p;
  }
  qr.init(n);
  for(int u = 0; u < n; u++) {
    for(int v : g[u]) {
      if(notOk.find({u, v}) == notOk.end()) {
        qr.unite(u, v);
      }
    }
  }
  int qs;
  cin >> qs;
  while(qs--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if(qr.find(u) == qr.find(v)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
