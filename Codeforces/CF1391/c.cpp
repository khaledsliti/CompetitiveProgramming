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

const ll Mod = 1e9 + 7;
const int N = 1e6 + 3;

int n;
ll fact[N], inv[N], invFact[N];

ll C(int n, int k) {
  return fact[n] * invFact[n - k] % Mod * invFact[k] % Mod;
}

int main()
{
  fact[0] = 1;
  fact[1] = 1;
  inv[1] = 1;
  invFact[0] = invFact[1] = 1;
  for(int i = 2; i < N; i++) {
    fact[i] = i * fact[i - 1] % Mod;
    inv[i] = Mod - Mod / i * inv[Mod % i] % Mod;
    invFact[i] = invFact[i - 1] * inv[i] % Mod;
  }

  cin >> n;
  ll ans = fact[n];
  for(int i = 0; i < n; i++) {
    ans = (ans - C(n - 1, i)) % Mod;
  }
  ans = (ans + Mod) % Mod;
  cout << ans << endl;
  return 0;
}
