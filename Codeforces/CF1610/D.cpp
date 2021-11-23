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

const int N = 2e5 + 5;
const int Mod = 1e9 + 7;

int n;
int odd, even;
long long fact[N];
int lg[N];

long long mpow(long long a, long long b) {
  if(!b) return 1LL;
  long long r = mpow(a, b >> 1);
  r = (r * r) % Mod;
  if(b & 1) r = (r * a) % Mod;
  return r;
}

long long inv(long long x) {
  return mpow(x, Mod - 2);
}

long long Cnk(int n, int k) {
  return fact[n] * inv(fact[n - k]) % Mod * inv(fact[k]) % Mod;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  fact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % Mod;
  }

  cin >> n;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    if(a & 1) odd++;
    else {
      int l = 0;
      while(a % 2 == 0) {
        l++;
        a >>= 1;
      }
      lg[l]++;
    }
  }
  even = n - odd;

  long long ans = (mpow(2, odd) - 1) * mpow(2, even) % Mod;

  for(int i = 1; i < N; i++) {
    if(lg[i]) {
      even -= lg[i];
      for(int t = 2; t <= lg[i]; t += 2) {
        ans = (ans + Cnk(lg[i], t) * mpow(2, even) % Mod) % Mod;
      }
    }
  }

  ans = (ans + Mod) % Mod;
  cout << ans << endl;

  return 0;
}
