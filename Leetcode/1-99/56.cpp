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
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(!intervals.size())
      return intervals;
    vector<int> idx;
    for(int i = 0 ; i < (int) intervals.size() ; i++)
      idx.push_back(i);
    sort(idx.begin(), idx.end(), [&intervals](const int a, const int& b) {
      if(intervals[a][0] != intervals[b][0])
        return intervals[a][0] < intervals[b][0];
      return intervals[a][1] < intervals[b][1];
    });
    vector<vector<int>> sol;
    for(int i = 0 ; i < (int)intervals.size() ; i++) {
      int r = intervals[idx[i]][1];
      int j = i;
      while(j < (int)intervals.size() && intervals[idx[j]][0] <= r){
        r = max(r, intervals[idx[j]][1]);
        j++;
      }
      sol.push_back({intervals[idx[i]][0], r});
      i = j - 1;
    }
    return sol;
  }
};

int main()
{
  
  return 0;
}
