// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

// Region Debug
string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(const pair<A, B>& p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename T>
string to_string(const vector<T>& v) {
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (i > 0) res += ", ";
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
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(const pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// End Region

const int N = 2e5 + 6;
const int INF = 1e9;

int n;
int arr[N];
int ans[N];

struct Node {
  int max_pj_p_j;
  int min_pj_p_j;
  int max_pj_m_j;
  int min_pj_m_j;
} st[N << 2];

Node zero = Node{-INF, INF, -INF, INF};

Node merge(Node a, Node b) {
  Node r;
  r.max_pj_m_j = max(a.max_pj_m_j, b.max_pj_m_j);
  r.min_pj_m_j = min(a.min_pj_m_j, b.min_pj_m_j);
  r.max_pj_p_j = max(a.max_pj_p_j, b.max_pj_p_j);
  r.min_pj_p_j = min(a.min_pj_p_j, b.min_pj_p_j);
  return r;
}

void build(int cur, int s, int e) {
  if (s == e) {
    st[cur] = zero;
    return;
  }
  int mid = (s + e) >> 1;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  st[cur] = merge(st[l], st[r]);
}

void update(int cur, int s, int e, int idx, int pj, int j) {
  if (s > idx || e < idx) {
    return;
  }
  if (s == e) {
    st[cur] = Node{pj + j, pj + j, pj - j, pj - j};
    return;
  }
  int mid = (s + e) >> 1;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  update(l, s, mid, idx, pj, j);
  update(r, mid + 1, e, idx, pj, j);
  st[cur] = merge(st[l], st[r]);
}

Node query(int cur, int s, int e, int i, int j) {
  if (s > j || e < i) {
    return zero;
  }
  if (s >= i && e <= j) {
    return st[cur];
  }
  int mid = (s + e) >> 1;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  return merge(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
}

void print(int cur, int s, int e) {
  debug(s, e, st[cur].min_pj_m_j);
  if (s == e) {
    return;
  }
  int mid = (s + e) >> 1;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  print(l, s, mid);
  print(r, mid + 1, e);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i]--;
  }

  for (int i = 0; i < n; i++) {
    ans[i] = INF;
  }

  build(0, 0, n - 1);

  for (int i = 0; i < n; i++) {
    int pi = arr[i];
    if (pi > 0) {
      Node cur = query(0, 0, n - 1, 0, pi - 1);
      ans[i] = min(ans[i], pi + i + 2 - cur.max_pj_p_j);
    }
    if (pi < n - 1) {
      Node cur = query(0, 0, n - 1, pi + 1, n - 1);
      // cout << i << " " << cur.min_pj_m_j << endl;
      ans[i] = min(ans[i], cur.min_pj_m_j - (pi - i));
    }
    update(0, 0, n - 1, pi, pi + 1, i + 1);
    // print(0, 0, n - 1);
  }

  build(0, 0, n - 1);

  for (int i = n - 1; i >= 0; i--) {
    int pi = arr[i];
    if (pi > 0) {
      Node cur = query(0, 0, n - 1, 0, pi - 1);
      ans[i] = min(ans[i], pi - i - cur.max_pj_m_j);
    }
    if (pi < n - 1) {
      Node cur = query(0, 0, n - 1, pi + 1, n - 1);
      ans[i] = min(ans[i], cur.min_pj_p_j - (pi + i + 2));
    }
    update(0, 0, n - 1, pi, pi + 1, i + 1);
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}

/*
|Pi - Pj| + |i - j|

i > j:
Pi > Pj: Pi - Pj + i - j = (Pi + i) - (Pj + j) -> max(Pj + j)
Pi < Pj: Pj - Pi + i - j = (Pj - j) - (Pi - i) -> min(Pj - j)

i < j
Pi > Pj: Pi - Pj + j - i = (Pi - i) - (Pj - j) -> max(Pj - j)
Pi < Pj: Pj - Pi + j - i = (Pj + j) - (Pi + i) -> min(Pj + j)
*/