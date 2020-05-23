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

const ll Mod = 1e10;

__int128_t mpow(__int128_t a, __int128_t b) {
  if(!b) return 1LL;
  __int128_t r = mpow(a, b >> 1);
  r = (r * r) % Mod;
  if(b & 1) r = (r * a) % Mod;
  return r;
}

int main()
{
  int n;
  cin >> n;
  ll ans = 0;
  for(int i = 1; i <= n; i++)
    ans = (ans + mpow(i, i)) % Mod;
  cout << ans << endl;
  return 0;
}
