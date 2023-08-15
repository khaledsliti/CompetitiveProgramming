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

const int N = 2005;
const int Mod = 998244353;

int n, k, m, z;
int arr[N];
long long cnk[N][N];
long long fact[N];

void pre() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        cnk[i][j] = 1;
      } else {
        cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % Mod;
      }
    }
  }
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = i * fact[i - 1] % Mod;
  }
}

long long mpow(long long a, long long b) {
  if (!b) {
    return 1LL;
  }
  long long r = mpow(a, b >> 1);
  r = (r * r) % Mod;
  if (b & 1) {
    r = (r * a) % Mod;
  }
  return r;
}

long long dp[N][N];
long long solve(int rem, int cur) {
  if (rem == 0) {
    return 1;
  }
  long long& r = dp[rem][cur];
  if (r != -1) {
    return r;
  }
  r = solve(rem - 1, cur);
  if (cur < m) {
    r = (r + solve(rem, cur + 1)) % Mod;
  }
  return r;
}

long long count(int target) {
  int cur_l = 0;
  int cur_e = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      continue;
    }
    cur_l += arr[i] < target;
    cur_e += arr[i] == target;
  }
  if (cur_l > k || cur_l + cur_e + z < k) {
    return 0;
  }
  long long ret = 0;
  for (int fix_l = cur_l; fix_l < k; fix_l++) {
    int ch_l = fix_l - cur_l;
    if (ch_l > z) {
      continue;
    }
    long long ways_l = cnk[z][ch_l] * mpow(target - 1, ch_l) % Mod;
    debug(ways_l);
    int av = z - ch_l;
    debug(av);
    int need_e = max(0, k - fix_l - cur_e);
    if (need_e > av) {
      continue;
    }
    debug(need_e, solve(av - need_e, target));
    long long cur = ways_l * solve(av - need_e, target) % Mod * fact[av] % Mod;
    ret = (ret + cur) % Mod;
  }
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  pre();
  memset(dp, -1, sizeof dp);

  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    z += arr[i] == 0;
  }
  cout << count(1) << endl;
  return 0;

  long long ans = 0;
  for (int target = 1; target <= m; target++) {
    int cur = target * count(target) % Mod;
    debug(target, count(target));
    ans = (ans + cur) % Mod;
  }
  debug(ans);

  ans = (ans * mpow(m, z * (Mod - 2))) % Mod;
  cout << ans << endl;
  return 0;
}
