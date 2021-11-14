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

template<typename T, typename U>
struct SegTree {
  int S, H;
  T zero;
  vector<T> values;
  U noop;
  vector<U> ops;
  vector<bool> dirty;

  inline int left(int i) { return i << 1; }
  inline int right(int i) { return (i << 1) | 1; }
  inline bool isLeft(int i) { return (i & 1) == 0; }
  inline bool isRight(int i) { return !isLeft(i); }

  SegTree<T, U>(int _S, T _zero = T(), U _noop = U()): zero(_zero), noop(_noop) {
    for(S = 1, H = 1; S < _S; ) {
      S <<= 1;
      H++;
    }
    values.resize(S << 1, zero);
    ops.resize(S << 1, noop);
    dirty.resize(S << 1, false);
  }

  void setValues(const vector<T>& leaves) {
    copy(leaves.begin(), leaves.end(), values.begin() + S);
    for(int i = S - 1; i > 0; i--) {
      values[i] = values[left(i)] + values[right(i)];
    }
  }

  void apply(int i, U update) {
    ops[i] = ops[i] + update;
    dirty[i] = true;
  }

  void pushDown(int i) {
    if(dirty[i]) {
      values[i] = ops[i](values[i]);
      if(i < S) {
        apply(left(i), ops[i]);
        apply(right(i), ops[i]);
      }
      dirty[i] = false;
      ops[i] = noop;
    }
  }

  void propagate(int i) {
    for(int h = H - 1; h >= 0; h--) {
      int node = i >> h;
      pushDown(node);
      if(node < S) {
        pushDown(left(node));
        pushDown(right(node));
      }
    }
  }

  void rebuild(int i) {
    for(int l = i; l > 0; l >>= 1) {
      pushDown(l);
      if(l < S) {
        pushDown(left(l));
        pushDown(right(l));
        values[l] = values[left(l)] + values[right(l)];
      }
    }
  }

  void update(int i, int j, U op) {
    i += S, j += S;
    propagate(i), propagate(j);
    for(int l = i, r = j; l <= r; l >>= 1, r >>= 1) {
      if(isRight(l)) apply(l++, op);
      if(isLeft(r)) apply(r--, op);
    }
    rebuild(i), rebuild(j);
  }

  T query(int i, int j) {
    i += S, j += S;
    propagate(i), propagate(j);
    T resLeft = zero, resRight = zero;
    for(; i <= j; i >>= 1, j >>= 1) {
      if(isRight(i)) resLeft = resLeft + values[i++];
      if(isLeft(j)) resRight = values[j--] + resRight;
    }
    return resLeft + resRight;
  }
};

struct Node {
  int length;
  long long sum;

  Node operator+(const Node& rhs) const {
    return min(*this, rhs);
  }

  bool operator<(const Node& rhs) const {
    if(length != rhs.length) {
      return length > rhs.length;
    }
    return sum > rhs.sum;
  }

  Node operator()(const Node& rhs) const {
    return min(*this, rhs);
  }
};

const int N = 1e5 + 6;

int n;
int val[N], cost[N];

void solve() {
  cin >> n;
  vector<int> values;
  for(int i = 0; i < n; i++) {
    cin >> val[i];
    values.push_back(val[i]);
  }

  sort(all(values));
  values.resize(unique(all(values)) - begin(values));

  for(int i = 0; i < n; i++) {
    val[i] = lower_bound(all(values), val[i]) - begin(values);
  }

  for(int i = 0; i < n; i++) {
    cin >> cost[i];
  }

  Node ans {0, 0};
  SegTree<Node, Node> st(sz(values), {0, 0}, {0, 0});

  for(int i = 0; i < n; i++) {
    Node cur{1, cost[i]};
    if(val[i] > 0) {
      auto q = st.query(0, val[i] - 1);
      cur.length += q.length;
      cur.sum += q.sum;
    }
    ans = min(ans, cur);
    st.update(val[i], val[i], cur);
  }

  cout << ans.length << " " << ans.sum << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifndef LOCAL
  freopen("blocks.in", "r", stdin);
#endif

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}