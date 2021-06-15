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

const int N = 105;

int n;
int t[N], b[N];
int dp[N][N];

int main()
{
  while(scanf("%d", &n) && n) {
    for(int i = 0; i < n; i++) {
      scanf("%d%d", t + i, b + i);
    }
    for(int j = 0; j <= n; j++)
      dp[n][j] = 0;
    for(int i = n - 1; i >= 0; i--) {
      for(int j = 0; j <= n; j++) {
        int nxt_j = j + b[i] > n ? n : j + b[i];
        int nxt_jm1 = j - 1 + b[i] > n ? n : j - 1 + b[i];
        dp[i][j] = dp[i + 1][nxt_j] + t[i];
        if(j > 0 && dp[i][j] > dp[i + 1][nxt_jm1] + (t[i] >> 1))
          dp[i][j] = dp[i + 1][nxt_jm1] + (t[i] >> 1);
      }
    }
    printf("%d\n", dp[0][0]);
  }
  return 0;
}
