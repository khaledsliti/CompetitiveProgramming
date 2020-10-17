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

const int N = 3e5 + 5;


struct SegTree {
  struct TreeNode {
    int max;
  };
  int n;
  vector<TreeNode> st;
  void build(int cur, int s, int e) {
    if(s == e) {
      st[cur] = { 0 };
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1, r = 2 * cur + 2;
    build(l, s, mid);
    build(r, mid + 1, e);
    st[cur] = merge(st[l], st[r]);
  }
  void init(int n) {
    this->n = n;
    st.resize(n << 2);
    build(0, 0, n - 1);
  }
  TreeNode merge(TreeNode a, TreeNode b) {
    return { max(a.max, b.max) };
  }
  void update(int cur, int s, int e, int idx, int val) {
    if(s > idx || e < idx) return;
    if(s == e) {
      st[cur].max = max(st[cur].max, val);
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
    if(s > j || e < i) return {0};
    if(s >= i && e <= j) return st[cur];
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    return merge(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
  }
  int query(int i, int j) {
    return query(0, 0, n - 1, i, j).max;
  }
};

int n, k;
SegTree st;
int a[N];

int main()
{
  cin >> n >> k;
  st.init(N);

  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 0;

  for(int i = n - 1; i >= 0; i--) {
    int v = a[i];
    int l = max(0, v - k), r = min(N - 1, v + k);
    int m = st.query(l, r);
    ans = max(ans, 1 + m);
    st.update(v, 1 + m);
  }

  cout << ans << endl;
  return 0;
}
