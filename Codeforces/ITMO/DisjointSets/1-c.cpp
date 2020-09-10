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

const int N = 3e5 + 5;

int n, q;

struct DSU {
  vector<int> par;
  vector<int> cost, size;
  void init(int n) {
    par.clear(); cost.clear(); size.clear();
    par.resize(n); cost.resize(n, 0); size.resize(n, 1);
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
      size[y] += size[x];
      cost[x] -= cost[y];
    } else {
      par[y] = x;
      size[x] += size[y];
      cost[y] -= cost[x];
    }
    return true;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;

  DSU d;
  d.init(n);

  while(q--) {
    string t;
    cin >> t;
    if(t[0] == 'a') {
      int x, v;
      cin >> x >> v;
      x = d.find(--x);
      d.cost[x] += v;
    } else if(t[0] == 'j') {
      int x, y;
      cin >> x >> y;
      d.unite(--x, --y);
    } else {
      int x;
      cin >> x; --x;
      int tot = 0;
      while(true) {
        tot += d.cost[x];
        if(x == d.par[x]) {
          break;
        } else {
          x = d.par[x];
        }
      }
      cout << tot << endl;
    }
  }
  return 0;
}
