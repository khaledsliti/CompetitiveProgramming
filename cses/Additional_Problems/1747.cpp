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

const int N = 2e5 + 5;

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


int n;
pair<int, int> arr[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  sort(arr, arr + n);
  ll ans = 0;
  fenwick<int> bit(n);
  for(int i = n - 1; i >= 0; i--) {
    int idx = arr[i].second;
    int left = bit.get(idx), right = bit.get(n - 1) - left;
    ans += min(left, right);
    bit.add(idx, 1);
  }
  cout << ans << endl;
  return 0;
}
