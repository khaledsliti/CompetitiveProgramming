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

const int N = 2e5 + 5;

int n;
int arr[N];
segmentTree<int, 0> st(
  MergeStrategy<int>([](int a, int b) { return a + b; })
);

int main()
{
  cin >> n;
  st.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    st.update(i, 1);
  }
  for(int i = 0; i < n; i++) {
    int cnt;
    cin >> cnt;
    int l = 0, r = n - 1, idx;
    while(l <= r) {
      int mid = (l + r) / 2;
      if(st.query(0, mid) >= cnt) {
        idx = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << arr[idx] << " ";
    st.update(idx, 0);
  }
  return 0;
}
