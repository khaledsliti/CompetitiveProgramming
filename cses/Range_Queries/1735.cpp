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

struct Node {
  ll sum, toSet, toAdd;
  Node() = default;
  Node(ll s, ll ts, ll ta): sum(s), toSet(ts), toAdd(ta) {}
};

int n;
int arr[N];
Node st[N << 2];

inline int L(int x) { return (x << 1) + 1; }
inline int R(int x) { return (x << 1) + 2; }
inline int Mid(int s, int e) { return s + (e - s) / 2; }

Node merge(const Node& a, const Node& b) {
  return Node(a.sum + b.sum, 0, 0);
}

void build(int cur, int s, int e) {
  if(s == e) {
    st[cur] = Node(arr[s], 0, 0);
    return;
  }
  int mid = Mid(s, e);
  build(L(cur), s, mid);
  build(R(cur), mid + 1, e);
  st[cur] = merge(st[L(cur)], st[R(cur)]);
}

void push_down(int cur, int s, int e) {
  if(st[cur].toSet != 0) {
    st[cur].sum = st[cur].toSet * (e - s + 1);
    if(s != e) {
      st[L(cur)].toAdd = st[R(cur)].toAdd = 0;
      st[L(cur)].toSet = st[R(cur)].toSet = st[cur].toSet;
    }
    st[cur].toSet = 0;
  }
  if(st[cur].toAdd != 0) {
    st[cur].sum += st[cur].toAdd * (e - s + 1);
    if(s != e) {
      st[L(cur)].toAdd += st[cur].toAdd;
      st[R(cur)].toAdd += st[cur].toAdd;
    }
    st[cur].toAdd = 0;
  }
}

void increase(int cur, int s, int e, int i, int j, int x) {
  push_down(cur, s, e);
  if(s > j || e < i) return;
  if(s >= i && e <= j) {
    st[cur].toAdd += x;
    push_down(cur, s, e);
    return;
  }
  int mid = Mid(s, e);
  increase(L(cur), s, mid, i, j, x);
  increase(R(cur), mid + 1, e, i, j, x);
  st[cur] = merge(st[L(cur)], st[R(cur)]);
}

void assign(int cur, int s, int e, int i, int j, int x) {
  push_down(cur, s, e);
  if(s > j || e < i) return;
  if(s >= i && e <= j) {
    st[cur].toAdd = 0;
    st[cur].toSet = x;
    push_down(cur, s, e);
    return;
  }
  int mid = Mid(s, e);
  assign(L(cur), s, mid, i, j, x);
  assign(R(cur), mid + 1, e, i, j, x);
  st[cur] = merge(st[L(cur)], st[R(cur)]);
}

Node query(int cur, int s, int e, int i, int j) {
  push_down(cur, s, e);
  if(s > j || e < i) return Node(0, 0, 0);
  if(s >= i && e <= j) return st[cur];
  int mid = Mid(s, e);
  return merge(query(L(cur), s, mid, i, j), query(R(cur), mid + 1, e, i, j));
}

int main()
{
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(0, 0, n - 1);
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) { // inc
      int a, b, x;
      cin >> a >> b >> x;
      --a, --b;
      increase(0, 0, n - 1, a, b, x);
    } else if(t == 2) { // set
      int a, b, x;
      cin >> a >> b >> x;
      --a, --b;
      assign(0, 0, n - 1, a, b, x);
    } else { // get
      int a, b;
      cin >> a >> b;
      --a, --b;
      cout << query(0, 0, n - 1, a, b).sum << endl;
    }
  }
  return 0;
}
