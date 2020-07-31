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

int n, k, z;
int a[N];
ll dp[N][10][2];

ll solve(int cur, int rem, int left, int last) {
  if(rem < 0)
    return 0;
  ll& ret = dp[cur][left][last];
  if(ret != -1) return ret;
  ret = a[cur];
  ll add = 0;
  if(cur < n - 1)
    add = max(add, solve(cur + 1, rem - 1, left, 0));
  if(!last && left > 0 && cur > 0)
    add = max(add, solve(cur - 1, rem - 1, left - 1, 1));
  ret += add;
  return ret;
}

void solve() {
  scanf("%d%d%d", &n, &k, &z);
  for(int i = 0; i < n; i++)
    scanf("%d", a + i);
  for(int i = 0; i < n; i++)
    for(int j = 0; j <= z; j++)
      for(int k = 0; k < 2; k++)
        dp[i][j][k] = -1;
  printf("%I64d\n", solve(0, k, z, 0));
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
