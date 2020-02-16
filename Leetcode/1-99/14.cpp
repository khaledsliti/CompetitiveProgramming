class Solution{
public:
  string longestCommonPrefix(vector<string>& strs){
    if(strs.size() == 0)
      return "";
    string res = strs[0];
    for(int i = 1 ; i < (int) strs.size() ; i++){
      if(strs[i].size() < res.size())
        res = res.substr(0, strs[i].size());
      for(int j = 0 ;  j < (int) res.size() ; j++){
        if(res[j] != strs[i][j]){
          res = res.substr(0, j);
          break;
        }
      }
    }
    return res;
  }
};
