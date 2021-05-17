// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
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

const ll T = 10000000000LL;
const ll N = 1000000000LL;
const ll nano_per_day = 12LL * 60 * 60 * N;
const ll nano_per_hour = 60LL * 60 * N;
const ll nano_per_min = 60 * N;

bool check(ll A, ll B, ll C, ll h, ll m, ll s, ll n) {
  if (h < 0 || h >= 12 || m < 0 || m >= 60 || s < 0 || s >= 60 || n >= N)
    return false;
  // debug(A, B, C);
  // debug(h, m, s, n);
  ll nano = n + s * N + m * 60 * N + h * 60 * 60 * N;
  ll a = nano;
  nano -= h * 60 * 60 * N;
  ll b = nano * 12;
  nano -= m * 60 * N;
  ll c = nano * 720;
  // debug(a, b, c);
  return A == a && B == b && C == c;
}

bool solve(ll A, ll B, ll C) {
  // debug(A, B, C);
  ll h = A / (360LL * 12LL * T / 12LL);
  ll m = B / (360LL * 12LL * T / 60LL);
  ll s = C / (360LL * 12LL * T / 60LL);
  ll n = (C - s) / 720;
  // debug(h, m, s, n);
  if(check(A, B, C, h, m, s, n)) {
    cout << h << " " << m << " " << s << " " << n << endl;
    return true;
  }
  if((C - s) % 720 != 0) {
    ll d = 720 - ((C - s) % 720);
    // debug(d);
    A = (A + d) % nano_per_day;
    B = (B + d) % nano_per_hour;
    C = (C + d) % nano_per_min;
    return solve(A, B, C);
  }
  // debug(A, B, C);
  return false;
}

void solve() {
  vector<long long> v(3);
  for(int i = 0; i < sz(v); i++) {
    cin >> v[i];
  }
  sort(all(v));
  do {
    if(solve(v[0], v[1], v[2]))
      return;
  } while(next_permutation(all(v)));
}

int main()
{

  // cout << solve(0, 11, 719) << endl;
  // return 0;


  int T; cin >> T;
  for(int tc = 1; tc <= T; tc++) {
    cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
