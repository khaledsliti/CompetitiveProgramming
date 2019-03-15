#include <bits/stdc++.h>
using namespace std;

class SRMIntermissionPhase
{
  const int mod = 1e9 + 7;
public:
  int countWays(vector<int> points, vector<string> description){
    int n = (int)description.size();
    assert(points.size() == 3 && n >= 1);
    int total = points[0] + points[1] + points[2];
    int cnt[(1 << 3)][4][total + 1];
    int pref_cnt[4][total + 1];
    for(int i = 0 ; i < 4 ; i++)
      for(int j = 0 ; j <= total ; j++)
        cnt[0][i][j] = 0;
    // for each mask, calculate the number of ways to form j points using problems of this mask
    for(int mask = 1 ; mask < (1 << 3) ; mask++){
      for(int j = 0 ; j <= total ; j++){
        cnt[mask][0][j] = j == 0;
        pref_cnt[0][j] = 1;
      }
      for(int i = 1 ; i <= 3 ; i++){
        int cur_p = points[i - 1];
        for(int j = 0 ; j <= total ; j++){
          int l = j, r = j;
          if(mask & (1 << (i - 1))){
            l = max(0, j - cur_p);
            r = j - 1;
          }
          if(l <= r){
            cnt[mask][i][j] = pref_cnt[i - 1][r] - (l > 0 ? pref_cnt[i - 1][l - 1] : 0);
          }else{
            cnt[mask][i][j] = 0;
          }
          cnt[mask][i][j] %= mod;
          pref_cnt[i][j] = cnt[mask][i][j];
          if(j > 0)
            pref_cnt[i][j] = (pref_cnt[i][j] + pref_cnt[i][j - 1]) % mod;
        }
      }
    }
    int dp[n + 1][total + 1];
    for(int j = 0 ; j <= total ; j++)
      dp[0][j] = j == 0;
    for(int i = 1 ; i <= n ; i++){
      int mask = 0;
      for(int k = 0 ; k < 3 ; k++)
        if(description[i - 1][k] == 'Y')
          mask |= (1 << k);
      for(int j = 1 ; j <= total ; j++){
        dp[i][j] = 0;
        if(j > 0){
          dp[i][j] = dp[i][j - 1];
          dp[i][j] = (dp[i][j] + 1LL * cnt[mask][3][j] * dp[i - 1][j - 1]) % mod;
        }
      }
    }
    return dp[n][total];
  }
};



