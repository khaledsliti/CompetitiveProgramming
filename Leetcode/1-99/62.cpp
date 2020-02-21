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
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));
    for(int j = 0 ; j < n ; j++)
      dp[0][j] = 1;
    for(int i = 1 ; i < m ; i++)
      for(int j = 0 ; j < n ; j++)
        dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
    return dp[m - 1][n - 1];
  }
};

int main()
{
  
  return 0;
}
