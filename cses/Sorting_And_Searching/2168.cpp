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

const int N = 2e5 + 5;

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

function<int(int, int)> comp;

struct Node {
  int val;

  Node operator+(const Node& rhs) {
    return { comp(val, rhs.val) };
  }
};

struct Update {
  int val;

  Update operator +(const Update& rhs) {
    return { comp(val, rhs.val) };
  }

  Node operator()(const Node& node) {
    return { comp(val, node.val) };
  }
};

int n;
array<int, 3> arr[N];
int have[N], in[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> values;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 2; j++) {
      cin >> arr[i][j];
      values.push_back(arr[i][j]);
    }
  }
  sort(all(values));
  values.resize(unique(all(values)) - begin(values));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 2; j++) {
      arr[i][j] = lower_bound(all(values), arr[i][j]) - begin(values);
    }
    arr[i][2] = i;
  }

  sort(arr, arr + n, [&](const array<int, 3>& a, const  array<int, 3>& b) {
    if(a[0] != b[0]) {
      return a[0] < b[0];
    }
    return a[1] > b[1];
  });

  comp = [](int a, int b) { return a < b ? a : b; };
  SegTree<Node, Update> st_min(sz(values) + 1, {INT_MAX}, {INT_MAX});
  
  for(int i = n - 1; i >= 0; i--) {
    int l = arr[i][0], r = arr[i][1];
    auto cur = st_min.query(l, r);
    if(cur.val <= r) {
      have[arr[i][2]] = 1;
    }
    st_min.update(l, l, {r});
  }

  for(int i = 0; i < n; i++) {
    cout << have[i] << " ";
  }
  cout << endl;

  comp = [](int a, int b) { return a > b ? a : b; };
  SegTree<Node, Update> st_max(sz(values) + 1, {INT_MIN}, {INT_MIN});

  for(int i = 0; i < n; i++) {
    int l = arr[i][0], r = arr[i][1];
    auto cur = st_max.query(0, l);
    if(cur.val >= r) {
      in[arr[i][2]] = 1;
    }
    st_max.update(l, l, {r});
  }

  for(int i = 0; i < n; i++) {
    cout << in[i] << " ";
  }
  cout << endl;

  return 0;
}
