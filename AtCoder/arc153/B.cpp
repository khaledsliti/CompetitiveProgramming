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
string to_string(const string &s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(const pair<A, B> &p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename T>
string to_string(const vector<T> &v) {
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
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(const pair<A, B> &p) {
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

const int N = 5e5 + 6;

struct implicit_treap {
  struct node {
    int prior, size;
    int val;
    int lazy;
    node *l, *r;
  };
  typedef node *pnode;
  pnode root = nullptr;
  int get_sz(pnode t) { return t ? t->size : 0; }
  void upd_sz(pnode t) {
    if (t) t->size = get_sz(t->l) + 1 + get_sz(t->r);
  }
  void push_down(pnode t) {
    if (!t || !t->lazy) return;
    if (t->l) t->l->lazy ^= 1;
    if (t->r) t->r->lazy ^= 1;
    swap(t->l, t->r);
    t->lazy = 0;
  }
  void split(pnode t, pnode &l, pnode &r, int pos, int add = 0) {
    if (!t) return void(l = r = NULL);
    push_down(t);
    int cur_pos = add + get_sz(t->l);
    if (cur_pos <= pos)
      split(t->r, t->r, r, pos, cur_pos + 1), l = t;
    else
      split(t->l, l, t->l, pos, add), r = t;
    upd_sz(t);
  }
  void merge(pnode &t, pnode l, pnode r) {
    push_down(l);
    push_down(r);
    if (!l || !r)
      t = l ? l : r;
    else if (l->prior > r->prior)
      merge(l->r, l->r, r), t = l;
    else
      merge(r->l, l, r->l), t = r;
    upd_sz(t);
  }
  pnode init(int val) {
    pnode ret = (pnode)malloc(sizeof(node));
    ret->prior = rand();
    ret->size = 1;
    ret->val = val;
    ret->lazy = 0;
    ret->l = ret->r = nullptr;
    return ret;
  }
  void insert(pnode &t, int val, int pos) {
    pnode L, R, mid;
    split(t, L, R, pos - 1);
    merge(mid, L, init(val));
    merge(t, mid, R);
  }
  void range_update(pnode &t, int l, int r) {
    pnode L, mid, R;
    split(t, L, mid, l - 1);
    split(mid, t, R, r - l);
    t->lazy ^= 1;
    merge(mid, L, t);
    merge(t, mid, R);
  }
  int query(pnode &t, int pos) {
    pnode L, mid, R;
    split(t, L, mid, pos - 1);
    split(mid, t, R, pos);
    int ret = t->val;
    merge(mid, L, t);
    merge(t, mid, R);
    return ret;
  }
  void push_back(int val) {
    pnode tmp = root;
    merge(root, tmp, init(val));
  }
  void insert(int pos, int val) {
    insert(root, val, pos);
  }
  void range_update(int l, int r) { range_update(root, l, r); }
  void get(pnode t, vector<int> &ret) {
    if (!t) {
      return;
    }
    push_down(t);
    get(t->l, ret);
    ret.push_back(t->val);
    get(t->r, ret);
  }
  vector<int> get() {
    vector<int> ret;
    get(root, ret);
    return ret;
  }
};

int n, m;
string s[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  implicit_treap row, col;
  for (int i = 0; i < n; i++) {
    row.insert(i, i);
  }
  for (int j = 0; j < m; j++) {
    col.insert(j, j);
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    row.range_update(0, a - 1);
    row.range_update(a, n - 1);
    col.range_update(0, b - 1);
    col.range_update(b, m - 1);
  }

  vector<int> r = row.get(), c = col.get();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << s[r[i]][c[j]];
    }
    cout << endl;
  }

  return 0;
}
