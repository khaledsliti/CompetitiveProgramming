/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1132/problem/F

  Idea:
    Let dp[i][j] be the answer after deleting the range [i, j].
    dp[i][j] = min( 1 + dp[i + 1][j], dp[i + 1][k - 1] + dp[k][j] ) for k in range [i + 1, j] such that s[i] == s[k]

  Compexity:
    Time: O(N^3)
    Memory: O(N^2)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
const int N = 505;

int n;
string s;
int dp[N][N];

int solve(int l, int r)
{
  if(l > r)
    return 0;
  int& res = dp[l][r];
  if(res != -1)
    return res;
  res = 1 + solve(l + 1, r);
  for(int k = l + 1 ; k <= r ; k++){
    if(s[l] == s[k]){
      res = min(res, solve(l + 1, k - 1) + solve(k, r));
    }
  }
  return res;
}

int main()
{
  cin >> n;
  cin >> s;
  memset(dp, -1, sizeof dp);
  cout << solve(0, n - 1) << endl;
  return 0;
}
