#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();
    int m = (int)matrix[0].size();
    int last_row = 0;
    for(int j = 0 ; j < m ; j++)
      if(matrix[n - 1][j] == 0)
        last_row = 1;
    for(int i = 0 ; i < n - 1 ; i++){ 
      bool contains_zero = 0;
      for(int j = 0 ; j < m ; j++){
        if(matrix[i][j] == 0){
          contains_zero = 1;
          matrix[n - 1][j] = 0;
        }
      }
      if(contains_zero)
        for(int j = 0 ; j < m ; j++)
          matrix[i][j] = 0;
    }
    for(int j = 0 ; j < m ; j++){
      if(matrix[n - 1][j] == 0)
        for(int i = 0 ; i < n - 1 ; i++)
          matrix[i][j] = 0;
    }
    if(last_row)
      for(int j = 0 ; j < m ; j++)
        matrix[n - 1][j] = 0;
  }
};

int main(){
  return 0;
}