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
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(); if(!n) return false;
    int m = matrix[0].size(); if(!m) return false;
    int l = 0, r = m * n - 1;
    while(l <= r){
      int mid = (l + r) >> 1;
      int i = mid / m;
      int j = mid % m;
      if(matrix[i][j] == target)
        return true;
      if(matrix[i][j] > target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return false;
  }
};

int main()
{
  
  return 0;
}
