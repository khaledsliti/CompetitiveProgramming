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

const int N = 501;
const int K = 3e5 + 5;
const int Mod = 998244353;

int n, m, k;
ll a[N][N];
ll last[N][N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j] %= Mod;
    }
  }
  ll ans = 0;
  for(int i = 0; i < k; i++) {
    char c;
    int r;
    ll t;
    cin >> c >> r >> t;
    --r;
    if(c == 'r') {
      for(int j = 0; j < m; j++) {
        ans += (t - last[r][j]) % Mod * a[r][j] % Mod;
        ans %= Mod;
        last[r][j] = t;
      }
    } else {  
      for(int i = 0; i < n; i++) {
        ans += (t - last[i][r]) % Mod * a[i][r] % Mod;
        ans %= Mod;
        last[i][r] = t;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
