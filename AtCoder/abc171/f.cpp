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

const int Mod = 1e9 + 7;
const int N = 2e6 + 5;

int n, k;
string s;
ll fact[N], inv[N], invFact[N];

ll mpow(ll a, ll b) {
  ll r = 1;
  while(b > 0) {
    if(b & 1) r = (r * a) % Mod;
    a = (a * a) % Mod;
    b >>= 1;
  }
  return r;
}

ll C(int n, int k) {
  return fact[n] * invFact[k] % Mod * invFact[n - k] % Mod;
}

int main()
{
  ios::sync_with_stdio(false);

  fact[0] = fact[1] = 1;
  inv[0] = inv[1] = 1;
  invFact[0] = invFact[1] = 1;
  for(int i = 2; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % Mod;
    inv[i] = Mod - Mod / i * inv[Mod % i] % Mod;
    invFact[i] = (invFact[i - 1] * inv[i]) % Mod;
  }

  cin >> k >> s;
  n = sz(s);
  ll ans = 0;
  for(int i = n; i <= n + k; i++) {
    ans += C(i - 1, n - 1) * mpow(25, i - n) % Mod * mpow(26, n + k - i) % Mod;
    ans %= Mod;
  }

  cout << ans << endl;

  return 0;
}
