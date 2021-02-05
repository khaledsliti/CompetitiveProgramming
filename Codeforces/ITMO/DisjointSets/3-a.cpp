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

struct dsu {
  int n;
  vector<pair<int, int>> history;
  vector<int> checkin_size;
  vector<int> par;
  vector<int> comp;

  dsu(int _n) : n(_n) {
    comp.push_back(n);
    for(int i = 0; i < n; i++) {
      par.push_back(i);
    }
    checkin_size.push_back(0);
  }

  int find(int x) {
    if(par[x] == x) return x;
    int p = find(par[x]);
    checkin_size.back()++;
    history.push_back({x, par[x]});
    return par[x] = p;
  }

  bool unite(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return false;
    checkin_size.back()++;
    comp.back()--;
    history.push_back({a, par[a]});
    par[a] = b;
    return true;
  }

  void checkin() {
    checkin_size.push_back(0);
    comp.push_back(comp.back());
  }

  void rollback() {
    if(!sz(checkin_size)) return;
    while(checkin_size.back()-- > 0) {
      int i = history.back().first, v = history.back().second;
      par[i] = v;
      history.pop_back();
    }
    checkin_size.pop_back();
    comp.pop_back();
  }

  int count() {
    return comp.back();
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, q;
  cin >> n >> q;
  dsu d(n);

  while(q--) {
    string t;
    cin >> t;
    if(t[0] == 'u') {
      int x, y;
      cin >> x >> y;
      --x, --y;
      d.unite(x, y);
      cout << d.count() << endl;
    } else if(t[0] == 'p') {
      d.checkin();
    } else {
      d.rollback();
      cout << d.count() << endl;
    }
  }
  return 0;
}
