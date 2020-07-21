// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2e5 + 5;
const ll Inf = 1e18;

struct Node {
  ll sum, pref, suff, best;
};

Node merge(Node& a, Node& b) {
  Node r;
  r.pref = max(a.pref, a.sum + b.pref);
  r.sum = a.sum + b.sum;
  r.suff = max(a.suff + b.sum, b.suff);
  r.best = max(a.best, max(b.best, a.suff + b.pref));
  return r;
}

Node Empty = { 0, 0, 0, 0 };

struct SegmentTree {
  int size;
  vector<Node> st;

  void init(int n) {
    size = 1;
    while(size < n) {
      size *= 2;
    }
    st.clear();
    st.resize(2 * size, Empty);
  }

  void update(int cur, int s, int e, int index, int val) {
    if(index < s || index > e) return;  
    if(s == e) {
      st[cur] = { val, val, val, val };
      return;
    }
    int mid = s + (e - s) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    update(l, s, mid, index, val);
    update(r, mid + 1, e, index, val);
    st[cur] = merge(st[l], st[r]);
  }

  Node get(int cur, int s, int e, int i, int j) {
    if(i > e || j < s) return Empty;
    if(s >= i && e <= j) return st[cur];
    int mid = s + (e - s) / 2;
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    auto L = get(l, s, mid, i, j);
    auto R = get(r, mid + 1, e, i, j);
    return merge(L, R);
  }
};

int n, q;
SegmentTree st;

int main()
{
  cin >> n >> q;
  st.init(n);
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    st.update(0, 0, n - 1, i, a);
  }
  while(q--) {
    int k, v;
    cin >> k >> v;
    st.update(0, 0, n - 1, --k, v);
    cout << max(0LL, st.get(0, 0, n - 1, 0, n - 1).best) << endl;
  }
  return 0;
}
