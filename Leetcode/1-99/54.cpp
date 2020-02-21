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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> sol;
    int n = matrix.size();
    if(n == 0)
      return vector<int>();
    int m = matrix[0].size();
    if(m == 0)
      return vector<int>();
    int up = 0, down = n - 1;
    int left = 0, right = m - 1;
    while(up < down && left < right){
      for(int j = left ; j < right ; j++)
        sol.push_back(matrix[up][j]);
      for(int i = up ; i < down ; i++)
        sol.push_back(matrix[i][right]);
      for(int j = right ; j > left ; j--)
        sol.push_back(matrix[down][j]);
      for(int i = down ; i > up ; i--)
        sol.push_back(matrix[i][left]);
      up++;
      down--;
      left++;
      right--;
    }
    for(int i = up ; i <= down ; i++)
      for(int j = left ; j <= right ; j++)
        sol.push_back(matrix[i][j]);
    return sol;
  }
};

int main()
{
  
  return 0;
}
