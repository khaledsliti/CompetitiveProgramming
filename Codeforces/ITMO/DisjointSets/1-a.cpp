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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, q;
  cin >> n >> q;

  DSU d;
  d.init(n);

  for(int i = 0; i < q; i++) {
    string t;
    cin >> t;
    if(t[0] == 'u') {
      int x, y;
      cin >> x >> y;
      d.unite(--x, --y);
    } else {
      int x, y;
      cin >> x >> y;
      if(d.find(--x) == d.find(--y)) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }

  return 0;
}
