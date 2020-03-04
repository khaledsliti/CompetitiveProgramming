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
  vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> sol;
    for(int mask = 0 ; mask < (1 << n) ; mask++) {
      vector<int> cur;
      for(int i = 0 ; i < n ; i++)
        if(mask & (1 << i))
          cur.push_back(nums[i]);
      sol.push_back(cur);
    }
    return sol;
  }
};

int main()
{
  
  return 0;
}
