// We only fail when we stop trying
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

struct Node {
  ll sum, first, step;
};


int n;
int arr[N];
Node st[N << 2];


void build(int cur, int s, int e) {
  if(s == e) {
    st[cur] = { arr[s], 0, 0 };
    return;
  }
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  build(2 * cur + 1, s, mid);
  build(2 * cur + 2, mid + 1, e);
  st[cur] = { st[l].sum + st[r].sum, 0, 0 };
}

void push_down(int cur, int s, int e) {
  if(st[cur].first != 0) {
    ll len = e - s + 1;
    st[cur].sum += st[cur].first * len + st[cur].step * (((len - 1) * len) / 2);
    if(s != e) {
      int l = 2 * cur + 1;
      int r = 2 * cur + 2;
      int mid = (s + e) / 2;
      st[l].first += st[cur].first;
      st[l].step += st[cur].step;
      st[r].first += st[cur].first + (mid + 1 - s) * st[cur].step;
      st[r].step += st[cur].step;
    }
    st[cur].first = 0;
    st[cur].step = 0;
  }
}

void update(int cur, int s, int e, int i, int j, int left) {
  push_down(cur, s, e);
  if(s > j || e < i) return;
  if(s >= i && e <= j) {
    st[cur].first += s - left + 1;
    st[cur].step += 1;
    push_down(cur, s, e);
    return;
  }
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  update(l, s, mid, i, j, left);
  update(r, mid + 1, e, i, j, left);
  st[cur] = { st[l].sum + st[r].sum, 0LL, 0LL };
}

ll query(int cur, int s, int e, int i, int j) {
  push_down(cur, s, e);
  if(s > j || e < i) return 0LL;
  if(s >= i && e <= j) return st[cur].sum;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  return query(l, s, mid, i, j) + query(r, mid + 1, e, i, j);
}

int main()
{
  int q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(0, 0, n - 1);
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int a, b;
      cin >> a >> b;
      update(0, 0, n - 1, a, --b, --a);
    } else {
      int a, b;
      cin >> a >> b;
      cout << query(0, 0, n - 1, --a, --b) << endl;
    }
  }
  return 0;
}
