class Solution {
  bool isDigit(char c){
    return c >= '0' && c <= '9';
  }
public:
  string decodeString(string s){
    stack<pair<int, string>> st;
    st.push(make_pair(1, ""));
    for(int i = 0 ; i < (int)s.size() ; i++){
      int c = s[i];
      if(!isDigit(c) && c != ']'){
        st.top().second += c;
      }else if(isDigit(c)) {
        int k = 0;
        while(isDigit(s[i]))
          k = k * 10 + s[i++] - '0';
        st.push(make_pair(k, ""));
      }else{
        auto cur = st.top();
        st.pop();
        while(cur.first--)
          st.top().second += cur.second;
      }
    }
    return st.top().second;
  }
};
