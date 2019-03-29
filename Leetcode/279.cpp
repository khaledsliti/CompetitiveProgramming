#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numSquares(int n){
    int sqrt_n = sqrt(n);
    if(sqrt_n * sqrt_n == n)
      return 1;
    for(int i = 1 ; i * i <= n ; i++){
      int j = n - i * i;
      int sqrt_j = sqrt(j);
      if(sqrt_j * sqrt_j == j)
        return 2;
    }
    int tmp = n;
    while((tmp & 3) == 0)
      tmp >>= 2;
    if((tmp & 7) == 7)
      return 4;
    return 3;
  }
};

int main(){
  Solution sol = Solution();
  cout << sol.numSquares(12) << endl;
  cout << sol.numSquares(13) << endl;
  return 0;
}