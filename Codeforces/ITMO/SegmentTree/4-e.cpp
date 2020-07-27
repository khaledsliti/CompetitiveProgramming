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
    int min;
    TreeNode() = default;
  };
  
  TreeNode zero {INT_MIN};
  int n;
  vector<TreeNode> st;
  void init(int n) {
    this->n = n;
    st.clear();
    st.resize(n << 2, TreeNode());
  }
  TreeNode merge(TreeNode a, TreeNode b) {
    return {min(a.min, b.min)};
  }
  int update(int cur, int s, int e, int i, int j, int val) {
    if(s > j || e < i) return 0;
    if(st[cur].min > val) return 0;
    if(s == e) {
      st[cur].min = INT_MAX;
      return 1;
    }
    int ret = 0;
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    ret += update(l, s, mid, i, j, val);
    ret += update(r, mid + 1, e, i, j, val);
    st[cur] = merge(st[l], st[r]);
    return ret;
  }
  int update(int l, int r, int val) {
    return update(0, 0, n - 1, l, r, val);
  }
  void set(int cur, int s, int e, int idx, int val) {
    if(s > idx || e < idx) return;
    if(s == e) {
      st[cur].min = val;
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    set(l, s, mid, idx, val);
    set(r, mid + 1, e, idx, val);
    st[cur] = merge(st[l], st[r]);
  }
  void print(int cur, int s, int e) {
    if(s == e) {
      cout << s << " " << st[cur].min << endl;
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    print(l, s, mid);
    print(r, mid + 1, e);
  }
};

int n, q;
SegTree st;


int main()
{
  scanf("%d%d", &n, &q);
  st.init(n);
  for(int i = 0; i < n; i++)
    st.set(0, 0, n - 1, i, INT_MAX);
  for(int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int idx, h;
      scanf("%d%d", &idx, &h);
      st.set(0, 0, n - 1, idx, h);
    } else {
      int l, r, p;
      scanf("%d%d%d", &l, &r, &p);
      printf("%d\n", st.update(l, r - 1, p));
    }
  }
  return 0;
}
