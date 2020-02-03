#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution{
public:
  int maxArea(vector<int>& height) {
    int n = height.size();
    int best = 0;
    int left = 0, right = n - 1;
    while(left < right){
      best = max(best, (right - left) * min(height[left], height[right]));
      if(height[left] <= height[right])
        left++;
      else
        right--;
    }
    return best;
  }
};

int main()
{
  
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity