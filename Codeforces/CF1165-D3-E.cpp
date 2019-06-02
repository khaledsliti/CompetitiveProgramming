#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int mod = 998244353;
const int N = 2e5 + 5;

int n;
long long a[N], b[N];

int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i] *= 1LL * (n - i) * (i + 1);
  }
  long long ans = 0;
  for(int i = 0 ; i < n ; i++){
    cin >> b[i];
  }
  sort(a, a + n);
  reverse(a, a + n);
  sort(b, b + n);
  for(int i = 0 ; i <n ; i++){
    ans += b[i] * (a[i] % mod) % mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
