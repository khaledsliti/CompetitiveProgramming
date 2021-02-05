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

struct Query {
  int idx;
  vector<int> val;
};

int n;
int arr[N];
vector<Query> qr[N];
int ans[N];

struct SegTree {
  struct TreeNode {
    int min;
  };
  int n;
  vector<TreeNode> st;
  void build(int cur, int s, int e, TreeNode node) {
    if(s == e) {
      st[cur] = node;
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1, r = 2 * cur + 2;
    build(l, s, mid, node);
    build(r, mid + 1, e, node);
    st[cur] = merge(st[l], st[r]);
  }
  void init(int n, TreeNode node) {
    this->n = n;
    st.resize(n << 2);
    build(0, 0, n - 1, node);
  }
  TreeNode merge(TreeNode a, TreeNode b) {
    return { min(a.min, b.min) };
  }
  void update(int cur, int s, int e, int idx, int val) {
    if(s > idx || e < idx) return;
    if(s == e) {
      st[cur].min = val;
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
  TreeNode query(int cur, int s, int e, int i, int j) {
    if(s > j || e < i) return {INT_MAX};
    if(s >= i && e <= j) return st[cur];
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    return merge(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
  }
  int query(int i, int j) {
    return query(0, 0, n - 1, i, j).min;
  }
} st;

int main()
{
  scanf("%d", &n);
  vector<int> pts;
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    pts.push_back(arr[i]);
  }
  sort(all(pts));
  pts.resize(unique(all(pts)) - begin(pts));
  for(int i = 0; i < n; i++) {
    arr[i] = lower_bound(all(pts), arr[i]) - begin(pts);
  }

  st.init(n, {n});

  int q;
  scanf("%d", &q);
  for(int i = 0; i < q; i++) {
    int idx, m;
    scanf("%d%d", &idx, &m);
    Query cur;
    while(m--) {
      int x;
      scanf("%d", &x);
      int j = lower_bound(all(pts), x) - begin(pts);
      if(j < sz(pts) && pts[j] == x) {
        cur.val.push_back(j);
      }
    }
    cur.idx = i;
    qr[--idx].push_back(cur);
  }

  for(int i = n - 1; i >= 0; i--) {
    st.update(arr[i], i);
    for(int j = 0; j < sz(qr[i]); j++) {
      vector<pair<int, int>> updates;
      for(int k: qr[i][j].val) {
        updates.push_back({k, st.query(k, k)});
        st.update(k, n);
      }
      ans[qr[i][j].idx] = st.query(0, n - 1) - i;
      // debug(i, qr[i][j].idx, st.query(0, n - 1));
      for(int k = 0; k < sz(updates); k++) {
        st.update(updates[k].first, updates[k].second);
      }
    }
  }

  for(int i = 0; i < q; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
