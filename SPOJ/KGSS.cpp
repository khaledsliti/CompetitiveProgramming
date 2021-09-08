// Guess Who's Back
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

class SegTree {
  struct Node {
    vector<int> data;
    Node() = default;
    static Node identity() {
      return {{-1, -1}};
    }
    friend Node merge(const Node& a, const Node& b) {
      Node res;
      res.data.insert(res.data.end(), a.data.begin(), a.data.end());
      res.data.insert(res.data.end(), b.data.begin(), b.data.end());
      sort(res.data.begin(), res.data.end());
      reverse(res.data.begin(), res.data.end());
      while(res.data.size() > 2) res.data.pop_back();
      return res;
    }
    int getAns() {
      return data[0] + data[1];
    }
  };

  int n;
  vector<Node> st;
  inline int getLeft(int cur) const { return 2 * cur + 1; }
  inline int getRight(int cur) const { return 2 * cur + 2; }
  inline int getMid(int s, int e) const { return s + (e - s) / 2; }
  void assign(int cur, int s, int e, int i, int j, int newValue) {
    if(s > j || e < i) return;
    if(s >= i && e <= j) {
      st[cur].data = {newValue, INT_MIN};
      return;
    }
    int mid = getMid(s, e);
    assign(getLeft(cur), s, mid, i, j, newValue);
    assign(getRight(cur), mid + 1, e, i, j, newValue);
    st[cur] = merge(st[getLeft(cur)], st[getRight(cur)]);
  }
  Node query(int cur, int s, int e, int i, int j) {
    if(s > j || e < i) return Node::identity();
    if(s >= i && e <= j) return st[cur];
    int mid = getMid(s, e);
    auto left = query(getLeft(cur), s, mid, i, j);
    auto right = query(getRight(cur), mid + 1, e, i, j);
    return merge(left, right);
  }
  void build(int cur, int s, int e) {
    if(s == e) {
      st[cur] = Node::identity();
      return;
    }
    int mid = getMid(s, e);
    build(getLeft(cur), s, mid);
    build(getRight(cur), mid + 1, e);
    st[cur] = merge(st[getLeft(cur)], st[getRight(cur)]);
  }
public:
  SegTree() {}
  void init(int n) {
    this->n = n;
    st.resize(n << 2);
    build(0, 0, n - 1);
  }
  void assign(int l, int r, int newValue) { assign(0, 0, n - 1, l, r, newValue); }
  int query(int l, int r) {
    return query(0, 0, n - 1, l, r).getAns();
  }
};

int main()
{
  int n;
  scanf("%d", &n);
  SegTree seg;
  seg.init(n);
  for(int i = 0; i < n; i++) {
    int a; scanf("%d", &a);
    seg.assign(i, i, a);
  }

  int q;
  scanf("%d", &q);
  while(q--) {
    char t;
    scanf(" %c", &t);
    if(t == 'U') {
      int x, v;
      scanf("%d%d", &x, &v);
      --x;
      seg.assign(x, x, v);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", seg.query(--l, --r));
    }
  }
  return 0;
}
