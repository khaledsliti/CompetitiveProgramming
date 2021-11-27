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

const int Mod = 1e9 + 7;

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long ans = 0;
  for(int i = 0; i < m; i++) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    ans |= x;
  }
  for(int i = 0; i < n - 1; i++) {
    ans *= 2;
    ans %= Mod;
  }
  printf("%lld\n", ans % Mod);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
