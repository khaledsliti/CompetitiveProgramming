#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int oo = 1e9;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    for(int i = 0 ; i < n ; i++)
      for(int j = 0 ; j < m ; j++){
        dp[i][j] = grid[i][j] + (i > 0 || j > 0 ? min(i > 0 ? dp[i - 1][j] : oo, j > 0 ? dp[i][j - 1] : oo) : 0);
      }
    return dp[n - 1][m - 1];
  }
};

int main()
{
  vector<vector<int>> grid = 
  {
    {1,2,5},
    {3,2,1}
  };
  cout << Solution().minPathSum(grid) << endl;
  return 0;
}
