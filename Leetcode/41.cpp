#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0)
      return 1;
    for(int i = 0 ; i < n ; i++){
      while(nums[i] >= 0 && nums[i] < n && nums[i] != i && nums[nums[i]] != nums[i]){
        swap(nums[i], nums[nums[i]]);
      }
    }
    for(int i = 1 ; i < n ; i++)
      if(nums[i] != i)
        return i;
    if(nums[0] == n)
      return n + 1;
    return n;
  }
};

int main()
{
  Solution sol = Solution();
  vector<int> arr = {1,2,0};
  cout << sol.firstMissingPositive(arr) << endl;
  arr = {3,4,-1,1};
  cout << sol.firstMissingPositive(arr) << endl;
  arr = {7,8,9,11,12};
  cout << sol.firstMissingPositive(arr) << endl;
  return 0;
}
