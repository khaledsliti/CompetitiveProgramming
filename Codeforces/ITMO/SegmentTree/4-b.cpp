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

int mod;

struct SegTree {
  struct TreeNode {
    int a[2][2];
    TreeNode() {
      a[0][0] = a[1][1] = 1;
      a[0][1] = a[1][0] = 0;
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
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++) {
        res.a[i][j] = 0;
        for(int k = 0; k < 2; k++)
          res.a[i][j] = (res.a[i][j] + 1LL * a.a[i][k] * b.a[k][j] % mod) % mod;
      }
  }
  void update(int cur, int s, int e, int idx, int a[2][2]) {
    if(s > idx || e < idx) return;
    if(s == e) {
      for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
          st[cur].a[i][j] = a[i][j];
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    update(l, s, mid, idx, a);
    update(r, mid + 1, e, idx, a);
    merge(st[cur], st[l], st[r]);
  }
  void update(int idx, int a[2][2]) {
    update(0, 0, n - 1, idx, a);
  }
  TreeNode query(int cur, int s, int e, int i, int j) {
    if(s > j || e < i) return TreeNode();
    if(s >= i && e <= j) return st[cur];
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    TreeNode res;
    merge(res, query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
    return res;
  }
  TreeNode query(int i, int j) {
    return query(0, 0, n - 1, i, j);
  }
};

int n, q;


int main()
{
  scanf("%d%d%d", &mod, &n, &q);
  SegTree st;
  st.init(n, SegTree::TreeNode());
  for(int i = 0; i < n; i++) {
    int a[2][2];
    for(int j = 0; j < 2; j++)
      for(int k = 0; k < 2; k++)
        scanf("%d", &a[j][k]);
    st.update(i, a);
  }
  while(q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    auto m = st.query(--l, --r);
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++)
        printf("%d%c", m.a[i][j], " \n"[j]);
    }
    printf("\n");
  }
  return 0;
}
