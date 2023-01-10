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

const int N = 5e5 + 5;
const int Mod = 998244353;

int n, m;
int cur[N];

bool isPalin(int i, int j) {
  for(int k = 0; k < (j - i + 1) / 2; k++) {
    if(cur[i + k] != cur[j - k]) {
      return false;
    }
  }
  return true;
}

bool check() {
  vector<int> dp(n + 1, 0);
  dp[n] = 1;
  for(int i = n - 2; i >= 0; i -= 2) {
    for(int j = i + 1; j < n; j += 2) {
       if(isPalin(i, j)) {
        dp[i] |= dp[j + 1];
       }
    }
  }
  return dp[0];
}

int calc(int i) {
  if(i >= n) {
    return check();
  }
  int ret = 0;
  for(int j = 1; j <= m; j++) {
    cur[i] = j;
    ret += calc(i + 1);
  }
  return ret;
}

int main()
{
  cin >> n >> m;
  
  vector<int> u(n + 1, 0);
  u[1] = 1;
  for(int i = 1; i < sz(u) - 1; i++) {
    if(i % 2 == 1) {
      u[i + 1] = 1LL * m * u[i] % Mod;
    } else {
      u[i + 1] = ((1LL * m * u[i] % Mod - u[i / 2 + 1]) % Mod + Mod);
    }
  }

  vector<int> p(sz(u), 0);
  p[1] = 1;
  for(int n = 1; n < sz(u) - 1; n++) {
    p[n + 1] = 0;
    for(int i = 1; i <= n; i++) {
      p[n + 1] += (1LL * u[i + 1] * p[n - i + 1]) % Mod;
      p[n + 1] %= Mod;
    }
  }

  cout << p[n / 2 + 1] << endl;

  return 0;
}
