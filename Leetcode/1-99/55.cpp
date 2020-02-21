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
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return false;
    int mx = 0;
    for(int i = 0 ; i < n ; i++){
      if(mx < i)
        return false;
      mx = max(mx, i + nums[i]);
    }
    return true;
  }
};

int main()
{
  
  return 0;
}
