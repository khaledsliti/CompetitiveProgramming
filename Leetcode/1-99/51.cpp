#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution{
  int n;
  vector<vector<bool>> board;
  vector<vector<string>> sol;
  void solve(int row, int d, int v, int a) {
    if(row >= n){
      vector<string> cur(n);
      for(int i = 0 ; i < n ; i++){
        cur[i] = "";
        for(int j = 0 ; j < n ; j++)
          cur[i] += board[i][j] ? "Q" : ".";
      }
      sol.push_back(cur);
      return;
    }
    for(int col = 0; col < n; col++){
      if(!(d & (1 << col)) && !(v & (1 << col)) && !(a & (1 << col))){
        board[row][col] = 1;
        solve(row + 1, (d | (1 << col)) >> 1, v | (1 << col), (a | (1 << col)) << 1);
        board[row][col] = 0;
      }
    }
  }
public:
  vector<vector<string>> solveNQueens(int n) {
    this->n = n;
    board.clear();
    board.resize(n, vector<bool>(n, 0));
    solve(0, 0, 0, 0);
    return sol;
  }
};

int main()
{
  Solution sol = Solution();
  vector<vector<string>> ans = sol.solveNQueens(5);
  cout << ans.size() << endl;
  for(int i = 0 ; i < ans.size() ; i++){
    for(int j = 0 ; j < (int) ans[i].size(); j++)
      cout << ans[i][j] << endl;
    cout << endl;
  }
  return 0;
}
