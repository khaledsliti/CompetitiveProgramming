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

const int N = 1e5 + 5;

struct SegTree {
  struct TreeNode {
    ll sum;
  };
  int n;
  vector<TreeNode> st;
  void build(int cur, int s, int e) {
    if(s == e) {
      st[cur].sum = 0;
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
    return { a.sum + b.sum };
  }
  void update(int cur, int s, int e, int idx, int diff) {
    if(s > idx || e < idx) return;
    if(s == e) {
      st[cur].sum = diff;
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    update(l, s, mid, idx, diff);
    update(r, mid + 1, e, idx, diff);
    st[cur] = merge(st[l], st[r]);
  }
  void update(int idx, int val) {
    update(0, 0, n - 1, idx, val);
  }
  TreeNode query(int cur, int s, int e, int i, int j) {
    if(s > j || e < i) return { 0 };
    if(s >= i && e <= j) return st[cur];
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    return merge(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
  }
  ll query(int i, int j) {
    return query(0, 0, n - 1, i, j).sum;
  }
};

int n;
int idx[N];
SegTree st;

void solve() {
  cin >> n;
  st.init(n);
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    idx[--x] = i;
    st.update(i, x + 1);
  }
  ll ans = 0;
  int j = 0;
  for(int i = 0; i < n; i++) {
    int cur = idx[i];
    // choice 1: from j to i - 1
    ll cost = 0;
    if(j < cur) {
      cost = st.query(j, cur - 1);
    } else if(j > cur) {
      cost = st.query(j, n - 1) + (cur > 0 ? st.query(0, cur - 1) : 0);
    }
    ans += min(cost, st.query(0, n - 1) - cost);
    j = cur;
    st.update(cur, 0);
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
