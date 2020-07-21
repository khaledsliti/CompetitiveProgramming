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

const int Mod = 1e9 + 7;
const int N = 1e6 + 5;

int n;
ll fact[N];
ll inv[N], factInv[N];

ll C(ll n, ll k) {
  return fact[n] * factInv[k] % Mod * factInv[n - k] % Mod;
}

int main()
{
  fact[0] = 1;
  for(int i = 1; i < N; i++)
    fact[i] = (fact[i - 1] * i) % Mod;
  inv[1] = 1;
  factInv[0] = factInv[1] = 1;
  for(int i = 2; i < N; i++) {
    inv[i] = Mod - Mod / i * inv[Mod % i] % Mod;
    factInv[i] = inv[i] * factInv[i - 1] % Mod;
  }
  cin >> n;
  ll ans = 0;
  for(int i = n; i >= 0; i--) {
    ll cur = C(n, i) * fact[n - i] % Mod;
    if(i & 1) ans -= cur;
    else ans += cur;
    ans %= Mod;
  }
  ans = (ans + Mod) % Mod;
  cout << ans << endl;
  return 0;
}
