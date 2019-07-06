#include<bits/stdc++.h>
using namespace std;

class Solution {
  bool check(int x, int y) {
    if((x + y + 1) % 2)
      return false;
    int b = (x + y + 1) / 2;
    int a = x - b;
    return a >= 0 && b >= 0 && a <= b;
  }
public:
  int consecutiveNumbersSum(int N) {
    int ans = 0;
    for(int i = 1 ; i * i <= 2 * N ; i++){
      if((2 * N) % i == 0){
        int j = 2 * N / i;
        ans += i < j && check(j, i);
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol = Solution();
  cout << sol.consecutiveNumbersSum(4) << endl;
  cout << sol.consecutiveNumbersSum(5) << endl;
  cout << sol.consecutiveNumbersSum(9) << endl;
  cout << sol.consecutiveNumbersSum(15) << endl;
  cout << sol.consecutiveNumbersSum(93003) << endl;
  return 0;
}