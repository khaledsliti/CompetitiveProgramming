// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int Mod = 1e9 + 7;

long long f(int n) {
  return (1LL * n * (n - 1) % Mod + n) % Mod;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    long long ans;
    if(n == 0) {
      ans = f(k - 1) + k - 1;
    } else if(k & 1) {
      ans = f(n + (k - 1) / 2);
      if(k > 1) ans += (k - 1) / 2;
    } else {
      ans = f(n + (k - 1) / 2) + n + (k - 1) / 2 + n;
    }
    ans %= Mod;
    cout << ans << endl;
  }
  return 0;
}
