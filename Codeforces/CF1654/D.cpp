// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int Mod = 998244353;
const int N = 2e5 + 5;

int mpow(int a, int b) {
  if(!b) return 1;
  int r = mpow(a, b >> 1);
  r = (r * 1LL * r) % Mod;
  if(b & 1) r = (r * 1LL * a) % Mod;
  return r;
}

int inv(int a) {
  return mpow(a, Mod - 2);
}

struct Data {
  int a, b;
  int getVal() {
    return 1LL * a * inv(b) % Mod;
  }
};

int n;
vector<pair<int, Data>> g[N];
int co[N];
int smf[N];
int mx[N];

map<int, int> fact(int x) {
  map<int, int> res;
  for(int p = smf[x]; x > 1; x /= p, p = smf[x]) {
    res[p]++;
  }
  return res;
}

map<int, int> a, b;
void dfs(int u, int p) {
  for(auto e: g[u]) {
    int v = e.first;
    if(v != p) {
      // update maps
      map<int, int> a_diff, b_diff;
      auto c = fact(e.second.a), d = fact(e.second.b);
      for(auto i: d) {
        int cmn = min(a[i.first], i.second);
        a[i.first] -= cmn;
        a_diff[i.first] -= cmn;
        d[i.first] -= cmn;
      }
      for(auto i: c) {
        int cmn = min(b[i.first], i.second);
        b[i.second] -= cmn;
        b_diff[i.second] -= cmn;
        c[i.first] -= cmn;
      }
      for(const auto& i: c) {
        a[i.first] += i.second;
        a_diff[i.first] += i.second;
      }
      for(const auto& i: d) {
        b[i.first] += i.second;
        b_diff[i.first] += i.second;
        mx[i.first] = max(mx[i.first], b[i.first]);
      }
      co[v] = co[u] * 1LL * e.second.getVal() % Mod;
      dfs(v, u);
      // backtrack updates
      for(auto i: a_diff) {
        a[i.first] -= i.second;
      }
      for(auto i: b_diff) {
        b[i.first] -= i.second;
      }
    }
  }
}

void solve() {
  cin >> n;
  for(int i = 0; i <= n; i++) {
    g[i].clear();
    mx[i] = 0;
  }
  for(int i = 1; i < n; i++) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int gcd = __gcd(x, y);
    x /= gcd;
    y /= gcd;
    --a, --b;
    g[a].push_back({b, {y, x}});
    g[b].push_back({a, {x, y}});
  }
  
  a.clear(); b.clear();
  co[0] = 1;
  dfs(0, -1);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans = (ans + co[i]) % Mod;
  }
  for(int i = 0; i <= n; i++) {
    if(!mx[i]) continue;
    ans = (1LL * ans * mpow(i, mx[i])) % Mod;
  }
  cout << ans << endl;
}

void pre() {
  for(int i = 2; i < N; i++) {
    smf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    if(smf[i] == i) {
      for(int j = 2 * i; j < N; j += i) {
        smf[j] = min(smf[j], i);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  pre();

  int T; cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
