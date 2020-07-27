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
  int n;
  vector<int> st;
  void init(int n) {
    this->n = n;
    st.resize(n << 2, 0);
  }
  void update(int cur, int s, int e, int idx, int val) {
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
    st[cur] = st[l] + st[r];
  }
  void update(int idx, int val) {
    update(0, 0, n - 1, idx, val);
  }
  int query(int cur, int s, int e, int i, int j) {
    if(s > j || e < i) return 0;
    if(s >= i && e <= j) return st[cur];
    int mid = (s + e) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    return query(l, s, mid, i, j) + query(r, mid + 1, e, i, j);
  }
  int query(int i, int j) {
    return query(0, 0, n - 1, i, j);
  }
};

int main()
{
  SegTree st;
  int n;
  scanf("%d", &n);
  st.init(n);
  for(int i = 0; i < n; i++) {
    int a; scanf("%d", &a);
    --a;
    int cur = st.query(a, n - 1);
    st.update(a, 1);
    printf("%d ", cur);
  }
  printf("\n");
  return 0;
}
