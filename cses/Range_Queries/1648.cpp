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

template <typename T>
class segmentTree {
  typedef function<T(const T& a, const T& b)> MergeFunc;
  int n;
  vector<T> st;
  MergeFunc merge;
  T emptySegmentValue;
  inline int L(int cur) { return 2 * cur + 1; }
  inline int R(int cur) { return 2 * cur + 2; }
  void update(int cur, int s, int e, int index, T newValue) {
    if(s > index || e < index) return;
    if(s == e) return void(st[cur] = newValue);
    int mid = (s + e) / 2;
    update(L(cur), s, mid, index, newValue);
    update(R(cur), mid + 1, e, index, newValue);
    st[cur] = merge(st[L(cur)], st[R(cur)]);
  }
  T query(int cur, int s, int e, int i, int j) {
    if(s > j || e < i) return emptySegmentValue;
    if(s >= i && e <= j) return st[cur];
    int mid = (s + e) / 2;
    auto left = query(L(cur), s, mid, i, j);
    auto right = query(R(cur), mid + 1, e, i, j);
    return merge(left, right);
  }
public:
  segmentTree(int n, T emptySegmentValue, MergeFunc merge) :
    n(n), emptySegmentValue(emptySegmentValue), merge(merge) { st.resize(n << 2, T()); }
  segmentTree(int n, T emptySegmentValue, T defaultValue, MergeFunc merge) :
    n(n), emptySegmentValue(emptySegmentValue), merge(merge) { st.resize(n << 2, defaultValue); }
  void update(int index, T newValue) { update(0, 0, n - 1, index, newValue); }
  T query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

const int N = 2e5 + 5;

int main()
{
  int n, q;
  cin >> n >> q;
  segmentTree<ll> st(n, 0LL, [](const ll& a, const ll& b) { return a + b; });
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    st.update(i, a);
  }
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int i, v;
      cin >> i >> v;
      st.update(--i, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(--l, --r) << endl;
    }
  }
  return 0;
}
