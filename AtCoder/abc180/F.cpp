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

const int N = 305, V = 1e5;
const int Mod = 1e9 + 7;

int n, m, L;
ll dp[N][N][2];
ll fact[V], inv[V], factInv[V];

void init() {
  fact[0] = fact[1] = 1;
  inv[1] = 1;
  factInv[0] = factInv[1] = 1;
  for(int i = 2; i < V; i++) {
    fact[i] = fact[i - 1] * i % Mod;
    inv[i] = Mod - Mod / i * inv[Mod % i] % Mod;
    factInv[i] = factInv[i - 1] * inv[i] % Mod;
  }
}

ll C(int n, int k) {
  if(k > n) return 0;
  return fact[n] * factInv[n - k] % Mod * factInv[k] % Mod;
}

ll chain(int nodes) {
  if(nodes <= 1) return 1;
  return fact[nodes] * inv[2] % Mod;
}

ll cycle(int nodes) {
  if(nodes == 1) return 0;
  if(nodes == 2) return 1;
  return fact[nodes - 1] * inv[2] % Mod;
}

ll solve(int nodes, int edges, int done) {
  if(nodes <= 0) {
    return edges == 0 && done == 1;
  }
  ll& r = dp[nodes][edges][done];
  if(r != -1) return r;
  r = 0;
  for(int cur = 1; cur <= min(L, nodes); cur++) {
    // chain
    if(cur - 1 <= edges) {
      r += C(nodes - 1, cur - 1) * chain(cur) % Mod
        * solve(nodes - cur, edges - cur + 1, done || cur == L) % Mod;
      r %= Mod;
    }
    // cycle
    if(cur <= edges) {
      r += C(nodes - 1, cur - 1) * cycle(cur) % Mod
        * solve(nodes - cur, edges - cur, done || cur == L) % Mod;
      r %= Mod;
    }
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  init();

  cin >> n >> m >> L;
  memset(dp, -1, sizeof dp);

  cout << solve(n, m, 0) << endl;
  return 0;
}
