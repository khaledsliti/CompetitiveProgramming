/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://community.topcoder.com/stat?c=problem_statement&pm=11765&rd=14725

  Idea:
    The main idea is that we are going to process of the rows of the grid one by one from top to bottom.
    In each row, we try all possible configurations and check for each configuration if the previous configuration (the config of the previous row)
    still valid (that means all cells filled with 1 in the previous row should have even number of colored neighbors)
    For each row we must have two parameters so that we can calculate the result. The first one is the positions of colored cells in the previous row.
    The second is the position of colored cell that have odd number of colored neighbors.
    To avoid using a lot of memory we will use an integer to represent these two informations. It is the second parameters (prev_rep) of solve funtion.
    It contains all necessary informations of the previous row.
    We will assign a value for each column as follow
      - 0 if the current column contains an uncolored cell.
      - 1 if the current column contains a colored cell and has even number of colored neighbors so far.
      - 2 if the current column contains a colored cell and has odd number of colored neighbors so far.
    So, 0 <= prev_rep < 3^M.
    To decrease the time complexity of the function solve, we can precalculate the representation of all possible case between two rows
    using a dynamic programming solution.

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
