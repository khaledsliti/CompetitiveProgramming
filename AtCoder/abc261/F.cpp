// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
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

int n;
int c[N], v[N];
int nxt[N], last[N];
int vis[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> c[i];
    c[i]--;
  }
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    v[i]--;
  }
  for(int i = 0; i <= n; i++) {
    last[i] = n;
  }
  for(int i = n - 1; i >= 0; i--) {
    nxt[i] = last[c[i]];
    last[c[i]] = i;
  }
  long long ans = 0;
  fenwick<int> fn(n);
  for(int i = 0; i < n; i++) {
    if(v[i] + 1 < n) {
      ans += fn.get(v[i] + 1, n - 1);
    }
    fn.add(v[i], 1);
  }
  for(int i = 0; i < n; i++) {
    fn.add(v[i], -1);
  }
  // for(int i = 0; i < n; i++) {
  //   cout << nxt[i] << " ";
  // }
  // cout << endl;
  for(int i = 0; i < n; i++) {
    if(vis[i]) continue;
    for(int j = i; j < n; j = nxt[j]) {
      if(v[j] + 1 < n) {
        ans -= fn.get(v[j] + 1, n - 1);
      }
      fn.add(v[j], 1);
    }
    for(int j = i; j < n; j = nxt[j]) {
      fn.add(v[j], -1);
      vis[j] = 1;
    }
  }
  cout << ans << endl;
  return 0;
}
