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
const int L = 60;
const int Mod = 1e9 + 7;

int n;
vector<int> g[N];
vector<long long> cost[N];
int dp[L][N][2];
int ans;
int powerTwo[L];

void addBiEdge(int a, int b, long long c) {
  g[a].push_back(b);
  cost[a].push_back(c);
}

void addEdge(int a, int b, long long c) {
  addBiEdge(a, b, c);
  addBiEdge(b, a, c);
}

int getValue(int j, long long c) {
  return (c >> j) & 1;
}

void calcDP(int j, int u, int v, int c) {
  if(c == 0) {
    dp[j][u][0] += 1 + dp[j][v][0];
    dp[j][u][1] += dp[j][v][1];
  } else {
    dp[j][u][0] += dp[j][v][1];
    dp[j][u][1] += 1 + dp[j][v][0];
  }
}

inline int getSum0(int j, int v, int c) {
  if(c == 0) {
    return 1 + dp[j][v][0];
  } else {
    return dp[j][v][1];
  }
}

inline int getSum1(int j, int v, int c) {
  if(c == 0) {
    return dp[j][v][1];
  } else {
    return 1 + dp[j][v][0];
  }
}

void calcSubTree(int j, int u, int p, int& ans) {
  int sum0 = 0, sum1 = 0;
  for(int i = 0; i < sz(g[u]); i++) {
    int v = g[u][i];
    int c = getValue(j, cost[u][i]);
    if(v == p) continue;
    sum0 += getSum0(j, v, c);
    sum1 += getSum1(j, v, c);
  }
  int add = 0;
  for(int i = 0; i < sz(g[u]); i++) {
    int v = g[u][i];
    int c = getValue(j, cost[u][i]);
    if(v == p) continue;
    sum0 -= getSum0(j, v, c);
    sum1 -= getSum1(j, v, c);
    if(c == 0) {
      add += 1LL * sum0 * dp[j][v][1] % Mod;
      add %= Mod;
      add += 1LL * sum1 * (1 + dp[j][v][0]) % Mod;
      add %= Mod;
    } else {
      add += 1LL * sum0 * (1 + dp[j][v][0]) % Mod;
      add %= Mod;
      add += 1LL * sum1 * dp[j][v][1] % Mod;
      add %= Mod;
    }
  }
  ans = (ans + add) % Mod;
}

void dfs(int u, int p) {
  for(int j = 0; j < L; j++) {
    dp[j][u][0] = dp[j][u][1] = 0;
  }
  for(int i = 0; i < sz(g[u]); i++) {
    int v = g[u][i];
    if (v == p) continue;
    long long c = cost[u][i];
    dfs(v, u);
    for(int j = 0; j < L; j++) {
      calcDP(j, u, v, getValue(j, c));
    }
  }
  for(int j = 0; j < L; j++) {
    int cur = dp[j][u][1];
    calcSubTree(j, u, p, cur);
    ans = (ans + 1LL * cur * powerTwo[j] % Mod) % Mod;
  }
}

int main()
{
  powerTwo[0] = 1;
  for(int i = 1; i < L; i++) {
    powerTwo[i] = 2LL * powerTwo[i - 1] % Mod;
  }

  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    long long c;
    scanf("%d%d%lld", &a, &b, &c);
    addEdge(--a, --b, c);
  }

  dfs(0, -1);

  cout << ans << endl;
  return 0;
}
