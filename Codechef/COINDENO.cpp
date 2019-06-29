/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://www.codechef.com/problems/COINDENO

  Idea:
    http://codeforces.com/blog/entry/60701?#comment-446462

  Compexity:
    Time: O(MAX * N + Q)
    Memory: O(MAX + N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
const int N = 105;
const int mod = 1e9 + 7;
const long long oo = 1e18;

int n, c, q;
long long cost[N], val[N];
long long dp[MAX];

int main()
{
  scanf("%d%d%d", &n, &c, &q);
  for(int i = 0 ; i < n ; i++){
    int a, w;
    scanf("%d%d", &a, &w);
    cost[i] = w;
    val[i] = a;
  }
  dp[0] = 0;
  for(int i = 1 ; i < MAX ; i++){
    dp[i] = oo;
    for(int j = 0 ; j < n ; j++)
      if(i - val[j] >= 0)
        dp[i] = min(dp[i], dp[i - val[j]] + cost[j]);
  }
  while(q--){
    long long qi;
    scanf("%lld", &qi);
    if(qi < MAX){
      printf("%d\n", dp[qi] >= oo ? -1 : dp[qi] % mod);
    }else{
      __int128 big_max = (__int128)oo * (__int128)oo;
      __int128 ans = big_max;
      for(int i = 0 ; i < n ; i++){
        long long t = (qi - MAX + val[i]) / val[i];
        int At = qi - t * val[i];
        assert(At >= 0 && At < MAX);
        if(dp[At] >= oo)
          continue;
        ans = min(ans, dp[At] + (__int128)cost[i] * (__int128)t);
      }
      printf("%d\n", ans >= big_max ? -1 : (int)(ans % mod));
    }
  }
  return 0;
}
