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
const int N = 1e6 + 1;

ll fact[N], inv[N], invFact[N];

void init() {
  fact[0] = fact[1] = 1;
  inv[1] = 1;
  invFact[0] = invFact[1] = 1;
  for(int i = 2; i < N; i++) {
    fact[i] = fact[i - 1] * i % Mod;
    inv[i] = Mod - Mod / i * inv[Mod % i] % Mod;
    invFact[i] = invFact[i - 1] * inv[i] % Mod;
  }
}

int main()
{
  init();
  int T;
  cin >> T;
  while(T--) {
    int a, b;
    cin >> a >> b;
    ll ans = fact[a] * invFact[b] % Mod * invFact[a - b] % Mod;
    cout << ans << endl;
  }
  return 0;
}
