#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()



class Solution {
  int fact[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
public:
  string getPermutation(int n, int k) {
    --k;
    string s = "";
    vector<int> nums;
    for(int i = 1 ; i <= n ; i++)
      nums.push_back(i);
    for(int i = 0 ; i < n ; i++){
      for(int d = nums.size() - 1 ; d >= 0 ; d--){
        if(k >= fact[n - 1 - i] * d){
          s += char('0' + nums[d]);
          nums.erase(begin(nums) + d);
          k -= fact[n - 1 - i] * d;
          break;
        }
      }
    }
    return s;
  }
};

int main()
{
  Solution sol;
  for(int i = 1 ; i <= 6 ; i++)
    cout << sol.getPermutation(3, i) << endl;
  return 0;
}
