// Guess Who's Back
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

const int N = 101, A = 10001;
const int INF = 1e9;

int n;
int a[N], b[N];
int dp[N][N][A];
int total_b;

double solve(int k) {
  int ans = 0;
  for(int a = 1; a < A; a++) {
    if(dp[n][k][a] >= 0) {
      ans = max(ans, min(2 * a, dp[n][k][a] + total_b));
    }
  }
  return ans * 0.5;
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    total_b += b[i];
  }

  for(int j = 0; j <= n; j++) {
    for(int k = 0; k < A; k++) {
      dp[0][j][k] = -INF;
    }
  }
  dp[0][0][0] = 0;

  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      for(int k = 1; k < A; k++) {
        dp[i][j][k] = dp[i - 1][j][k];
        if(j > 0 && k - a[i - 1] >= 0) {
          dp[i][j][k] = max(dp[i][j][k], b[i - 1] + dp[i - 1][j - 1][k - a[i - 1]]);
        }
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    cout << fixed << setprecision(3) << solve(i) << " ";
  }
  cout << endl;

  return 0;
}
