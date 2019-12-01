#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5011;

int n;
char s[N];
int dp[N][N];

int main()
{
  scanf("%d%s", &n, s);
  for(int len = 2 ; len <= n ; len++){
    for(int i = 0 ; i + len <= n ; i++){
      int j = i + len - 1;
      dp[len][j] = 1e9;
      if(s[i] == s[j])
        dp[len][j] =  min(dp[i][j], dp[len - 2][j - 1]);
      dp[len][j] =  min(dp[len][j], 1 + dp[len][j - 1]);
      dp[len][j] =  min(dp[len][j], 1 + dp[len + 1][j]);
    }
  }
  printf("%d\n", dp[0][n - 1]);
  return 0;
}
