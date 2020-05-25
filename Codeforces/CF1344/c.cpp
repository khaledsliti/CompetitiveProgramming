// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

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

int n, m;
vector<int> g[N], r[N];
int dp1[N], dp2[N], col[N];
bool cycle = false;

void dfs(vector<int> gr[], int dp[], int u) {
  col[u] = 1;
  dp[u] = u;
  for(int v : gr[u]) {
    if(col[v] == 1) {
      cycle = true;
      continue;
    }
    if(col[v] == 0)
      dfs(gr, dp, v);
    dp[u] = min(dp[u], dp[v]);
  }
  col[u] = 2;
}

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    r[b].pb(a);
  }
  memset(col, 0, sizeof col);
  for(int i = 0; i < n; i++)
    if(col[i] == 0)
      dfs(g, dp1, i);
  dfs(g, dp1, 0);
  if(cycle)
    return cout << -1 << endl, 0;
  memset(col, 0, sizeof col);
  for(int i = 0; i < n; i++)
    if(col[i] == 0)
      dfs(r, dp2, i);
  int tot = 0;
  string res = "";
  for(int i = 0; i < n; i++)
    if(min(dp1[i], dp2[i]) >= i) tot++, res += 'A';
    else res += 'E';
  printf("%d\n", tot);
  for(int i = 0; i < n; i++)
    printf("%c", res[i]);
  return 0;
}
