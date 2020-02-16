#include <bits/stdc++.h>
using namespace std;

class Solution {
  int n, m;
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  vector<vector<char>> board;
  vector<vector<int>> vis;

  bool good(int nx, int ny){
    return nx >= 0 && nx < n && ny >= 0 && ny < m;
  }

  bool solve(int x, int y, int idx, string& s){
    if(idx >= (int)s.size())
      return true;
    char need = s[idx];
    for(int k = 0 ; k < 4 ; k++){
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(good(nx, ny) && !vis[nx][ny] && board[nx][ny] == need){
        vis[nx][ny] = 1;
        if(solve(nx, ny, idx + 1, s))
          return true;
        vis[nx][ny] = 0;
      }
    }
    return false;
  }

public:
  bool exist(vector<vector<char>>& board, string word){
    if(!word.size())
      return false;
    n = (int)board.size();
    if(n == 0) return false;
    m = (int)board[0].size();
    if(m == 0) return false;
    this->board = board;
    vis.clear();
    vis.resize(n, vector<int>(m, 0));
    for(int i = 0 ; i < n ; i++)
      for(int j = 0 ; j < m ; j++){
        vis[i][j] = 1;
        if(board[i][j] == word[0] && solve(i, j, 1, word))
          return true;
        vis[i][j] = 0;
      }
    return false;
  }
};

int main()
{
  Solution sol = Solution();
  vector<vector<char>> board = {
    { 'A','B','C','E' },
    { 'S','F','C','S' },
    { 'A','D','E','E' }
  };

  cout << sol.exist(board, "ABCCED") << endl;
  return 0;
}