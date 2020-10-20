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
const int Mod = 1e9 + 7;

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
ll dp[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a; scanf("%d", &a);
    arr[i] = {a, i};
  }
  sort(arr, arr + n, [](const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
  });
  fenwick<long long> bit(n);
  for(int i = 0; i < n; i++) {
    int idx = arr[i].second;
    dp[idx] = bit.get(n - 1) - bit.get(idx);
    dp[idx] = (1 + dp[idx]) % Mod;
    bit.add(idx, dp[idx]);
  }
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    ans = (ans + dp[i]) % Mod;
  }
  cout << ans << endl;
  return 0;
}
