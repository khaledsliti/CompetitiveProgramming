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

const int N = 3e5 + 5;

struct Node {
  pair<int, int> min, max;
};

int n;
int arr[N], lt[N], gt[N];
Node st[N << 2];

Node merge(Node a, Node b) {
  Node r;
  if(a.min.first < b.min.first) {
    r.min = a.min;
  } else {
    r.min = b.min;
  }
  if(a.max.first > b.max.first) {
    r.max = a.max;
  } else {
    r.max = b.max;
  }
  return r;
}

void build(int cur, int s, int e) {
  if(s == e) {
    st[cur] = {{arr[s], s}, {arr[s], s}};
    return;
  }
  int mid = (s + e) / 2;
  build(2 * cur + 1, s, mid);
  build(2 * cur + 2, mid + 1, e);
  st[cur] = merge(st[2 * cur + 1], st[2 * cur + 2]);
}

Node query(int cur, int s, int e, int i, int j) {
  if(s > j || e < i) return {{1e9, 0}, {-1, 0}};
  if(s >= i && e <= j) return st[cur];
  int mid = (s + e) / 2;
  return merge(query(2 * cur + 1, s, mid, i, j), query(2 * cur + 2, mid + 1, e, i, j));
}

int getMinIdx(int i, int j) {
  return query(0, 0, n - 1, i, j).min.second;
}

int getMaxIdx(int i, int j) {
  return query(0, 0, n - 1, i, j).max.second;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  stack<pair<int, int>> st;
  st.push({1e9, n});
  for(int i = n - 1; i >= 0; i--) {
    while(st.top().first <= arr[i]) {
      st.pop();
    }
    gt[i] = st.top().second;
    st.push({arr[i], i});
  }
  while(st.size()) {
    st.pop();
  }
  st.push({-1, n});
  for(int i = n - 1; i >= 0; i--) {
    while(st.top().first >= arr[i]) {
      st.pop();
    }
    lt[i] = st.top().second;
    st.push({arr[i], i});
  }

  build(0, 0, n - 1);

  vector<int> dp(n, 0);
  for(int i = n - 2; i >= 0; i--) {
    dp[i] = 1 + dp[i + 1];
    int r = lt[i];
    if(i + 1 < r) {
      int idx = getMaxIdx(i + 1, r - 1);
      dp[i] = min(dp[i], 1 + dp[idx]);
    }
    r = gt[i];
    if(i + 1 < r) {
      int idx = getMinIdx(i + 1, r - 1);
      dp[i] = min(dp[i], 1 + dp[idx]);
    }
  }
  cout << dp[0] << endl;

  // for(int i = 0; i < n; i++) {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;
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
