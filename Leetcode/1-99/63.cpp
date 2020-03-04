#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size(); if(!n) return 0;
    int m = obstacleGrid[0].size(); if(!m) return 0;
    if(obstacleGrid[0][0] || obstacleGrid[n - 1][m - 1]) return 0;
    for(int i = n - 1 ; i >= 0 ; i--)
      for(int j = m - 1 ; j >= 0 ; j--)
        if(i == n - 1 && j == m - 1)
          continue;
        else
          obstacleGrid[i][j] = obstacleGrid[i][j] || 
            ((i + 1 < n ? obstacleGrid[i + 1][j] : 1) && (j + 1 < m ? obstacleGrid[i][j + 1] : 1));
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = 0 ; i < n ; i++) {
      for(int j = 0 ; j < m ; j++) {
        if(obstacleGrid[i][j]) dp[i][j] = 0;
        else if(!i && !j) dp[i][j] = 1;
        else dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
      }
    }
    return dp[n - 1][m - 1];
  }
};

int main()
{
  
  return 0;
}
