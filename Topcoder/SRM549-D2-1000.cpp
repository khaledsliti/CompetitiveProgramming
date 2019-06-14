/********************************************************************************************************
  Author: RedStone

  Idea:
    Let dp[mask] be the solution if we have already learned all spells present in the mask.
    The cost of choosing the next spell to learn is the number of spells that we didn't learn them yet and must be learned before the next.
    We can calculate the cost in O(1) using a preprocessing on the spellChart and bit operations.

  Complexity:
    Time: O(N 2^N)
    Memory: O(2^N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class OrderOfTheHats{
  int n;
  vector<int> before;
  vector<int> dp;

  int solve(int doneSoFar)
  {
    if(doneSoFar + 1 == (1 << n))
      return 0;
    int& r = dp[doneSoFar];
    if(r != -1)
      return r;
    r = 1e9;
    for(int nxt = 0 ; nxt < n ; nxt++)
      if(!(doneSoFar & (1 << nxt))){
        int notDone = ((1 << n) - 1) & ~doneSoFar;
        int cost = __builtin_popcount(notDone & before[nxt]);
        r = min(r, cost + solve(doneSoFar | (1 << nxt)));
      }
    return r;
  }
public:
  int minChanged(vector<string> spellChart){
    n = spellChart.size();
    before.clear();
    before.resize(n, 0);
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++)
        if(spellChart[i][j] == 'Y'){
          before[j] |= (1 << i);
        }
    }
    dp.clear();
    dp.resize((1 << n), -1);
    return solve(0);
  }
};

int main()
{
  OrderOfTheHats sol = OrderOfTheHats();
  cout << sol.minChanged({"Y"}) << endl;
  cout << sol.minChanged({"NYN", "NNY", "NNN"}) << endl;
  cout << sol.minChanged({"NYN", "NNY", "YNN"}) << endl;
  cout << sol.minChanged({"NYYYYYY", "YNYYYYY", "YYNYYYY", "YYYNYYY", "YYYYNYY", "YYYYYNY", "YYYYYYN"}) << endl;
  return 0;
}
