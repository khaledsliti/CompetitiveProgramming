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

const int N = 2e5 + 5;
const long long INF = 1e18;

int n, q;
int arr[N];
long long st[N << 2], lz[N << 2];

void push_down(int cur, int s, int e) {
  if(lz[cur] != 0) {
    st[cur] += lz[cur];
    if(s != e) {
      int l = 2 * cur + 1;
      int r = 2 * cur + 2;
      lz[l] += lz[cur];
      lz[r] += lz[cur];
    }
    lz[cur] = 0;
  }
}

void update(int cur, int s, int e, int i, int j, long long val) {
  push_down(cur, s, e);
  if(s > j || e < i) return;
  if(s >= i && e <= j) {
    lz[cur] += val;
    push_down(cur, s, e);
    return;
  }
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) >> 1;
  update(l, s, mid, i, j, val);
  update(r, mid + 1, e, i, j, val);
  st[cur] = max(st[l], st[r]);
}

long long query(int cur, int s, int e, int i, int j) {
  push_down(cur, s, e);
  if(s > j || e < i) return -INF;
  if(s >= i && e <= j) return st[cur];
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) >> 1;
  return max(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
}

int main()
{
  scanf("%d%d", &n, &q);

  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    update(0, 0, n - 1, i, n - 1, arr[i]);
  }

  while(q--) {
    int t; scanf("%d", &t);
    if(t == 1) {
      int k, u;
      scanf("%d%d", &k, &u);
      --k;
      update(0, 0, n - 1, k, n - 1, u - arr[k]);
      arr[k] = u;
    } else {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      ll p;
      if(a > 0) {
        p = query(0, 0, n - 1, a - 1, a - 1);
        update(0, 0, n - 1, a, b, -p);
      }
      printf("%lld\n", max(0LL, query(0, 0, n - 1, a, b)));
      if(a > 0) {
        update(0, 0, n - 1, a, b, p);
      }
    }
  }
  return 0;
}
