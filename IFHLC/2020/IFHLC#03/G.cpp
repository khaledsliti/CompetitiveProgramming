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

const int N = 51;
const int A = 1e4 + 5;

int n, att;
int cnt[N];
double p[N];
double dp[A][N][N];

double solve(int a, int x, int c) {
  if(x >= n) return 1.0;
  if(a <= 0) return 0.0;
  double& res = dp[a][x][c];
  if(res != -1) return res;
  res = (1 - p[x]) * solve(a - 1, x, c) +
    p[x] * solve(a - 1, x + (c + 1 == cnt[x]), (c + 1) % cnt[x]);
  return res;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> cnt[i] >> p[i];
  }
  cin >> att;
  for(int i = 0; i <= att; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k <= cnt[j]; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  cout << fixed << setprecision(3) << solve(att, 0, 0) << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
