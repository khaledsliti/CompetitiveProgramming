// Guess Who's Back
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

  void print() {
    for(int i = 1; i < values.size(); i++) {
      cout << i << ": " << values[i].value << " " << ops[i].value << "(" << dirty[i] << ")" << endl;;
    }
    cout << endl;
  }
};

struct Node {
  long long sum;
  int length;

  Node operator+(const Node& rhs) {
    return {sum + rhs.sum, length + rhs.length};
  }
};

#define SET_OP 0
#define INC_OP 1

struct Update {
  int type;
  long long value;

  Update operator +(const Update& rhs) {
    if(rhs.type == SET_OP) {
      return {SET_OP, rhs.value};
    } else {
      return {type, value + rhs.value};
    }
  }

  Node operator()(const Node& node) {
    if(type == SET_OP) {
      return {value * node.length, node.length};
    } else {
      return {value * node.length + node.sum, node.length};
    }
  }
};




int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, t;
  cin >> n >> t;
  vector<Node> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i].sum;
    arr[i].length = 1;
  }
  SegTree<Node, Update> st(n, {0, 0}, {INC_OP, 0});
  st.setValues(arr);

  while(t--) {
    int op; cin >> op;
    if(op == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      st.update(--l, --r, {INC_OP, x});
    } else if(op == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      st.update(--l, --r, {SET_OP, x});
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(--l, --r).sum << endl;
    }
  }
  return 0;
}
