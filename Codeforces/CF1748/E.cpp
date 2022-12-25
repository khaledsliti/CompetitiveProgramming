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

int n, m;
int arr[N];
int st[N << 2];
vector<vector<int>> dp;
map<pair<int, int>, int> cache;

int merge(int i, int j) {
  if(j == -1) return i;
  if(i == -1) return j;
  if(arr[i] >= arr[j]) {
    return i;
  }
  return j;
}

void build(int cur, int s, int e) {
  if(s == e) {
    st[cur] = s;
    return;
  }
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  st[cur] = merge(st[l], st[r]);
}

int get(int cur, int s, int e, int i, int j) {
  if(s >= i && e <= j) {
    return st[cur];
  }
  if(s > j || e < i) {
    return -1;
  }
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  return merge(get(l, s, mid, i, j), get(r, mid + 1, e, i, j));
}

int get(int l, int r) {
  if (cache.count({l, r})) {
    return cache[{l, r}];
  }
  return cache[{l, r}] = get(0, 0, n - 1, l, r);
}

int solve(int l, int r, int mx) {
  if (l > r) {
    return 1;
  }
  if(mx <= 0) {
    return 0;
  }
  int idx = get(l, r);
  int& ret = dp[idx][mx];
  if(ret != -1) {
    return ret;
  }

  ret = 1LL * solve(l, idx - 1, mx - 1) * solve(idx + 1, r, mx) % Mod;
  ret = (ret + solve(l, r, mx - 1)) % Mod;
  
  return ret;
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(0, 0, n - 1);
  dp.clear();
  dp.resize(n, vector<int>(m + 1, -1));
  cache.clear();

  cout << solve(0, n - 1, m) << endl;
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
