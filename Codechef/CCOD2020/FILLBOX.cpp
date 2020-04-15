// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int Mod = 1e9 + 7;

int n, k, p, q;
int dp[N][2];

void solve() {
  scanf("%d%d%d%d", &n, &k, &p, &q);
  dp[0][0] = p != q;
  dp[0][1] = p == q;
  for(int i = 1 ; i < n - 1; i++) {
    dp[i][1] = dp[i - 1][0];
    dp[i][0] = (1LL * dp[i - 1][1] * (k - 1) % Mod + 1LL * dp[i - 1][0] * (k - 2) % Mod) % Mod;
  }
  printf("%d\n", dp[n - 2][0]);
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    solve();
  return 0;
}
