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
const int Mod = 998244353;


int n, q;
ll st[N << 2], lz[N << 2];
ll w[N];

ll mpow(ll a, ll b) {
  ll r = 1;
  while(b > 0) {
    if(b & 1) r = r * a % Mod;
    a = a * a % Mod;
    b >>= 1;
  }
  return r;
}

ll merge(ll a, ll b ,int len_left) {
  return (a + b * mpow(10, len_left) % Mod) % Mod;
}

void build(int cur, int s, int e) {
  if(s == e) {
    st[cur] = 1;
    return;
  }
  int l = 2 * cur + 1, r = 2 * cur + 2;
  int mid = (s + e) / 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  st[cur] = merge(st[l], st[r], mid - s + 1);
}

void push_down(int cur, int s, int e) {
  if(lz[cur]) {
    st[cur] = w[e - s + 1] * lz[cur] % Mod;
    if(s != e) {
      int l = 2 * cur + 1, r = 2 * cur + 2;
      lz[l] = lz[cur];
      lz[r] = lz[cur];
    }
    lz[cur] = 0;
  }
}

void update(int cur, int s, int e, int i, int j, int d) {
  push_down(cur, s, e);
  if(s > j || e < i) return;
  if(s >= i && e <= j) {
    lz[cur] = d;
    push_down(cur, s, e);
    return;
  }
  int l = 2 * cur + 1, r = 2 * cur + 2;
  int mid = (s + e) / 2;
  update(l, s, mid, i, j, d);
  update(r, mid + 1, e, i, j, d);
  st[cur] = merge(st[l], st[r], mid - s + 1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  w[1] = 1;
  for(int i = 2; i < N; i++) {
    w[i] = (w[i - 1] * 10 + 1) % Mod;
  }
  
  cin >> n >> q;
  build(0, 0, n - 1);

  while(q--) {
    int l, r, d;
    cin >> l >> r >> d;
    --l, --r;
    l = n - l - 1;
    r = n - r - 1;
    swap(l, r);
    update(0, 0, n - 1, l, r, d);
    cout << st[0] << endl;
  }

  return 0;
}
