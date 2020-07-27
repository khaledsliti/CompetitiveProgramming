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
    int sum;
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
int arr[N << 1];
int last[N];
int ans[N];
SegTree st;

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n * 2; i++) {
    scanf("%d", &arr[i]);
  }
  for(int it = 0; it < 2; it++) {
    memset(last, -1, sizeof last);
    st.init(2 * n, {0});
    for(int i = 0; i < 2 * n; i++) {
      if(last[arr[i]] == -1) {
        last[arr[i]] = i;
      } else {
        ans[arr[i]] += st.query(last[arr[i]], i).sum;
        st.update(i, {1});
        st.update(last[arr[i]], {-1});
      }
    }
    reverse(arr, arr + 2 * n);
  }
  for(int i = 1; i <= n; i++)
    printf("%d%c", ans[i], " \n"[i == n]);
  return 0;
}
