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

const int N = 1e5 + 5;

int n;
vector<int> g[N];
int sub[N], mx[N];

void init() {
  for(int i = 0; i < n; i++) {
    g[i].clear();
  }
}

void dfs(int u, int p) {
  sub[u] = 1;
  mx[u] = 0;
  for(int v: g[u]) {
    if(v == p) continue;
    dfs(v, u);
    sub[u] += sub[v];
    mx[u] = max(mx[u], sub[v]);
  }
  if(p != -1)
    mx[u] = max(mx[u], n - sub[u]);
}

void print(int u, int v) {
  cout << u + 1 << " " << v + 1 << endl;
}

void solve() {
  cin >> n;
  init();
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0, -1);
  // for(int i = 0; i < n; i++) {
  //   cout << i + 1 << " " << sub[i] << " " << mx[i] << endl;
  // }
  // cout << endl;
  vector<int> cen;
  int cur_max = n + 1;
  for(int i = 0; i < n; i++) {
    if(cur_max > mx[i]) {
      cen.clear();
      cen.push_back(i);
      cur_max = mx[i];
    } else if(cur_max == mx[i]) {
      cen.push_back(i);
    }
  }
  // debug(cen);
  if(cen.size() == 1) {
    int a = cen.front();
    int b = g[a][0];
    print(a, b);
    print(a, b);
  } else {
    int a = cen.front();
    int b = cen.back();
    int c = -1;
    for(int v: g[b]) {
      if(v != a) {
        c = v;
        break;
      }
    }
    print(b, c);
    print(a, c);
  }
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
