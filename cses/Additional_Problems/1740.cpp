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

template<typename T>
class fenwick {
public:
  vector<T> fen;
  int n;

  fenwick(int _n) : n(_n) {
    fen.resize(n, T());
  }

  void add(int x, T v) {
    while(x < n) {
      fen[x] += v;
      x |= x + 1;
    }
  }

  T get(int x) {
    T v{};
    while(x >= 0) {
      v += fen[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

vector<array<int, 3>> h, v;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2) {
      v.push_back({x1, y1, y2});
    } else {
      h.push_back({x1, 1, y1});
      h.push_back({x2 + 1, -1, y1});
    }
  }
  sort(all(h));
  sort(all(v));
  fenwick<int> fn(3e6 + 5);
  long long ans = 0;
  int j = 0;
  for(int i = 0; i < sz(v); i++) {
    while(j < sz(h) && h[j][0] <= v[i][0]) {
      fn.add(1e6 + h[j][2], h[j][1]);
      j++;
    }
    ans += fn.get(1e6 + v[i][2]) - fn.get(1e6 + v[i][1] - 1);
  }
  cout << ans << endl;
  return 0;
}
