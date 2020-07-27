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
  
  TreeNode zero {0};
  int n;
  vector<TreeNode> st;
  void init(int n) {
    this->n = n;
    st.clear();
    st.resize(n << 2, TreeNode());
  }
  TreeNode merge(TreeNode a, TreeNode b) {
    return { a.sum + b.sum };
  }
  void update(int cur, int s, int e, int idx, TreeNode val) {
    if(s > idx || e < idx) return;
    if(s == e) {
      st[cur] = val;
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    update(l, s, mid, idx, val);
    update(r, mid + 1, e, idx, val);
    st[cur] = merge(st[l], st[r]);
  }
  void update(int idx, TreeNode val) {
    update(0, 0, n - 1, idx, val);
  }
  TreeNode query(int cur, int s, int e, int i, int j) {
    if(s > j || e < i) return zero;
    if(s >= i && e <= j) return st[cur];
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    return merge(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
  }
  TreeNode query(int i, int j) {
    return query(0, 0, n - 1, i, j);
  }
};

const int N = 1e5 + 5;

int n;
SegTree st;

int main()
{
  scanf("%d", &n);
  st.init(n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if(i & 1) a = -a;
    st.update(i, {a});
  }
  int q;
  scanf("%d", &q);
  while(q--) {
    int t, a, b;
    scanf("%d%d%d", &t, &a, &b);
    if(t == 0) {
      --a;
      if(a & 1) b = -b;
      st.update(a, {b});
    } else {
      --a, --b;
      ll sum = st.query(a, b).sum;
      if(a & 1) sum = -sum;
      printf("%lld\n", sum);
    }
  }
  return 0;
}
