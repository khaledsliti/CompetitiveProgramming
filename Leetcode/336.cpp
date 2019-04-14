class Solution{
  bool isPalin(string& s, int i, int j){
    for(int k = 0 ; k <= j - i ; k++)
      if(s[i + k] != s[j - k])
        return false;
    return true;
  }
public:
  vector<vector<int>> palindromePairs(vector<string>& words){
    vector<vector<int>> result;
    unordered_map<string, vector<int>> cnt, cnt_rev;
    for(int i = 0 ; i < (int)words.size() ; i++)
      cnt[words[i]].push_back(i), cnt_rev[words[i]].push_back(i);
    for(int i = 0 ; i < (int)words.size() ; i++){
      // some prefix
      string pref = "";
      for(int j = 0 ; j < (int)words[i].size() - 1 ; j++){
        pref += words[i][j];
        if(cnt_rev.count(pref) && isPalin(words[i], j + 1, words[i].size() - 1))
          for(auto pos : cnt_rev[pref])
            result.push_back({ i, pos });
      }
      // hole string
      string tmp = words[i];
      reverse(tmp.begin(), tmp.end());
      if(cnt.count(tmp))
        for(auto pos : cnt[tmp])
          if(pos != i)
            result.push_back({ i, pos });
      // with empty string
      if(isPalin(words[i], 0, words[i].size() - 1) && cnt.count(""))
        for(auto pos : cnt[""])
          if(pos != i){
            result.push_back({ i, pos });
            if(words[i].size())
              result.push_back({ pos, i });
          }
      // some suffix
      string suff = "";
      for(int j = (int)words[i].size() - 1 ; j > 0 ; j--){
        suff += words[i][j];
        if(cnt.count(suff) && isPalin(words[i], 0, j - 1))
          for(auto pos : cnt[suff])
            result.push_back({ pos, i });
      }
    }
    return result;
  }
};
