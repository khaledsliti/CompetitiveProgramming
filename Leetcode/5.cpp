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
  string longestPalindrome(string s) {
    int n = s.size();
    if(n <= 1)
      return s;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0 ; i < n ; i++){
      dp[i][i] = 1;
      if(i > 0 && s[i - 1] == s[i])
        dp[i - 1][i] = 1;
    }
    for(int len = 3 ; len <= n ; len++)
      for(int i = 0 ; i + len <= n ; i++){
        int j = i + len - 1;
        dp[i][j] = 0;
        if(s[i] == s[j] && dp[i + 1][j - 1])
          dp[i][j] = dp[i + 1][j - 1];
      }
    int longest = 0, start;
    for(int i = 0 ; i < n ; i++){
      for(int j = i, len = 1 ; j < n ; j++, len++){
        if(dp[i][j] && len > longest){
          longest = len;
          start = i;
        }
      }
    }
    return s.substr(start, longest);
  }
};

int main()
{
  Solution sol;
  cout << sol.longestPalindrome("babad") << endl;
  cout << sol.longestPalindrome("cbbd") << endl;
  cout << sol.longestPalindrome("ababababa") << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity