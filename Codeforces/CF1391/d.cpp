// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
typedef long long ll;

const int N = 1e6 + 5;
const int INF = 1e9;

int n, m;
char line[N];
int dp[N][8];
char s[3][N];

bool check(int cur, int last, int nw) {
  if(cur == 0) return true;
  int mat[n][2];
  for(int i = 0; i < n; i++)
    mat[i][0] = mat[i][1] = 0;
  for(int i = 0; i < n; i++) {
    if(last & (1 << i)) mat[i][0] = 1;
    if(nw & (1 << i)) mat[i][1] = 1;
  }
  for(int i = 0; i + 1 < n; i++) {
    int s = mat[i][0] + mat[i][1] + mat[i + 1][0] + mat[i + 1][1];
    if(s % 2 == 0) return false;
  }
  return true;
}

int cost(int cur, int nw) {
  int c = 0;
  for(int i = 0; i < n; i++) {
    if(s[i][cur] - '0' != ((nw >> i) & 1))
      c++;
  }
  // debug(cur, nw, c);
  return c;
}

int solve(int cur, int last) {
  if(cur >= m) return 0;
  int& r = dp[cur][last];
  if(r != -1) return r;
  r = INF;
  for(int nw = 0; nw < (1 << n); nw++) {
    if(check(cur, last, nw))
      r = min(r, cost(cur, nw) + solve(cur + 1, nw));
  }
  return r;
}

int main()
{
  scanf("%d%d", &n, &m);
  if(n >= 4) {
    cout << -1 << endl;
    return 0;
  }
  if(n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for(int i = 0; i < n; i++)
    scanf("%s", s[i]);
  // for(int i = 0; i < n; i++)
  //   printf("%s\n", s[i]);
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << endl;
  return 0;
}