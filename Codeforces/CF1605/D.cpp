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

void solve() {
  int n; cin >> n;
  vector<vector<int>> g(n);
  for(int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    --a, --b;
    g[a].pb(b), g[b].pb(a);
  }
  vector<int> ws, bs;
  function<void(int, int, int)> dfs;
  dfs = [&](int u, int p, int col) {
    if(col) ws.pb(u);
    else bs.pb(u);
    for(int v: g[u]) {
      if(v != p) {
        dfs(v, u, 1 - col);
      }
    }
  };
  dfs(0, -1, 0);
  if(sz(ws) > sz(bs)) {
    swap(ws, bs);
  }
  int width = 32 - __builtin_clz(n);
  vector<vector<int>> gr(width);
  for(int i = 1; i <= n; i++) {
    gr[31 - __builtin_clz(i)].push_back(i);
  }
  vector<int> ans(n);
  for(int i = 0; i < width; i++) {
    if(sz(ws) >> i & 1) {
      for(int x: gr[i]) {
        ans[ws.back()] = x;
        ws.pop_back();
      }
    } else {
      for(int x: gr[i]) {
        ans[bs.back()] = x;
        bs.pop_back();
      }
    }
  }
  for(int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
