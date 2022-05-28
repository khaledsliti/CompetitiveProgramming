#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;

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
  void add(int x, int y, T v) {
    addPr(x + 1, v);
    if (y + 2 < n) {
      addPr(y + 2, -v);
    }
  }
  T get(int x) {
    return getPr(x + 1);
  }
};

int n;
int arr[N], ans[N];

void solve() {
  cin >> n;
  long long ones = 0;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    ones += arr[i];
  }
  ones /= n;
  for(int i = 0; i < n; i++) {
    ans[i] = 0;
  }
  fenwick<int> acc(n + 2);

  for(int i = n - 1; i >= 1; i--) {
    int C = arr[i] - acc.get(i);
    int add = ones ? 1 : 0;
    ans[i] = (C - add) / i;
    acc.add(i - ones + 1, i, 1);
    if(ans[i] == 1) {
      ones--;
    }
  }
  if(ones) {
    ans[0] = 1;
  }

  for(int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
