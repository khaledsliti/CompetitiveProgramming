class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp.insert({0, 1});
    int ans = 0;
    int pref = 0;
    for(int i = 0 ; i < (int) nums.size() ; i++){
      pref += nums[i];
      int need = pref - k;
      if(mp.count(need))
        ans += mp[need];
      mp[pref]++;
    }
    return ans;
  }
};