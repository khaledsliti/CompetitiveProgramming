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
int n;

ll mpow(ll a, ll b) {
  ll r = 1;
  while(b > 0) {
    if(b & 1) r = (r * a) % Mod;
    b >>= 1, a = (a * a) % Mod;
  }
  return r;
}

int main()
{
  cin >> n;
  int sum = n * (n + 1) / 2;
  if(sum & 1) return cout << 0 << endl, 0;
  sum >>=  1;
  vector<int> dp(sum + 1, 0);
  dp[0] = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = sum; j >= i; j--) {
      dp[j] = (dp[j] + dp[j - i]) % Mod;
    }
  }
  cout << dp[sum] * mpow(2, Mod - 2) % Mod << endl;
  return 0;
}
