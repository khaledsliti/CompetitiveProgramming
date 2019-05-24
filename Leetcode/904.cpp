class Solution {

public:
  int totalFruit(vector<int>& tree) {
    int n = (int)tree.size();
    unordered_map<int, int> mp;
    int j = 0, ans = 0;
    for(int i = 0 ; i < n ; i++){
      mp[tree[i]]++;
      while(mp.size() > 2){
        if(!--mp[tree[j]])
          mp.erase(tree[j]);
        j++;
      }
      ans = max(ans, i - j + 1);
    }
    return ans;
  }
};