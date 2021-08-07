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

const int N = 3e5 + 5;
const int V = 1e6 + 5;

struct Seg {
  int l, r;
  int cost;
  bool operator<(const Seg& rhs) const {
    return cost > rhs.cost;
  }
};

struct Node {
  int val;
  int delta;
  Node() = default;
  Node(int val): val(val), delta(0) {}
};


int n, m;
Seg arr[N];
Node st[V << 2];



inline int L(int x) { return (x << 1) + 1; }
inline int R(int x) { return (x << 1) + 2; }
inline int Mid(int s, int e) { return s + (e - s) / 2; }

Node merge(const Node& a, const Node& b) {
  return Node(min(a.val, b.val));
}

void push_down(int cur, int s, int e) {
  if(st[cur].delta != 0) {
    st[cur].val += st[cur].delta;
    if(s != e) {
      st[L(cur)].delta = st[R(cur)].delta = st[cur].delta;
    }
    st[cur].delta = 0;
  }
}

void increase(int cur, int s, int e, int i, int j, int x) {
  push_down(cur, s, e);
  if(s > j || e < i) return;
  if(s >= i && e <= j) {
    st[cur].delta += x;
    push_down(cur, s, e);
    return;
  }
  int mid = Mid(s, e);
  increase(L(cur), s, mid, i, j, x);
  increase(R(cur), mid + 1, e, i, j, x);
  st[cur] = merge(st[L(cur)], st[R(cur)]);
}

Node query(int cur, int s, int e, int i, int j) {
  push_down(cur, s, e);
  if(s > j || e < i) return Node(0);
  if(s >= i && e <= j) return st[cur];
  int mid = Mid(s, e);
  return merge(query(L(cur), s, mid, i, j), query(R(cur), mid + 1, e, i, j));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].l >> arr[i].r >> arr[i].cost;
    arr[i].l--;
    arr[i].r--;
  }
  sort(arr, arr + n);
  reverse(arr, arr + n);

  int ans = INT_MAX;
  set<Seg> have;

  for(int i = n - 1; i >= 0; i--) {
    increase(0, 0, m - 2, arr[i].l, arr[i].r - 1, 1);

    while(have.size() > 0) {
      Seg cur = *have.begin();
      increase(0, 0, m - 2, cur.l, cur.r - 1, -1);
      if(query(0, 0, m - 2, 0, m - 2).val == 0) {
        increase(0, 0, m - 2, cur.l, cur.r - 1, 1);
        break;
      }
      have.erase(have.begin());
    }

    if(query(0, 0, m - 2, 0, m - 2).val > 0) {
      if(have.size() > 0) {
        ans = min(ans, have.begin()->cost - arr[i].cost);
      } else {
        ans = 0;
      }
    }

    have.insert(arr[i]);
  }

  cout << ans << endl;
  return 0;
}
