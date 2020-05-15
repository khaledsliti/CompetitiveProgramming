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

const int N = 2e5 + 5;
const int Mod = 998244353;

ll n, m, k;
ll dp[N];

int main()
{
  cin >> n >> m >> k;
  k++;
  dp[0] = 1;
  ll prv = 1;
  for(int i = 1 ; i <= n ; i++) {
    dp[i] = (m - 1) * prv % Mod;
    prv += dp[i], prv %= Mod;
    if(i - k >= 0)
      prv = (prv - dp[i - k]) % Mod, prv = (prv + Mod) % Mod;
  }
  ll ans = 0;
  for(int i = n ; i > n - k ; i--)
    ans = (ans + m * dp[i - 1]) % Mod;
  cout << ans << endl;
  return 0;
}
