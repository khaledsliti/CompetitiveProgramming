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

const int N = 1006;
const int INF = 1e9;

int n, m;
vector<int> arr[N];
int dp[N][2][2];

void sw(vector<int>& a) {
  for(int j = 0; j < m; j++) {
    a[j] ^= 1;
  }
}

vector<int> get(int idx, int t) {
  vector<int> ret(m, 0);
  for(int i = 0; i < m; i++) {
    ret[i] = arr[idx][i] ^ t;
  }
  return ret;
}

int solve(int i, int im1, int im2) {
  if(i >= n) {
    vector<int> b = get(i - 1, im1);
    vector<int> c = get(i - 2, im2);
    // debug(im1, im2);
    // debug(b);
    // debug(c);
    for(int j = 0; j < m; j++) {
      if(j > 0 && b[j] == b[j - 1] || j + 1 < m && b[j + 1] == b[j]) {
        continue;
      }
      if(b[j] == c[j]) {
        continue;
      }
      return INF;
    }
    return 0;
  }
  int& r = dp[i][im1][im2];
  if(r != -1) {
    return r;
  }
  r = INF;
  vector<int> a = get(i, 0);
  vector<int> b = get(i - 1, im1);
  vector<int> c = get(i - 2, im2);

  for(int cost = 0; cost <= 1; cost++) {
    bool ok = true;
    for(int j = 0; j < m; j++) {
      if(j > 0 && b[j - 1] == b[j] || j < m - 1 && b[j + 1] == b[j]) {
        continue;
      }
      if(a[j] == b[j] || b[j] == c[j]) {
        continue;
      }
      ok = false;
      break;
    }
    if (ok) {
      r = min(r, cost + solve(i + 1, cost, im1));
    }
    sw(a);
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    arr[i].resize(m);
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  memset(dp, -1, sizeof dp);
  int ans = INF;
  vector<int> aa = arr[0];
  for(int a = 0; a < 2; a++) {
    vector<int> bb = arr[1];
    for(int b = 0; b < 2; b++) {
      bool ok = true;
      for(int j = 0; j < m; j++) {
        if(j > 0 && aa[j] == aa[j - 1] || j + 1 < m && aa[j] == aa[j + 1]) {
          continue;
        }
        if(aa[j] == bb[j]) {
          continue;
        }
        ok = false;
      }
      if(ok) {
        ans = min(ans, a + b + solve(2, a, b));
      }
      sw(bb);
    }
    sw(aa);
  }

  if(ans >= INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
