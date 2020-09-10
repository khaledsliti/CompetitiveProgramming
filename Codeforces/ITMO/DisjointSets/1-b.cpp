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
  vector<int> mn, mx, cnt;
  void init(int n) {
    par.clear(); mn.clear(), mx.clear(), cnt.clear();
    par.resize(n), mn.resize(n), mx.resize(n), cnt.resize(n);
    for(int i = 0; i < n; i++) {
      par[i] = i;
      mn[i] = mx[i] = i;
      cnt[i] = 1;
    }
  }
  int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
      par[x] = y;
      cnt[y] += cnt[x];
      mx[y] = max(mx[y], mx[x]);
      mn[y] = min(mn[y], mn[x]);
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
  d.init(n + 1);
  for(int i = 0; i < q; i++) {
    string t;
    int x, y;
    cin >> t;
    if(t[0] == 'u') {
      cin >> x >> y;
      d.unite(x, y);
    } else {
      cin >> x;
      x = d.find(x);
      cout << d.mn[x] << " " << d.mx[x] << " " << d.cnt[x] << endl;
    }
  }
  return 0;
}
