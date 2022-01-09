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
    if(l > r) return T();
    return get(r) - get(l - 1);
  }
};

const int A = 26;
const ll INF = 1e18;
const int N = 1e5 + 5;

void solve() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  vector<int> pos[A];
  for(int i = 0; i < n; i++) {
    pos[s[i] - 'a'].push_back(i);
  }
  for(int i = 0; i < A; i++) {
    reverse(all(pos[i]));
  }
  fenwick<int> f(n);
  for(int i = 0; i < n; i++) {
    f.add(i, 1);
  }
  ll ans = INF, cur_cost = 0;
  for(int i = 0; i < n; i++) {
    int refr = t[i] - 'a';
    // take lower
    for(int j = 0; j < refr; j++) {
      if(sz(pos[j]) > 0) {
        int idx = pos[j].back();
        ans = min(ans, cur_cost + f.get(idx - 1));
      }
    }
    // make equal
    if(sz(pos[refr]) == 0) {
      break;
    }
    int idx = pos[refr].back();
    pos[refr].pop_back();
    cur_cost += f.get(idx - 1);
    f.add(idx, -1);
  }
  if(ans >= INF) ans = -1;
  std::cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
