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

const int N = 1e5 + 5;

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

int n, m;
ll s;

struct Edge {
  int a, b, c, idx;
  bool operator<(const Edge& other) {
    return c > other.c;
  }
} E[N];

int take[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n >> m >> s;
  ll tot = 0;
  for(int i = 0; i < m; i++) {
    cin >> E[i].a >> E[i].b >> E[i].c;
    --E[i].a; --E[i].b;
    E[i].idx = i;
    tot += E[i].c;
  }

  sort(E, E + m);

  DSU d;
  d.init(n);
  int ans = m;
  for(int i = 0; i < m; i++) {
    if(d.unite(E[i].a, E[i].b)) {
      tot -= E[i].c;
      take[E[i].idx] = 1;
      ans--;
    }
  }
  for(int i = 0; i < m; i++) {
    if(!take[E[i].idx] && tot > s) {
      take[E[i].idx] = 1;
      ans--;
      tot -= E[i].c;
    }
  }
  cout << ans << endl;
  for(int i = 0; i < m; i++) {
    if(!take[E[i].idx])
      cout << E[i].idx + 1 << " ";
  }
  cout << endl;
  return 0;
}
