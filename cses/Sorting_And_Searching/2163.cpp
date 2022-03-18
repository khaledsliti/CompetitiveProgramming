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

template<typename T>
class fenwick {
  vector<T> fen;
  int n;
  void addPr(int x, T v) {
    for(int i = x; i < n; i += i & -i) {
      fen[i] += v;
    }
  }
  T getPr(int x) const {
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
  T get(int x) const {
    return getPr(x + 1);
  }
  T get(int l, int r) const {
    return get(r) - get(l - 1);
  }
};

const int N = 4e5 + 5;

int n, k;

int GetNext(const fenwick<int>& fn, int cur, int k, int len) {
  int j = k % len + 1;
  int suff = fn.get(cur, n - 1);
  if(suff < j) {
    cur = 0;
    j -= suff;
  }
  int s = cur, e = n - 1, ret;
  while(s <= e) {
    int mid = s + e >> 1;
    int cnt = fn.get(cur, mid);
    if(cnt >= j) {
      ret = mid;
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n >> k;
  int len = n;
  fenwick<int> fn(N);
  for(int i = 0; i < n; i++) {
    fn.add(i, 1);
  }
  int cur = 0;
  for(int it = 0; it < n; it++) {
    int idx = GetNext(fn, cur, k, len);
    fn.add(idx, -1);
    len--;
    cur = idx;
    cout << idx + 1 << " ";
  }
  cout << endl;

  return 0;
}
