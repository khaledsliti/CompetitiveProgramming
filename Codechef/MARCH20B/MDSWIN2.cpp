// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int Mod = 998244353;
const int N = 1e5 + 5;
const int L = 17;
const int BlockSize = 317;

struct query {
  int l, r, b, idx;
  query(){}
  query(int l, int r, int idx) : l(l), r(r), idx(idx), b(l / BlockSize) {}
  bool operator<(const query& rhs) const {
    if(b != rhs.b) return b < rhs.b;
    return r > rhs.r;
  }
};

int n, q;
int a[N];
query qr[N];
int inv[N], invFact[N], fact[N];
int ans[N];
int fr[N], occ[N];
int pos[N];
vector<int> values;

int C(int n, int k) {
  return (((1LL * fact[n] * invFact[k]) % Mod) * invFact[n - k]) % Mod;
}

void add(int val) {
  --occ[fr[val]];
  ++fr[val];
  ++occ[fr[val]];
  if(pos[fr[val]] == -1) {
    pos[fr[val]] = sz(values);
    values.pb(fr[val]);
  }
}

void del(int val) {
  --occ[fr[val]];
  --fr[val];
  ++occ[fr[val]];
  if(pos[fr[val]] == -1) {
    pos[fr[val]] = sz(values);
    values.pb(fr[val]);
  }
}

int getSolution() {
  vector<int> vv;
  for(const int& x : values)
    if(occ[x]) vv.pb(x);
    else pos[x] = -1;
  values = vv;
  int sum = 0;
  for(const int& cur : values)
    if(occ[cur] & 1)
      sum ^= cur;
  if(!sum)
    return 0;
  int ans = 0;
  for(const int& s : values) {
    int nxt = s ^ sum;
    if(nxt > s) continue;
    ans = (ans + 1LL * occ[s] * C(s, nxt) % Mod) % Mod;
  }
  return ans;
}

void format() {
  map<int, int> x;
  for(int i = 0 ; i < n ; i++)
    x[a[i]];
  int cur = 1;
  for(auto& y : x)
    y.second = cur++;
  for(int i = 0 ; i < n ; i++)
    a[i] = x[a[i]];
}

void solve() {
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", a + i);
  }
  format();
  for(int i = 0 ; i < n ; i++) {
    fr[a[i]] = 0;
  }
  scanf("%d", &q);
  for(int i = 0 ; i < q ; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    qr[i] = query(--l, r, i);
  }
  sort(qr, qr + q);
  int l = 0, r = 0;
  for(int i = 0 ; i <= n ; i++)
    occ[i] = 0, pos[i] = -1;
  values.clear();
  for(int i = 0 ; i < q ; i++) {
    int cur_l = qr[i].l;
    int cur_r = qr[i].r;
    while(l > cur_l) add(a[--l]);
    while(l < cur_l) del(a[l++]);
    while(r < cur_r) add(a[r++]);
    while(r > cur_r) del(a[--r]);
    ans[qr[i].idx] = getSolution();
  }
  for(int i = 0 ; i < q ; i++)
    printf("%d\n", ans[i]);
}

void pre() {
  fact[0] = fact[1] = 1;
  inv[0] = inv[1] = 1;
  invFact[0] = invFact[1] = 1;
  for(int i = 2 ; i < N ; i++) {
    fact[i] = (1LL * i * fact[i - 1]) % Mod;
    inv[i] = (1LL * inv[Mod % i] * (Mod - 1LL * Mod / i)) % Mod;
    invFact[i] = (1LL * invFact[i - 1] * inv[i]) % Mod;
  }
}

int main()
{
  pre();
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
