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
  T get(int l, int r) {
    return get(r) - get(l - 1);
  }
};


int n;
int a[N];
int b[N];
int last[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for(int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  cin >> n;
  vector<pair<int, int>> v;
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    for(int j = 0; j < 6; j++) {
      v.push_back({b[i] - a[j], i});
    }
  }
  sort(all(v));
  
  int ans = INT_MAX;
  vector<int> cnt(n, 0);
  int tot = 0;
  int j = sz(v) - 1;
  for(int i = sz(v) - 1; i >= 0; i--) {
    if(++cnt[v[i].second] == 1) {
      tot++;
    }
    while(cnt[v[j].second] > 1) {
      cnt[v[j].second]--;
      j--;
    }
    if(tot == n) {
      ans = min(ans, v[j].first - v[i].first);
    }
  }
  cout << ans << endl;
  return 0;
}
