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
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int d = 0 ; d < n / 2 ; d++) {
      for(int j = d ; j < n - d - 1 ; j++) {
        int& a = matrix[d][j];
        int& b = matrix[j][n - 1 - d];
        int& c = matrix[n - 1 - d][n - 1 - j];
        int& e = matrix[n - 1 - j][d];
        int tmp = b;
        b = a;
        a = e;
        e = c;
        c = tmp;
      }
    }
  }
};

int main()
{
  vector<vector<int>> mat = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };
  Solution sol;
  sol.rotate(mat);
  for(int i = 0 ; i < (int)mat.size() ; i++){
    for(int j = 0 ; j < (int)mat.size() ; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }
  return 0;
}
