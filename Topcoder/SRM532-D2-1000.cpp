/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://community.topcoder.com/stat?c=problem_statement&pm=11765&rd=14725

  Idea:

  Compexity:
    Time: O(4^M * M + 6^M * N)
    Memory: O(4^M + N * 3^M)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

const int R = 101, C = 8;
const int mod = 1e9 + 7;
int dp[R][6566];
int rep[1 << C][1 << C];

class DengklekPaintingSquares{
  int n, m;
  void init(){
    memset(dp, -1, sizeof dp);
  }
  void pre()
  {
    for(int mask = 0 ; mask < (1 << m) ; mask++){
      int par_mask = 0;
      for(int i = 0 ; i < m ; i++){
        if(mask & (1 << i)){
          if(i > 0)
            par_mask ^= (1 << (i - 1));
          if(i + 1 < m)
            par_mask ^= (1 << (i + 1));
        }
      }
      par_mask &= mask;
      for(int prev_mask = 0 ; prev_mask < (1 << m) ; prev_mask++){
        int new_par = par_mask ^ (mask & prev_mask);
        rep[mask][prev_mask] = 0;
        for(int i = m - 1 ; i >= 0 ; i--){
          int c = 0;
          if(mask & (1 << i)){
            c++;
            if(new_par & (1 << i))
              c++;
          }
          rep[mask][prev_mask] = rep[mask][prev_mask] * 3 + c;
        }
      }
    }
  }
  int solve(int cur, int prev_rep){
    int prev_mask = 0;
    int prev_par = 0;
    int temp = prev_rep;
    for(int i = 0 ; i < m ; i++){
      int c = temp % 3;
      if(c >= 1)
        prev_mask |= (1 << i);
      if(c >= 2)
        prev_par |= (1 << i);
      temp /= 3;
    }
    if(cur >= n)
      return prev_par == 0;
    int& res = dp[cur][prev_rep];
    if(res != -1)
      return res;
    res = 0;
    for(int mask = 0 ; mask < (1 << m) ; ++mask){
      if((mask & prev_mask) ^ prev_par)
        continue;
      int cur_rep = rep[mask][prev_mask];
      res = (res + solve(cur + 1, cur_rep)) % mod;
    }
    return res;
  }
public:
  int numSolutions(int n_, int m_){
    n = n_;
    m = m_;
    init();
    pre();
    return solve(0, 0);
  }
};
