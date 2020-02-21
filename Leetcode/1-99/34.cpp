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
  vector<int> searchRange(vector<int>& arr, int target) {
    int n = arr.size();
    int first = n, left = 0, right = n - 1;
    while(left <= right) {
      int mid = (left + right) >> 1;
      if(arr[mid] >= target) {
        first = mid;
        right = mid - 1;
      }else {
        left = mid + 1;
      }
    }
    if(first >= n || arr[first] != target)
      return {-1, -1};
    int last = first;
    left = first + 1, right = n - 1;
    while(left <= right) {
      int mid = (left + right) >> 1;
      if(arr[mid] <= target) {
        last = mid;
        left = mid + 1;
      }else{
        right = mid - 1;
      }
    }
    return { first, last };
  }
};

int main()
{
  
  return 0;
}
