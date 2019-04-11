class Solution {
public:
  int maxCoins(vector<int>& nums){
    vector<int> A;
    A.push_back(1);
    for(auto x : nums)
      A.push_back(x);
    A.push_back(1);
    int n = (int)A.size();
    int dp[n][n] = {};
    for(int len = 2 ; len <= n ; len++){
      for(int i = 0 ; i < n ; i++){
        int j = i + len - 1;
        for(int k = i + 1 ; k < j ; k++){
          dp[i][j] = max(dp[i][j], A[i] * A[j] * A[k] + dp[i][k] + dp[k][j]);
        }
      }
    }
    return dp[0][n-1];
  }
};