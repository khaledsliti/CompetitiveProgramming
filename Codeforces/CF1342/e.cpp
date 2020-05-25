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

template<typename T, int D>
struct Vec : public vector<Vec<T, D - 1>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template<typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<T, D - 1>>(n, Vec<T, D - 1>(args...)) { }
};
template<typename T>
struct Vec<T, 1> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) { }
};

const int N = 2e5 + 5;
const int Mod = 998244353;

Vec<ll, 1> fact(N), inv(N), invFact(N);

ll binPow(ll a, ll b) {
  if(!b) return 1;
  ll r = binPow(a, b >> 1);
  r = r * r % Mod;
  if(b & 1) r = r * a % Mod;
  return r;
}

ll P(int n, int r) {
  return fact[n] * invFact[n - r] % Mod;
}

ll C(int n, int r) {
  return P(n, r) * invFact[r] % Mod;
}

int main()
{
  for(int i = 0; i < 2; i++)
    fact[i] = inv[i] = invFact[i] = 1;
  for(int i = 2; i < N; i++) {
    fact[i] = i * fact[i - 1] % Mod;
    inv[i] = Mod - Mod / i * inv[Mod % i] % Mod;
    invFact[i] = inv[i] * invFact[i - 1] % Mod;
  }
  int n, k;
  cin >> n >> k;
  if(k >= n)
    return cout << 0 << endl, 0;
  if(k == 0)
    return cout << fact[n] << endl, 0;
  ll ans = 0;
  for(int i = 0; i <= n - k; i++) {
    ll cur = C(n - k, i) * binPow(n - k - i, n) % Mod;
    if(i & 1) cur = -cur;
    ans += cur;
    ans = (ans % Mod + Mod) % Mod;
  }
  ans = ans * 2 % Mod * C(n, k) % Mod;
  cout << ans << endl;
  return 0;
}
