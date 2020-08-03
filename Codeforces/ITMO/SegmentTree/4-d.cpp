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

const int A = 41;

struct SegTree {
  struct TreeNode {
    int occ[A];
    TreeNode() {
      memset(occ, 0, sizeof occ);
    }
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
    merge(st[cur], st[l], st[r]);
  }
  void init(int n, TreeNode node) {
    this->n = n;
    st.resize(n << 2);
    build(0, 0, n - 1, node);
  }
  void merge(TreeNode& res, const TreeNode& a, const TreeNode& b) {
    for(int i = 0; i < A; i++)
      res.occ[i] = a.occ[i] | b.occ[i];
  }
  void update(int cur, int s, int e, int idx, int val) {
    if(s > idx || e < idx) return;
    if(s == e) {
      st[cur] = TreeNode();
      st[cur].occ[val] = 1;
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    update(l, s, mid, idx, val);
    update(r, mid + 1, e, idx, val);
    merge(st[cur], st[l], st[r]);
  }
  void update(int idx, int val) {
    update(0, 0, n - 1, idx, val);
  }
  TreeNode query(int cur, int s, int e, int i, int j) {
    if(s > j || e < i) return TreeNode();
    if(s >= i && e <= j) return st[cur];
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    TreeNode ans;
    merge(ans, query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
    return ans;
  }
  TreeNode query(int i, int j) {
    return query(0, 0, n - 1, i, j);
  }
};

int main()
{
  int n, q;
  scanf("%d%d", &n, &q);
  SegTree st;
  st.init(n, SegTree::TreeNode());
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    st.update(i, a);
  }
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int l, r;
      scanf("%d%d", &l, &r);
      auto x = st.query(--l, --r);
      int ans = 0;
      for(int i = 0; i < A; i++)
        ans += x.occ[i];
      printf("%d\n", ans);
    } else {
      int i, v;
      scanf("%d%d", &i, &v);
      st.update(--i, v);
    }
  }
  return 0;
}
