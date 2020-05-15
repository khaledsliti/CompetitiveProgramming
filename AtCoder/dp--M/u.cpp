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

const ll Inf = 1e18;
const int N = 16;

int n;
int a[N][N];
long long cost[1 << N];
long long dp[1 << N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> a[i][j];
  for(int msk = 0; msk < (1 << n); msk++) {
    cost[msk] = 0;
    for(int i = 0; i < n; i++)
      if(msk & (1 << i))
        for(int j = i + 1; j < n; j++)
          if(msk & (1 << j))
            cost[msk] += a[i][j];
  }
  dp[0] = 0;
  for(int msk = 1; msk < (1 << n); msk++) {
    dp[msk] = -Inf;
    for(int sub = msk; sub > 0; sub = (msk & (sub - 1))) {
      dp[msk] = max(dp[msk], cost[sub] + dp[msk ^ sub]);
    }
  }
  cout << dp[(1 << n) - 1] << endl;
  return 0;
}
