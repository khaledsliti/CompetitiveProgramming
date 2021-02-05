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

const int Mod = 1e9 + 7;

ll n, a, b;

ll sum(ll x, ll y) {
  if(x > y) return 0;
  ll s = (y - x + 1) * (x + y) / 2;
  return s % Mod;
}

ll sum1(ll x, ll y) {
  return max(0LL, y - x + 1);
}

ll sqr(ll a) {
  return a * a % Mod;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    cin >> n >> a >> b;
    if(a < b) swap(a, b);
    if(a > n) {
      cout << 0 << endl;
      continue;
    }
    int m = min(n, a + b - 1);
    ll ans = sqr(n - a + 1) % Mod * sqr(n - b + 1) % Mod;
    ll r = (a - b + 1) * (n - a + 1) % Mod;
    r += 2 * (n + 1) * sum1(a + 1, m) % Mod;
    r %= Mod;
    r -= 2 * sum(a + 1, m) % Mod;
    r %= Mod;
    r = (r * r) % Mod;
    ans = (ans - r) % Mod;
    ans = (ans + Mod) % Mod;
    cout << ans << endl;
  }
  return 0;
}
