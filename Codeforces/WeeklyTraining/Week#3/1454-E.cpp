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

const int N = 2e5 + 5;

int n;
vector<int> g[N];
vector<int> st;
int vis[N], found, cycle;
long long ans;

int run(int u) {
  int cnt = 1;
  vis[u] = 1;
  for(int v: g[u]) {
    if(!vis[v]) {
      cnt += run(v);
    }
  }
  return cnt;
}

void dfs(int u, int p) {
  if(found) return;
  st.push_back(u);
  if(vis[u]) {
    found = true;
    cycle = 0;
    memset(vis, 0, n * sizeof(vis[0]));
    vector<int> nodes;
    do {
      vis[st.back()] = 1;
      nodes.push_back(st.back());
      cycle++;
      st.pop_back();
    } while(st.size() > 0 && st.back() != u);
    ans = 0;
    for(int u : nodes) {
      int s = run(u);
      ans += 1LL * s * (s - 1);
      ans += 2LL * s * (n - s);
    }
    ans >>= 1;
    return;
  }
  vis[u] = 1;
  for(int v: g[u]) {
    if(v != p) {
      dfs(v, u);
    }
  }
  st.pop_back();
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    g[i].clear();
  }
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  st.clear();
  memset(vis, 0, n * (sizeof(vis[0])));
  found = false;
  dfs(0, -1);
  cout << ans << endl;
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
