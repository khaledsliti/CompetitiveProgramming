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

const int N = 5e5 + 5;

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

int n, k;
int p[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }

  fenwick<int> f(n + 5);
  int index = 0;

  for(int i = 0; i < n; i++) {
    f.add(p[i], 1);
    if(i >= k - 1) {
      while(f.get(index, n - 1) >= k) {
        index++;
      }
      cout << index << endl;
    }
  }

  return 0;
}
