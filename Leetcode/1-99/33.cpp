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
  int search(vector<int>& arr, int target) {
    if(int n = arr.size(); n > 0){
      int first = 0, l = 1, r = n - 1;
      while(l <= r){
        int mid = (l + r) >> 1;
        if(arr[mid] < arr[0]){
          r = mid - 1;
          first = mid;
        }else{
          l = mid + 1;
        }
      }
      int last = first + n - 1;
      while(first <= last){
        int mid = (first + last) >> 1;
        int idx = mid % n;
        if(arr[idx] == target)
          return idx;
        if(arr[idx] > target)
          last = mid - 1;
        else
          first = mid + 1;
      }
    }
    return -1;
  }
};

int main()
{
  return 0;
}
