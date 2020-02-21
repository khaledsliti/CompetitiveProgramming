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
  vector<pair<int, int>> arr;
  void solve(int i, int target) {
    if(i >= (int)arr.size()) {
      if(target == 0) 
        sol.push_back(cur);
      return;
    }
    solve(i + 1, target);
    int added = 0;
    for(int occ = 1 ; occ <= arr[i].second ; occ++){
      if(target >= arr[i].first * occ) {
        cur.push_back(arr[i].first);
        solve(i + 1, target - arr[i].first * occ);
        added++;
      }
    }
    while(added--)
      cur.pop_back();
  }
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(begin(candidates), end(candidates));
    sol.clear();
    arr.clear();
    for(int i = 0 ; i < (int)candidates.size() ; i++){
      if(i == 0 || arr.back().first != candidates[i]){
        arr.push_back({candidates[i], 1});
      }else{
        arr.back().second++;
      }
    }
    solve(0, target);
    return sol;
  }
};

int main()
{
  
  return 0;
}
