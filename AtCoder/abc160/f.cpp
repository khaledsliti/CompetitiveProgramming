// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;
const int Mod = 1e9 + 7;

int n;
vector<int> g[N];
int sub[N];
long long fact[N], invFact[N], inv[N];
long long psub[N], ans[N];

long long mypow(int a, int b) {
  if(!b) return 1;
  long long r = mypow(a, b >> 1);
  r = r * r % Mod;
  if(b & 1) r = (r * a) % Mod;
  return r;
}

long long inver(int a) {
  return mypow(a, Mod - 2);
}

long long C(int n, int k) {
  return fact[n] * invFact[k] % Mod * invFact[n - k] % Mod;
}

void dfs(int u, int p) {
  sub[u] = 1;
  for(int v : g[u])
    if(v != p) {
      dfs(v, u);
      sub[u] += sub[v];
    }
  psub[u] = 1;
  int cur = sub[u] - 1;
  for(int v : g[u]) {
    if(v == p) continue;
    psub[u] *= C(cur, sub[v]) * psub[v] % Mod;
    psub[u] %= Mod;
    cur -= sub[v];
  }
}

void dfs2(int u, int p) {
  if(p == -1) ans[u] = psub[u];
  else ans[u] = ans[p] * inver(C(n - 1, sub[u])) % Mod * C(n - 1, sub[u] - 1) % Mod;
  for(int v : g[u])
    if(v != p) {
      dfs2(v, u);
    }
}

int main()
{
  inv[1] = 1;
  for(int i = 2 ; i < N ; i++)
    inv[i] = Mod - Mod / i * inv[Mod % i] % Mod;
  fact[0] = invFact[0] = 1;
  for(int i = 1 ; i < N ; i++) {
    fact[i] = (fact[i - 1] * i) % Mod;
    invFact[i] = (invFact[i - 1] * inv[i]) % Mod;
  }
  cin >> n;
  for(int i = 1 ; i < n ; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0, -1);
  // for(int i = 0 ; i < n ; i++)
  //   cout << psub[i] << " ";
  // cout << endl;
  dfs2(0, -1);
  for(int i = 0 ; i < n ; i++)
    cout << ans[i] << endl;
  return 0;
}
