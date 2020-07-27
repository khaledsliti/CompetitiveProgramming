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

struct SegTree {
  struct TreeNode {
    ll sum;
    TreeNode() = default;
  };

  TreeNode zero { 0 };
  int n;
  vector<TreeNode> st;
  void init(int n, TreeNode v) {
    this->n = n;
    st.clear();
    st.resize(n << 2, v);
  }
  TreeNode merge(TreeNode a, TreeNode b) {
    return { a.sum + b.sum };
  }
  void update(int cur, int s, int e, int idx, int val) {
    if(s > idx || e < idx) return;
    if(s == e) {
      st[cur].sum += val;
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    update(l, s, mid, idx, val);
    update(r, mid + 1, e, idx, val);
    st[cur] = merge(st[l], st[r]);
  }
  void update(int l, int r, int val) {
    update(0, 0, n - 1, l, val);
    update(0, 0, n - 1, r, -val);
  }
  TreeNode query(int cur, int s, int e, int i, int j) {
    if(s > j || e < i) return zero;
    if(s >= i && e <= j) return st[cur];
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    return merge(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
  }
  ll query(int i) {
    return query(0, 0, n - 1, 0, i).sum;
  }
};

int main()
{
  int n, q;
  scanf("%d%d", &n, &q);
  SegTree st;
  st.init(n + 1, {0});
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 2) {
      int idx;
      scanf("%d", &idx);
      printf("%lld\n", st.query(idx));
    } else {
      int l, r, v;
      scanf("%d%d%d", &l, &r, &v);
      st.update(l, r, v);
    }
  }
  return 0;
}
