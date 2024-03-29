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

const int N = 2e5 + 5;

int n, q;
string s;
int dp[3][N];

void pre() {
  for(int i = 0; i < 3; i++) {
    char c = char('a' + i);
    dp[i][n] = dp[i][n + 1] = dp[i][n + 2] = 0;
    for(int j = n - 1; j >= 0; j--) {
      dp[i][j] = dp[i][j + 3] + (s[j] != c);
    }
  }

  // for(int i = 0; i < 3; i++) {
  //   for(int j = 0; j < n; j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
}

int calc(int st, int c, int r) {
  if(st > r) return 0;
  int x = (r - st) / 3 + 1;
  return dp[c][st] - dp[c][st + 3 * x];
}

int solve(int l, int r) {
  vector<int> p {0, 1, 2};
  int ans = n;
  do {
    int cur = 0;
    for(int i = 0; i < 3; i++) {
      if(l + i <= r) {
        cur += calc(l + i, p[i], r);
      }
    }
    // debug(cur, p);
    ans = min(ans, cur);
  }while(next_permutation(all(p)));
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  cin >> s;

  pre();

  while(q--) {
    int l, r;
    cin >> l >> r;
    cout << solve(--l, --r) << endl;
  }

  return 0;
}
