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
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, int> groups;
    vector<vector<string>> sol;
    for(int i = 0 ; i < (int)strs.size() ; i++){
      string cur = strs[i];
      sort(begin(cur), end(cur));
      if(groups.find(cur) == groups.end()){
        groups[cur] = sol.size();
        sol.push_back(vector<string>());
      }
      sol[groups[cur]].push_back(strs[i]);
    }
    return sol;
  }
};

int main()
{
  
  return 0;
}
