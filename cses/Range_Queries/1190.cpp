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

template <typename T>
class segmentTree {
private:
  int n;
  vector<T> st;
  inline int L(int cur) const { return 2 * cur + 1; }
  inline int R(int cur) const { return 2 * cur + 2; }
  void update(int cur, int s, int e, int index, T newValue) {
    if(s > index || e < index) return;
    if(s == e) return void(st[cur] = newValue);
    int mid = (s + e) / 2;
    update(L(cur), s, mid, index, newValue);
    update(R(cur), mid + 1, e, index, newValue);
    st[cur] = merge(st[L(cur)], st[R(cur)]);
  }
  T query(int cur, int s, int e, int i, int j) {
    if(s > j || e < i) return T::identity();
    if(s >= i && e <= j) return st[cur];
    int mid = (s + e) / 2;
    auto left = query(L(cur), s, mid, i, j);
    auto right = query(R(cur), mid + 1, e, i, j);
    return merge(left, right);
  }
public:
  segmentTree(): n(0) {}
  segmentTree(int n): n(n) { st.resize(n << 2, T()); }
  void resize(int n, T defaultValue) { this->n = n; st.clear(); st.resize(n << 2, defaultValue); }
  void resize(int n) { this->n = n; st.clear(); st.resize(n << 2, T::identity()); }
  void update(int index, T newValue) { update(0, 0, n - 1, index, newValue); }
  T query(int l, int r) { return query(0, 0, n - 1, l, r); }
  friend ostream& operator<< (ostream& cout, const segmentTree& s) {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, s.n - 1});
    while(!q.empty()) {
      int cur = get<0>(q.front());
      int l = get<1>(q.front()), r = get<2>(q.front());
      q.pop();
      cout << cur << " - [" << l << " - " << r << "] = " << s.st[cur] << endl;
      if(l != r) {
        int mid = (l + r) / 2;
        q.push({s.L(cur), l, mid});
        q.push({s.R(cur), mid + 1, r});
      }
    }
    return cout;
  }
};

struct Node {
  ll pref, sum, suff, best;
  Node() = default;
  static Node identity() { return {0, 0, 0, -Inf}; }
  friend Node merge(const Node& a, const Node& b) {
    Node r;
    r.pref = max(a.pref, a.sum + b.pref);
    r.sum = a.sum + b.sum;
    r.suff = max(b.suff, b.sum + a.suff);
    r.best = max(a.best, max(b.best, a.suff + b.pref));
    return r;
  }
  friend ostream& operator<< (ostream& cout, const Node& a) {
    cout << a.pref << " " << a.sum << " " << a.suff << " " << a.best;
    return cout;
  }
};

int n, q;
segmentTree<Node> st;

int main()
{
  cin >> n >> q;
  st.resize(n);
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    st.update(i, {a, a, a, a});
  }
  while(q--) {
    int k, v;
    cin >> k >> v;
    st.update(--k, {v, v, v, v});
    cout << st.query(0, n - 1).best << endl;
  }
  return 0;
}
