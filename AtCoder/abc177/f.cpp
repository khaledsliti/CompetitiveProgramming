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
const int Inf = 1e9;
 
struct Node {
  ll min, first;
};
 
int n, m;
Node st[N << 2];
 
void push_down(int cur, int s, int e) {
  if(st[cur].first != 0) {
    st[cur].min = st[cur].first;
    if(s != e) {
      int l = 2 * cur + 1;
      int r = 2 * cur + 2;
      int mid = (s + e) / 2;
      st[l].first = st[cur].first;
      st[r].first = st[cur].first + mid - s + 1;
    }
    st[cur].first = 0;
  }
}
 
void merge(Node& r, const Node& a, const Node& b) {
  r.min = min(a.min, b.min);
  r.first = 0;
}
 
void update(int cur, int s, int e, int i, int j, ll val) {
  push_down(cur, s, e);
  if(s > j || e < i) return;
  if(s >= i && e <= j) {
    st[cur].first = val;
    push_down(cur, s, e);
    return;
  }
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  update(l, s, mid, i, j, val);
  int a = max(s, i), b = min(mid, j);
  int left_size = max(0, b - a + 1);
  update(r, mid + 1, e, i, j, val + left_size);
  merge(st[cur], st[l], st[r]);
}
 
ll query(int cur, int s, int e, int i, int j) {
  push_down(cur, s, e);
  if(s > j || e < i) return LLONG_MAX;
  if(s >= i && e <= j) return st[cur].min;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  return min(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  cin >> n >> m;
  int left = 0;
  for(int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    while(l <= left && left <= r)
      left++;
    if(left >= m) {
      cout << -1 << endl;
      continue;
    }
    if(l > left) {
      long long val = query(0, 0, m - 1, l - 1, l - 1);
      update(0, 0, m - 1, l, r, val + 1);
      // cout << val << endl;
    }
    // for(int i = 0; i < m; i++)
    //   cout << query(0, 0, m - 1, i, i) << " ";
    // cout << endl;
    ll ans = query(0, 0, m - 1, left, m - 1);
    cout << ans + i + 1 << endl;
  }
  return 0;
}