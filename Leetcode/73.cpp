#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();
    int m = (int)matrix[0].size();
    for(int i = 0 ; i < n ; i++){
      bool contains_zero = 0;
      for(int j = 0 ; j < m ; j++){
        if(matrix[i][j] == 0){
          contains_zero = 1;
          for(int k = i - 1 ; k >= 0 ; k--)
            matrix[k][j] = 0;
        }
      }
      if(contains_zero)
        for(int j = 0 ; j < m ; j++)
          matrix[i][j] = 0;
    }
    for(int j = 0 ; j < m ; j++){
      if(matrix[0][j] == 0)
        for(int i = 1 ; i < n ; i++)
          matrix[i][j] = 0;
    }
  }
};

int main(){
  return 0;
}