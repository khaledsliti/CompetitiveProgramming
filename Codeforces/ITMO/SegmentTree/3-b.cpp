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

const int N = 1e5 + 5;

struct SegTree {
  struct TreeNode {
    int cnt;
  };
  
  TreeNode zero { 0 };
  int n;
  vector<TreeNode> st;
  void init(int n) {
    this->n = n;
    st.resize(n << 2, TreeNode());
  }
  TreeNode merge(TreeNode a, TreeNode b) {
    TreeNode r { a.cnt + b.cnt };
    return r;
  }
  void update(int cur, int s, int e, int idx) {
    if(s > idx || e < idx) return;
    if(s == e) {
      st[cur].cnt ^= 1;
      return;
    }
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    update(l, s, mid, idx);
    update(r, mid + 1, e, idx);
    st[cur] = merge(st[l], st[r]);
  }
  void update(int idx) {
    update(0, 0, n - 1, idx);
  }
  int query(int cur, int s, int e, int k) {
    if(s == e) return s;
    int mid = (s + e) / 2;
    int left_size = st[2 * cur + 1].cnt;
    if(k < left_size)
      return query(2 * cur + 1, s, mid, k);
    return query(2 * cur + 2, mid + 1, e, k - left_size);
  }
};

int n;
int arr[N];
int ans[N];
SegTree st;

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  st.init(n);
  for(int i = 0; i < n; i++) {
    st.update(i);
  }
  for(int i = n - 1; i >= 0; i--) {
    int j = st.query(0, 0, n - 1, arr[i]);
    ans[i] = n - j;
    st.update(j);
  }
  for(int i = 0; i < n; i++) {
    printf("%d%c", ans[i], " \n"[i == n - 1]);
  }
  return 0;
}
