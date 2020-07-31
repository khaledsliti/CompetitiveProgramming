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
    if(s > j || e < i) return {INT_MAX};
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

const int N = 2e5 + 5;

int n, q;
int a[N];
SegTree stree;
int st[N], en[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  int z = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] == q)
      z = 1;
  }
  if(z == 0) {
    for(int i = 0; i < n; i++)
      if(!a[i]) {
        a[i] = q;
        break;
      }
  }

  for(int i = 1; i < n; i++)
    if(a[i - 1] && !a[i])
      a[i] = a[i - 1];
  for(int i = n - 2; i >= 0; i--)
    if(a[i + 1] && !a[i])
      a[i] = a[i + 1];

  memset(st, -1, sizeof st);
  stree.init(n, {INT_MAX});
  for(int i = 0; i < n; i++) {
    if(st[a[i]] == -1) st[a[i]] = i;
    en[a[i]] = i;
    stree.update(i, {a[i]});
  }

  bool yes = st[q] != -1;
  for(int i = 1; i <= q; i++) {
    if(st[i] == -1) continue;
    int l = st[i], r = en[i];
    int mn = stree.query(l, r).min;
    if(mn < i) yes = false;
  }
  if(!yes) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for(int i = 0; i < n; i++)
      cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}
