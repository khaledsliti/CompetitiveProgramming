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

template<typename T>
class sparse_table {
  int n, depth;
  vector<T> values;
  vector<vector<int>> dp;

  int largest_bit(int x){
    int cnt = 0;
    while(x)
      cnt++, x >>= 1;
    return cnt - 1;
  }

  int max_index(int a, int b) const{
    return values[a] <= values[b] ? a : b;
  }

  void build(){
    n = (int)values.size();
    depth = largest_bit(n) + 1;
    dp.clear();
    dp.resize(n);
    for(int i = 0 ; i < n ; i++)
      dp[i].resize(depth);
    for(int i = 0 ; i < n ; i++)
      dp[i][0] = i;
    for(int len = 1 ; (1 << len) <= n ; len++){
      for(int i = 0 ; i + (1 << (len - 1)) < n ; i++){
        dp[i][len] = max_index(dp[i][len - 1], dp[i + (1 << (len - 1))][len - 1]);
      }
    }
  }

public:
  sparse_table(){}

  sparse_table(const vector<T> &_values){
    values = _values;
    build();
  }

  sparse_table(T* first, T* last){
    values.clear();
    for(T* i = first ; i != last ; i++)
      values.push_back(*i);
    build();
  }

  int query_index(int l, int r){
    int dep = largest_bit(r - l + 1);
    return max_index(dp[l][dep], dp[r - (1 << dep) + 1][dep]);
  }

  T query_value(int l, int r){
    return values[query_index(l, r)];
  }
};


const int N = 2e5 + 5;

void solve() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<long long> pref(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    pref[i] = a[i] + pref[i - 1];
  }
  // debug(pref);
  sparse_table<long long> sp(pref);
  int len = 0, st;
  for(int i = 1; i <= n; i++) {
    int low = i, high = n, j = n + 1;
    while(low <= high) {
      int mid = low + high >> 1;
      if(sp.query_value(i, mid) < pref[i - 1] - s) {
        high = mid - 1;
        j = mid;
      } else {
        low = mid + 1;
      }
    }
    // debug(i, j);
    if(len < j - i) {
      len = j - i;
      st = i;
    }
  }
  if(len == 0) cout << -1 << endl;
  else cout << st << " " << st + len - 1 << endl;
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
