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
const int Inf = 1e9;

struct SegTree {
  struct TreeNode {
    int min, idx;
    int lz;
    TreeNode(): min(0), idx(0), lz(0) {}
    TreeNode(int _min, int _idx): min(_min), idx(_idx), lz(0) {}
  };
  
  int n;
  vector<TreeNode> tree;

  int getMid(int l, int r) {
    return (l + r) / 2;
  }

  void pull(TreeNode& res, const TreeNode& a, const TreeNode& b) {
    res.min = min(a.min, b.min);
    res.idx = res.min == b.min ? b.idx : a.idx;
  }

  void push(int cur, int s, int e) {
    if(tree[cur].lz != 0) {
      tree[cur].min = min(tree[cur].min + tree[cur].lz, Inf);
      if(s != e) {
        int l = 2 * cur + 1, r = 2 * cur + 2;
        tree[l].lz = min(tree[l].lz + tree[cur].lz, Inf);
        tree[r].lz = min(tree[r].lz + tree[cur].lz, Inf);
      }
      tree[cur].lz = 0;
    }
  }

  void build(int cur, int s, int e) {
    if(s == e) {
      tree[cur] = TreeNode(0, s);
      return;
    }
    int mid = getMid(s, e);
    int l = 2 * cur + 1, r = 2 * cur + 2;
    build(l, s, mid);
    build(r, mid + 1, e);
    pull(tree[cur], tree[l], tree[r]);
  }

  void init(int n) {
    this->n = n;
    tree.resize(n << 2);
    build(0, 0, n - 1);
  }
  
  void update(int cur, int s, int e, int i, int j, int val) {
    push(cur, s, e);
    if(s > j || e < i) return;
    if(s >= i && e <= j) {
      tree[cur].lz = min(tree[cur].lz + val, Inf);
      push(cur, s, e);
      return;
    }
    int mid = getMid(s, e);
    int l = 2 * cur + 1, r = 2 * cur + 2;
    update(l, s, mid, i, j, val);
    update(r, mid + 1, e, i, j, val);
    pull(tree[cur], tree[l], tree[r]);
  }

  void update(int l, int r, int val) {
    update(0, 0, n - 1, l, r, val);
  }

  TreeNode query(int cur, int s, int e, int i, int j) {
    push(cur, s, e);
    if(s > j || e < i) return TreeNode(Inf, -1);
    if(s >= i && e <= j) return tree[cur];
    int mid = getMid(s, e);
    int l = 2 * cur + 1, r = 2 * cur + 2;
    auto x = query(l, s, mid, i, j), y = query(r, mid + 1, e, i, j);
    TreeNode res;
    pull(res, x, y);
    return res;
  }

  TreeNode query(int i, int j) {
    return query(0, 0, n - 1, i, j);
  }

  void print(int cur, int s, int e) {
    debug(s, e, tree[cur].min, tree[cur].idx);
    if(s != e) {
      int mid = getMid(s, e);
      int l = 2 * cur + 1, r = 2 * cur + 2;
      print(l, s, mid);
      print(r, mid + 1, e);
    }
  }
};

template<typename T>
class fenwick {
public:
  vector<T> fen;
  int n;

  fenwick(int _n) : n(_n) {
    fen.resize(n);
  }

  void add(int x, T v) {
    while(x < n) {
      fen[x] += v;
      x |= x + 1;
    }
  }

  T get(int x) {
    T v{};
    while(x >= 0) {
      v += fen[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};


int n, q;
int a[N];
SegTree st;
vector<pair<int, int>> qr[N];
fenwick<int> fen(N);
int ans[N];


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n >> q;
  st.init(n);

  for(int i = 0; i < n; i++) {
    cin >> a[i];
    st.update(i, i, i - a[i] + 1);
  }

  for(int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    qr[x].push_back({i, n - y - 1});
  }

  vector<int> pos;
  while(true) {
    auto node = st.query(0, n - 1);
    if(node.min < 0) {
      st.update(node.idx, node.idx, Inf);
      continue;
    }
    if(node.min > 0) {
      break;
    }
    pos.push_back(node.idx);
    st.update(node.idx, n - 1, -1);
  }

  int j = 0;
  for(int i = n - 1; i >= 0; i--) {
    while(j < sz(pos) && pos[j] >= i) {
      fen.add(pos[j], 1);
      j++;
    }
    for(int k = 0; k < sz(qr[i]); k++) {
      int idx = qr[i][k].first;
      int r = qr[i][k].second;
      ans[idx] = fen.get(r);
    }
  }

  for(int i = 0; i < q; i++) {
    cout <<  ans[i] << endl;
  }
  return 0;
}
