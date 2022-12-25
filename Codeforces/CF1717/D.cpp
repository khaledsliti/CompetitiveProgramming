#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
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

const int N = 1e5 + 5;
const int Mod = 1e9 + 7;

template<int N, int Mod>
struct Combination {
  int fact[N], inv[N], p2[N];
  int pow(int a, int b) {
    if(!b) return 1;
    int r = pow(a, b >> 1);
    r = 1LL * r * r % Mod;
    if(b & 1) r = 1LL * r * a % Mod;
    return r;
  }
  Combination() {
    fact[0] = inv[0] = p2[0] = 1;
    for(int i = 1; i < N; i++) {
      fact[i] = 1LL * fact[i - 1] * i % Mod;
      inv[i] = pow(fact[i], Mod - 2);
      p2[i] = 2LL * p2[i - 1] % Mod;
    }
  }
  int choose(int n, int k) {
    if(k < 0 || k > n) return 0;
    return 1LL * fact[n] * inv[n - k] % Mod * inv[k] % Mod;
  }
};

Combination<N, Mod> c;

void solve() {
  int n, k;
  cin >> n >> k;
  k = min(k, n);
  ll ans = 0;
  debug(n, k);
  for(int i = 0; i <= k; i++) {
    ans = (ans + c.choose(n, i)) % Mod;
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  while(T--) {
    solve();
  }
  return 0;
}
