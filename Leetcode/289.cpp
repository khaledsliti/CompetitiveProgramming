#include <bits/stdc++.h>
using namespace std;

void print(const vector<vector<int>>& board){
  for(int i = 0 ; i < (int)board.size(); i++){
    for(int j = 0 ; j < (int)board[i].size() ; j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << "---------" << endl;
}

class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    int n = board.size();
    int m = board[0].size();
    for(int i = 0 ; i < n ; i++){
      for(int j = m - 1 ; j >= 0 ; j--){
        int tmp = 0;
        if(i > 0)
          tmp = (board[i - 1][j] << 3) & ((1 << 9) - 1);
        for(int k = j - 2, p = 0 ; k <= j ; k++, p++){
          int c = (k >= 0 ? board[i][k] : 0);
          if(c)
            tmp |= (1 << p);
        }
        board[i][j] = tmp;
      }
    }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        int tmp = board[min(n - 1, i + 1)][min(m - 1, j + 1)];
        if(i == n - 1)
          tmp = (tmp << 3) & ((1 << 9) - 1);
        if(j == m - 1)
          tmp = ((tmp & ~((1 << 3) | (1 << 6))) >> 1);
        int old = (tmp >> 4) & 1;
        int cnt = 0;
        while(tmp)
          tmp -= tmp & -tmp, cnt++;
        board[i][j] = (cnt == 3 || (old && cnt == 4));
      }
    }
  }
};

int main(){
  vector<vector<int>> board = {
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 1, 1, 1 },
    { 0, 0, 0 }
  };
  Solution sol = Solution();
  sol.gameOfLife(board);
  print(board);
  return 0;
}