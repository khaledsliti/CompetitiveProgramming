// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 502, R = 200010;
long long const Inf = 1e18 + 5;

long long dp[N][R];
int ans[N];

int main()
{
  dp[0][0] = 1;
  for(int i = 1 ; i < N ; i++) {
    for(int j = 0 ; j <= i * (i - 1) / 2 ; j++) {
      long long sum = 0;
      for(int k = j ; k >= max(0, j - i + 1) && sum > -1 ; k--) {
        if(dp[i - 1][k] == -1) sum = -1;
        else {
          sum += dp[i - 1][k];
          if(sum > Inf)
            sum = -1;
        }
      }
      dp[i][j] = sum;
    }
  }
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, r;
    long long k;
    scanf("%d%d%lld", &n, &r, &k);
    if(dp[n][r] > -1 && dp[n][r] < k) {
      printf("-1\n");
      continue;
    }
    for(int i = n ; i > 0 ; i--) {
      for(int d = 0 ; d < i ; d++) {
        if(r - d >= 0 && (dp[i - 1][r - d] == -1 || dp[i - 1][r - d] >= k)) {
          ans[n - i] = d;
          r -= d;
          break;
        } else if(r - d >= 0) {
          k -= dp[i - 1][r - d];
        }
      }
    }
    vector<int> sol = {n - 1};
    for(int i = n - 2 ; i >= 0 ; i--) {
      sol.insert(begin(sol) + ans[i], i);
    }
    for(int i = 0 ; i < sz(sol) ; i++) {
      ans[sol[i]] = i + 1;
    }
    for(int i = 0 ; i < n ; i++)
      printf("%d%c", ans[i], " \n"[i == n - 1]);
  }
  return 0;
}
