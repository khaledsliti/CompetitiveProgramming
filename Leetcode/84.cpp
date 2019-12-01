#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = sz(heights);
    stack<int> st;
    st.push(-1);
    int max_area = 0;
    for(int i = 0 ; i < n ; i++){
      while(st.top() != -1 && heights[st.top()] > heights[i]){
        int cur = st.top();
        st.pop();
        max_area = max(max_area, heights[cur] * (i - st.top() - 1));
      }
      st.push(i);
    }
    while(st.top() != -1){
      int cur = st.top();
      st.pop();
      max_area = max(max_area, heights[cur] * (n - st.top() - 1));
    }
    return max_area;
  }
};

int main()
{
  vector<int> h = {2, 1, 5, 6, 2, 3};
  Solution sol = Solution();
  cout << sol.largestRectangleArea(h) << endl;
  return 0;
}
