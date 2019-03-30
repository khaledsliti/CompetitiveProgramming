class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& T) {
    int n = (int) T.size();
    stack<short> st;
    for(int i = 0 ; i < n ; i++){
      while(!st.empty() && T[st.top()] < T[i]){
        T[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }
    while(!st.empty())
      T[st.top()] = 0, st.pop();
    return T;
  }
};
