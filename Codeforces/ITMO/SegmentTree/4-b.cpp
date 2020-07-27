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
const int N = 1e5 + 5;

struct SegTree {
  struct TreeNode {
    ll inv;
    int cnt[A];
    TreeNode(): inv(0) {
      memset(cnt, 0, sizeof cnt);
    }
  };

  int n;
  vector<TreeNode> st;
  void init(int n) {
    this->n = n;
    st.clear();
    st.resize(n << 2, TreeNode());
  }
  void merge(TreeNode& r, const TreeNode& a, const TreeNode& b) {
    r.inv = a.inv + b.inv;
    int pref[A];
    for(int i = 0; i < A; i++) {
      pref[i] = a.cnt[i];
      if(i > 0) pref[i] += pref[i - 1];
    }
    for(int i = 1; i < A; i++) {
      r.inv += 1LL * pref[i - 1] * b.cnt[i];
    }
  }
  void update(int cur, int s, int e, int idx, int old, int nw) {
    if(s > idx || e < idx) return;
    if(s == e) {
      if(old) st[cur].cnt[old]--;
      st[cur].cnt[nw]++;
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    update(l, s, mid, idx, old, nw);
    update(r, mid + 1, e, idx, old, nw);
    merge(st[cur], st[l], st[r]);
  }
  void update(int idx, int old, int nw) {
    update(0, 0, n - 1, idx, old, nw);
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

int n;
int arr[N];
SegTree st;

int main()
{
  int q;
  scanf("%d%d", &n, &q);
  st.init(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    st.update(i, 0, arr[i]);
  }
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int l, r;
      scanf("%d%d", &l, &r);
      --l, --r;
      printf("%lld\n", st.query(l, r).inv);
    } else {
      int idx, val;
      scanf("%d%d", &idx, &val);
      --idx;
      st.update(idx, arr[idx], val);
      arr[idx] = val;
    }
  }
  return 0;
}
