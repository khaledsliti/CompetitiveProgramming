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

// Region Debug
string to_string(const string &s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template<typename A, typename B>
string to_string(const pair<A, B>& p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template<typename T>
string to_string(const vector<T>& v) {
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (i > 0)
      res += ", ";
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first)
      res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template<typename A, typename B>
string to_string(const pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// End Region

void solve() {
  long long n, x;
  cin >> n >> x;
  if (x > n) {
    cout << -1 << endl;
    return;
  }
  if (n == x) {
    cout << n << endl;
    return;
  }
  vector<int> bn;
  ll t = n;
  while(n > 0) {
    bn.push_back(n & 1);
    n >>= 1;
  }
  n = t;
  if (x == 0) {
    cout << (1LL << sz(bn)) << endl;
    return;
  }

  auto ith = [](ll a, int i) -> int {
    return (a >> i) & 1;
  };
  long long ans = LLONG_MAX;
  for (int i = 1; i <= sz(bn) - 1; i++) {
    int bit = sz(bn) - i - 1;
    if (ith(n, bit) == 1) {
      continue;
    }
    ll m = (1LL << sz(bn)) - 1;
    for (int j = 0; j < sz(bn) - i; j++) {
      m ^= (1LL << j);
    }
    // debug(m);
    if ((n & m) != x) {
      continue;
    }
    ll target = x + (1LL << bit);
    ans = min(ans, target);
  }
  if (ans >= LLONG_MAX) {
    ans = -1;
  }
  cout << ans << endl;
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
