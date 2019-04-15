class Solution{
public:
  int maxProfit(vector<int>& prices){
    nt n = (int)prices.size();
    int dp[n + 2][2];
    dp[n][0] = dp[n][1] = 0;
    dp[n + 1][0] = dp[n + 1][1] = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
      dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] - prices[i]);
      dp[i][0] = max(dp[i + 1][0], dp[i + 2][1] + prices[i]);
    }
    return dp[0][1];
  }
};
