#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution {
  int cubes[3][3], rows[9], cols[9];
  bool add(int& s, int c) {
    if((s >> c) & 1)
      return false;
    s |= (1 << c);
    return true;
  }
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0 ; i < 9 ; i++)
      for(int j = 0 ; j < 9 ; j++){
        char cur = board[i][j];
        if(cur == '.')
          continue;
        int d = cur - '0';
        if(!add(cubes[i / 3][j / 3], d) || !add(rows[i], d) || !add(cols[j], d))
          return false;
      }
    return true;
  }
};

int main()
{
  
  return 0;
}
