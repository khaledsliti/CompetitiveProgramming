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
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> sol;
    for(int i = 0 ; i < (int)intervals.size() ; i++){
      if(intervals[i][0] > newInterval[1] || intervals[i][1] < newInterval[0]){
        sol.push_back(intervals[i]);
      }else{
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
      }
    }
    sol.push_back(newInterval);
    for(int i = sol.size() - 2 ; i >= 0 ; i--){
      if(sol[i][0] > sol[i + 1][0])
        swap(sol[i], sol[i + 1]);
    }
    return sol;
  }
};

int main()
{
  
  return 0;
}
