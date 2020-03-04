// We only fail when we stop trying
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
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int n = trips.size();
    vector<pair<pair<int, int>, int>> pts;
    for(int i = 0 ; i < n ; i++) {
      pts.push_back({{trips[i][1], 1}, trips[i][0]});
      pts.push_back({{trips[i][2], -1}, trips[i][0]});
    }
    sort(pts.begin(), pts.end());
    int cur = 0;
    for(int i = 0 ; i < (int) pts.size() ; i++) {
      cur += pts[i].first.second * pts[i].second;
      if(cur > capacity)
        return false;
    }
    return true;
  }
};

int main()
{
  
  return 0;
}
