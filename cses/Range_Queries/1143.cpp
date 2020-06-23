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
struct MergeStrategy {
private:
  typedef function<T(T, T)> func;
  func merge;
public:
  MergeStrategy(func merge): merge(merge) {}
  T operator()(const T& a, const T& b) const { return merge(a, b); }
};

template <typename T, T identity>
class segmentTree {
private:
  int n;
  vector<T> st;
  MergeStrategy<T> merge;
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
    if(s > j || e < i) return identity;
    if(s >= i && e <= j) return st[cur];
    int mid = (s + e) / 2;
    auto left = query(L(cur), s, mid, i, j);
    auto right = query(R(cur), mid + 1, e, i, j);
    return merge(left, right);
  }
public:
  segmentTree(MergeStrategy<T> merge): n(0), merge(merge) {}
  segmentTree(int n, MergeStrategy<T> merge): n(n), merge(merge) { st.resize(n << 2, T()); }
  void resize(int n, T defaultValue) { this->n = n; st.clear(); st.resize(n << 2, defaultValue); }
  void resize(int n) { this->n = n; st.clear(); st.resize(n << 2, identity); }
  void update(int index, T newValue) { update(0, 0, n - 1, index, newValue); }
  T query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

int n, m;
segmentTree<int, INT_MIN> st(
  MergeStrategy<int>([](int a, int b){ return max(a, b); })
);

int main()
{
  cin >> n >> m;
  st.resize(n);
  for(int i = 0; i < n; i++) {
    int h; cin >> h;
    st.update(i, h);
  }
  while(m--) {
    int x;
    cin >> x;
    int l = 0, r = n - 1, idx = -1, best = 0;
    while(l <= r) {
      int mid = (l + r) / 2;
      int val = st.query(0, mid);
      if(val < x) {
        l = mid + 1;
      } else {
        idx = mid;
        best = val;
        r = mid - 1;
      }
    }
    cout << idx + 1 << " ";
    if(idx != -1) st.update(idx, best - x);
  }
  cout << endl;
  return 0;
}
