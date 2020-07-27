// We only fail when we stop trying
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

struct SegTree {
  struct TreeNode {
    int cnt;
  };
  
  TreeNode zero { 0 };
  int n;
  vector<TreeNode> st;
  void init(int n) {
    this->n = n;
    st.resize(n << 2, TreeNode());
  }
  TreeNode merge(TreeNode a, TreeNode b) {
    TreeNode r { a.cnt + b.cnt };
    return r;
  }
  void update(int cur, int s, int e, int idx) {
    if(s > idx || e < idx) return;
    if(s == e) {
      st[cur].cnt ^= 1;
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    update(l, s, mid, idx);
    update(r, mid + 1, e, idx);
    st[cur] = merge(st[l], st[r]);
  }
  void update(int idx) {
    update(0, 0, n - 1, idx);
  }
  int query(int cur, int s, int e, int k) {
    if(s == e) return s;
    int mid = (s + e) / 2;
    int left_size = st[2 * cur + 1].cnt;
    if(k < left_size)
      return query(2 * cur + 1, s, mid, k);
    return query(2 * cur + 2, mid + 1, e, k - left_size);
  }
};

int n;
SegTree st;

int main()
{
  int q;
  scanf("%d%d", &n, &q);
  st.init(n);
  for(int i = 0; i < n; i++) {
    int a; scanf("%d", &a);
    if(a) st.update(i);
  }
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int idx;
      scanf("%d", &idx);
      st.update(idx);
    } else {
      int k;
      scanf("%d", &k);
      printf("%d\n", st.query(0, 0, n - 1, k));
    }
  }
  return 0;
}
