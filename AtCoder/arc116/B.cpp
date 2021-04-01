// RedStone
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

const int N = 2e5 + 5;
const int Mod = 998244353;

int n;
ll a[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  ll ans = 0;
  ll cur = 0;
  for(int i = n - 1; i >= 0; i--) {
    ans = (ans + a[i] * cur);
    ans = (ans + a[i] * a[i]) % Mod;
    cur = (cur * 2 + a[i]) % Mod;
  }

  cout << ans << endl;
  return 0;
}
