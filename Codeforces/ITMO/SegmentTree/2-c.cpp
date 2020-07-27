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
    int max, t_max;
  };
  
  int n;
  vector<TreeNode> st;
  void init(int n) {
    this->n = n;
    st.resize(n << 2, TreeNode());
  }
  TreeNode merge(TreeNode a, TreeNode b) {
    return { max(a.max, b.max), -1 };
  }
  void update(int cur, int s, int e, int idx, int val) {
    if(s > idx || e < idx) return;
    if(s == e) {
      st[cur] = { val, -1 };
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    update(l, s, mid, idx, val);
    update(r, mid + 1, e, idx, val);
    st[cur] = merge(st[l], st[r]);
  }
  void update(int idx, int val) {
    update(0, 0, n - 1, idx, val);
  }
  int query(int cur, int s, int e, int i, int x) {
    if(s == e) return s;
    int mid = (s + e) / 2;
    int l = 2 * cur + 1, r = 2 * cur + 2;
    int mx_left = st[l].t_max == -1 ? st[l].max : st[l].t_max;
    if(mx_left < x) return query(r, mid + 1, e, i, x);
    return query(l, s, mid, i, x);
  }
  void search(int cur, int s, int e, int i, int t) {
    if(e < i) {
      st[cur].t_max = t ? INT_MIN : -1;
      return;
    }
    if(s >= i) {
      st[cur].t_max = st[cur].max;
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1, r = 2 * cur + 2;
    search(l, s, mid, i, t);
    search(r, mid + 1, e, i, t);
    st[cur].t_max = t ? max(st[l].t_max, st[r].t_max) : -1;
  }
  int query(int l, int x) {
    search(0, 0, n - 1, l, 1);
    int ans = st[0].t_max < x ? -1 : query(0, 0, n - 1, l, x);
    search(0, 0, n - 1, l, 0);
    return ans;
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
    st.update(i, a);
  }
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int idx, val;
      scanf("%d%d", &idx, &val);
      st.update(idx, val);
    } else {
      int x, l;
      scanf("%d%d", &x, &l);
      printf("%d\n", st.query(l, x));
    }
  }
  return 0;
}
