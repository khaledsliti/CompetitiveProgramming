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
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> sol;
    sort(begin(nums), end(nums));
    do{
      sol.push_back(nums);
    }while(next_permutation(begin(nums), end(nums)));
    return sol;
  }
};

int main()
{
  
  return 0;
}
