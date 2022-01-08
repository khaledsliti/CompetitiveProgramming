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
  int min;
  int lenght;

  Node operator+(const Node& rhs) {
    return { std::min(min, rhs.min), lenght + rhs.lenght };
  }
};

struct Update {
  int add;

  Update operator +(const Update& rhs) {
    return { add + rhs.add };
  }

  Node operator()(const Node& node) {
    return { node.min + add , node.lenght };
  }
};

const int N = 1e5 + 5;
const int INF = 1e9;

int n, m;
int ta[N], low[N];
SegTree<Node, Update> st(N, {INF, 0}, {0});

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> ta[i];
    st.update(0, ta[i], {1});
  }
  vector<vector<int>> g(m);
  vector<ll> sum(m, 0);
  for(int i = 0; i < m; i++) {
    int k; cin >> k;
    g[i].resize(k);
    for(int j = 0; j < k; j++) {
      cin >> g[i][j];
      sum[i] += g[i][j];
    }
    low[i] = (sum[i] + sz(g[i]) - 1) / sz(g[i]);
    st.update(0, low[i], {-1});
  }

  for(int i = 0; i < m; i++) {
    st.update(0, low[i], {+1});
    for(int j = 0; j < sz(g[i]); j++) {
      int val = (sum[i] - g[i][j] + sz(g[i]) - 2) / (sz(g[i]) - 1);
      st.update(0, val, {-1});
      if(st.query(0, N - 1).min >= 0) {
        cout << 1;
      } else {
        cout << 0;
      }
      st.update(0, val, {+1});
    }
    st.update(0, low[i], {-1});
  }
  cout << endl;

  for(int i = 0; i < n; i++) {
    st.update(0, ta[i], {-1});
  }
  for(int i = 0; i < m; i++) {
    st.update(0, low[i], {+1});
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<Node> nodes(N, {0, 1});
  st.setValues(nodes);
  
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
