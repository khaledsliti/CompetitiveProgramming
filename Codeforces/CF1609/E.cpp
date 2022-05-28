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

const int N = 1e5 + 5;
const int M = 1 << 5;
const int INF = 1e9;

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

int n, q;
string s;
vector<string> strs = {"a", "b", "c", "ab", "bc"};
int mergedMask[M][M];

struct Node {
  int dp[M];
  Node() {
    for(int i = 0; i < M; i++) {
      dp[i] = INF;
    }
  }
  Node operator+(const Node& rhs) {
    Node r;
    for(int m1 = 0; m1 < M; m1++) {
      for(int m2 = 0; m2 < M; m2++) {
        int m = mergedMask[m1][m2];
        if(m != -1) {
          r.dp[m] = min(r.dp[m], dp[m1] + rhs.dp[m2]);
        }
      }
    }
    return r;
  }
};

Node initNode(char c) {
  Node node;
  node.dp[0] = 1;
  node.dp[1 << (c - 'a')] = 0;
  return node;
}

struct Update {
  char c = -1;
  Update operator +(const Update& rhs) {
    if(rhs.c == -1) return *this;
    return rhs;
  }

  Node operator()(const Node& node) {
    if(c == -1) return node;
    return initNode(c);
  }
};

vector<string> getStrs(int msk) {
  vector<string> s;
  for(int i = 0; i < 5; i++) {
    if(msk & (1 << i)) {
      s.push_back(strs[i]);
    }
  }
  return s;
}

bool contains(const string& a, const string& b) {
  for(int i = 0; i + sz(b) <= sz(a); i++) {
    if(a.substr(i, sz(b)) == b) {
      return true;
    }
  }
  return false;
}

int calc(const vector<string>& a, const vector<string>& b) {
  int msk = 0;
  for(int i = 0; i < sz(a); i++) {
    for(int j = 0; j < sz(b); j++) {
      string str = a[i] + b[j];
      if(contains(str, "abc")) {
        return -1;
      }
      for(int k = 0; k < 5; k++) {
        if(contains(str, strs[k])) {
          msk |= (1 << k);
        }
      }
    }
  }
  return msk;
}

void calcMergedMasks() {
  for(int msk1 = 0; msk1 < M; msk1++) {
    for(int msk2 = 0; msk2 < M; msk2++) {
      vector<string> a = getStrs(msk1);
      vector<string> b = getStrs(msk2);
      a.push_back(""), b.push_back("");
      mergedMask[msk1][msk2] = calc(a, b);
    }
  }
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  calcMergedMasks();

  cin >> n >> q >> s;
  SegTree<Node, Update> st(n);
  vector<Node> nodes;
  for(int i = 0; i < n; i++) {
    nodes.push_back(initNode(s[i]));
  }
  st.setValues(nodes);

  auto ans = st.query(0, n - 1);
  cout << *min_element(ans.dp, ans.dp + M) << endl;
  return 0;
}
