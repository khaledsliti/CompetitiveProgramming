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
      pushDown(i >> h);
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
      if((l & 1) == 1) apply(l++, op);
      if((r & 1) == 0) apply(r--, op);
    }
    rebuild(i), rebuild(j);
  }

  T query(int i, int j) {
    i += S, j += S;
    propagate(i), propagate(j);
    T resLeft = zero, resRight = zero;
    for(; i <= j; i >>= 1, j >>= 1) {
      if((i & 1) == 1) resLeft = resLeft + values[i++];
      if((j & 1) == 0) resRight = values[j--] + resRight;
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
  long long value;

  Node operator+(const Node& rhs) {
    return {min(value, rhs.value)};
  }
};

struct Update {
  long long value;

  Update operator +(const Update& rhs) {
    return {value + rhs.value};
  }

  Node operator()(const Node& node) {
    return {node.value + value};
  }
};

const int N = 2e5 + 5;

int n, q;
ll p[N];

int main()
{
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
    if(i) p[i] += p[i - 1];
  }
  while(q--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ll ans = p[b] - (a > 0 ? p[a - 1] : 0);
    cout << ans << endl;
  }
  return 0;
}
