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

const int N = 1e5 + 5;
const int L = 18;

int n, q;
int C[N], A[N], lg[N];
vector<int> g[N];
int anc[N][L], lev[N];
long long acc[N];
set<int> pos[N];
int st[N], en[N], cur_idx;
long long ans;

void init() {
  cur_idx = 0;
  for(int i = 0 ; i <= n ; i++) {
    g[i].clear();
    pos[i].clear();
    C[i] = -1;
  }
}

void dfs_lca(int u, int p) {
  st[u] = cur_idx++;
  anc[u][0] = p;
  for(int j = 1 ; (1 << j) < n ; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  acc[u] = A[u];
  if(~p) acc[u] += acc[p];
  for(int i = 0 ; i < (int)g[u].size() ; i++){
    int v = g[u][i];
    if(v != p){
      lev[v] = 1 + lev[u];
      dfs_lca(v, u);
    }
  }
  en[u] = cur_idx - 1;
}

int get_lca(int a, int b)
{
  if(lev[a] < lev[b])
    swap(a,b);
  int lg = 0;
  for(; (1 << lg) <= lev[a] ; lg++);
  lg--;
  for(int i = lg ; i >= 0 ; i--)
    if(lev[a] - (1 << i) >= lev[b])
      a = anc[a][i];
  if(a == b) return a;
  for(int i = lg ; i >= 0 ; i--)
    if(anc[a][i] != anc[b][i])
      a = anc[a][i], b = anc[b][i];
  return anc[a][0];
}

// O(log(N))
bool color_exist(int root, int col) {
  auto l = pos[col].lower_bound(st[root]);
  auto r = pos[col].lower_bound(en[root] + 1);
  return l != r;
}

void add_color(int u, int col) {
  C[u] = col;
  if(!color_exist(u, col)) {
    int node = u;
    for(int i = lg[lev[u]]; i >= 0; i--) {
      if(~anc[node][i] && !color_exist(anc[node][i], col))
        node = anc[node][i];
    }
    ans += acc[u];
    if(~anc[node][0])
      ans -= acc[anc[node][0]];
  }
  pos[col].insert(st[u]);
}

void erase_color(int u) {
  int col = C[u];
  pos[col].erase(st[u]);
  C[u] = -1;
  if(color_exist(u, col)) return;
  int node = u;
  for(int i = lg[lev[u]]; i >= 0 ; i--) {
    if(~anc[node][i] && !color_exist(anc[node][i], col)) {
      node = anc[node][i];
    }
  }
  ans -= acc[u];
  if(~anc[node][0])
    ans += acc[anc[node][0]];
}

void solve() {
  scanf("%d%d", &n, &q);
  init();
  for(int i = 0; i < n - 1 ; i ++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    swap(a, b);
    g[a].pb(b);
  }
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", C + i);
  }
  for(int i = 0; i < n ; i++) {
    scanf("%d", A + i);
  }
  dfs_lca(0, -1);
  ans = 0;
  for(int i = 0; i < n ; i++) {
    add_color(i, C[i]);
  }
  for(int i = 0 ; i < q ; i++) {
    int x, c;
    scanf("%d%d", &x, &c);
    erase_color(--x);
    add_color(x, c);
    printf("%lld\n", ans);
  }
}

int main()
{
  lg[0] = lg[1] = 0;
  for(int i = 2 ; i < N ; i++)
    lg[i] = lg[i >> 1] + 1;
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
