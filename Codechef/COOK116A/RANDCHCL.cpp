// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 500001;
const int Mod = 998244353;

int n, mx;
int arr[N], d[N];
long long inv[N];
long long e[N];

void solve() {
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", &arr[i]);
    mx = max(mx, arr[i] + 1);
  }
  for(int i = 0 ; i < mx ; i++)
    d[i] = 0;
  for(int i = 0 ; i < n ; i++)
    d[arr[i]]++;
  for(int i = 1 ; i < mx ; i++) {
    for(int j = 2 * i ; j < mx ; j += i)
      d[i] += d[j];
  }
  long long ans = 0;
  for(int i = mx - 1 ; i > 0 ; i--) {
    e[i] = 1LL * d[i] * d[i];
    for(int j = 2 * i ; j < mx ; j += i)
      e[i] -= e[j];
    ans = (ans + e[i] * i % Mod) % Mod;
  }
  ans = ans * (n + 1) % Mod * (2 * n + 1) % Mod * inv[6] % Mod * inv[n] % Mod * inv[n] % Mod;
  cout << ans << endl;
}

int main()
{
  inv[1] = 1;
  for(int i = 2 ; i < N ; i++)
    inv[i] = Mod - Mod / i * inv[Mod % i] % Mod;
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
