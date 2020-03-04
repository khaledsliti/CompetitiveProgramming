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
  void sortColors(vector<int>& nums) {
    int l = 0, k = 0, r = nums.size() - 1;
    while(l <= r){
      if(nums[l] == 0)
        swap(nums[l++], nums[k++]);
      else if(nums[l] == 1)
        l++;
      else
        swap(nums[l], nums[r--]);
    }
  }
};

int main()
{
  vector<int> v = {2};
  Solution().sortColors(v);
  for(auto x : v) cout << x << " ";
  return 0;
}
