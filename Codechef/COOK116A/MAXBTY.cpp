// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const long long oo = 2e18;

struct node {
  long long max, min;
  long long lz;
  node() {};
  node(long long min, long long max) : min(min), max(max), lz(0) {}
};

int n, q;
int arr[N];
long long pre[N];
node st[N << 2];

node merge(node a, node b) {
  return node(min(a.min, b.min), max(a.max, b.max));
}

void push_down(int cur, int s, int e) {
  if(st[cur].lz) {
    st[cur].max += st[cur].lz;
    st[cur].min += st[cur].lz;
    if(s != e) {
      int l = 2 * cur + 1;
      int r = 2 * cur + 2;
      st[l].lz += st[cur].lz;
      st[r].lz += st[cur].lz;
    }
    st[cur].lz = 0;
  }
}

void build(int cur, int s, int e) {
  if(s == e) {
    st[cur] = node(pre[s], pre[s]);
    return;
  }
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  st[cur] = merge(st[l], st[r]);
}

void update(int cur, int s, int e, int i, int j, long long val) {
  push_down(cur, s, e);
  if(s > j || e < i)
    return;
  if(s >= i && e <= j) {
    st[cur].lz += val;
    push_down(cur, s, e);
    return;
  }
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  update(l, s, mid, i, j, val);
  update(r, mid + 1, e, i, j, val);
  st[cur] = merge(st[l], st[r]);
}

node query(int cur, int s, int e, int i, int j) {
  push_down(cur, s, e);
  if(s > j || e < i)
    return node(oo, -oo);
  if(s >= i && e <= j)
    return st[cur];
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  return merge(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
}


int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &q);
    pre[0] = 0;
    for(int i = 1 ; i <= n ; i++) {
      scanf("%d", arr + i);
      pre[i] = arr[i] + pre[i - 1];
    }
    build(0, 0, n);
    while(q--) {
      char t;
      scanf(" %c", &t);
      if(t == 'Q') {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", query(0, 0, n, y, n).max - query(0, 0, n, 0, x - 1).min);
      } else {
        int x, v;
        scanf("%d%d", &x, &v);
        update(0, 0, n, x, n, v - arr[x]);
        arr[x] = v;
      }
    }
  }
  return 0;
}
