class Solution {
  int getNext(string& input, int& i, bool& isFile){
    int len = (int)input.size();
    isFile = false;
    int res = 0;
    while(i < len && input[i] != '\n'){
      isFile = isFile || (input[i] == '.');
      ++res;
      ++i;
    }
    i++;
    return res;
  }
  int getTabs(string& input, int& i){
    int r = 0;
    int len = (int)input.size();
    while(i < len && input[i] == '\t'){
      i++;
      r++;
    }
    return r;
  }
public:
  int lengthLongestPath(string input){
    if(input.size() == 0)
      return 0;
    if(input.back() != '\n')
      input += '\n';
    stack<int> st;
    int ans = 0;
    int i = 0;
    while(i < (int)input.size()){
      int tabs = getTabs(input, i);
      while(st.size() > tabs)
        st.pop();
      bool isFile;
      int len = getNext(input, i, isFile);
      int nxt_len = (st.empty() ? 0 : st.top() + 1) + len;
      if(isFile)
        ans = max(ans, nxt_len);
      else
        st.push(nxt_len);
    }
    return ans;
  }
};
// "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext\n"