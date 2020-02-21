#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution {
  vector<vector<int>> sol;
  vector<int> cur;
  void solve(vector<int>& arr, int i, int target) {
    if(i >= (int)arr.size()) {
      if(target == 0) 
        sol.push_back(cur);
      return;
    }
    if(arr[i] <= target) {
      cur.push_back(arr[i]);
      solve(arr, i, target - arr[i]);
      cur.pop_back();
    }
    solve(arr, i + 1, target);
  }
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sol.clear();
    cur.clear();
    solve(candidates, 0, target);
    return sol;
  }
};

int main()
{
  return 0;
}
