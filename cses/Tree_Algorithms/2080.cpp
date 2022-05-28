#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
 
const int N = 3e5 + 5;

template<typename T>
class fenwick {
  vector<T> fen;
  int n;
  void addPr(int x, T v) {
    for(int i = x; i < n; i += i & -i) {
      fen[i] += v;
    }
  }
  T getPr(int x) {
    T v{};
    for(int i = x; i > 0; i -= i & -i) {
      v += fen[i];
    }
    return v;
  }
public:
  fenwick(int _n) : n(_n + 1) {
    fen.resize(n, T());
  }
  void add(int x, T v) {
    addPr(x + 1, v);
  }
  T get(int x) {
    return getPr(x + 1);
  }
  T get(int l, int r) {
    return get(r) - get(l - 1);
  }
};
 
int n, k1, k2;

struct Solution {
  int k;
  long long ans;
  vector<set<int>> g;
  vector<int> sub;

  Solution(int k, const vector<pair<int, int>>& edges) : k(k) {
    g.resize(n), sub.resize(n);
    for(int i = 0; i < sz(edges); i++) {
      int a = edges[i].first;
      int b = edges[i].second;
      g[a].insert(b);
      swap(a, b);
      g[a].insert(b);
    }
    ans = 0;
    solve(0);
  }
  
  void calcSubTreeSize(int u, int p) {
    sub[u] = 1;
    for(int v: g[u]) {
      if(v != p) {
        calcSubTreeSize(v, u);
        sub[u] += sub[v];
      }
    }
  }
  
  int getCentroid(int u, int p, int tot) {
    for(int v: g[u]) {
      if(v != p && 2 * sub[v] > tot) {
        return getCentroid(v, u, tot);
      }
    }
    return u;
  }
  
  void add(int u, int p, int cur_lev, fenwick<int>& fen) {
    fen.add(cur_lev, 1);
    for(int v: g[u]) {
      if(v != p) {
        add(v, u, cur_lev + 1, fen);
      }
    }
  }
  
  void calc(int u, int p, int tot, int cur_lev, fenwick<int>& fen) {
    if(cur_lev > k) {
      return;
    }
    int x = k - cur_lev;
    if(x < tot) {
      ans += fen.get(x);
    }
    for(int v: g[u]) {
      if(v != p) {
        calc(v, u, tot, cur_lev + 1, fen);
      }
    }
  }
  
  void calcPaths(int root, int tot) {
    fenwick<int> fen(tot);
    for(int u: g[root]) {
      calc(u, root, tot, 1, fen);
      add(u, root, 1, fen);
    }
    if(k < tot) {
      ans += fen.get(k);
    }
  }

  void solve(int node) {
    calcSubTreeSize(node, -1);
    int c = getCentroid(node, -1, sub[node]);
    calcPaths(c, sub[node]);
    cerr D(c + 1) D(ans);
    vector<int> nxt(g[c].begin(), g[c].end());
    for(int u: nxt) {
      g[c].erase(u);
      g[u].erase(c);
      solve(u);
    }
  }
};
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k1 >> k2;
  vector<pair<int, int>> edges;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edges.push_back({a, b});
  }

  Solution s1(k1 - 1, edges);
  // Solution s2(k2, edges);
  // cerr D(s1.ans) D(s2.ans);
  // cout << s2.ans - s1.ans << endl;
  return 0;
}
