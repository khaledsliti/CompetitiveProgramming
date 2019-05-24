class Solution {
public:
  int search(vector<int>& nums, int target) {
    int n = (int)nums.size();
    int l = 0, r = n - 1, st = n - 1;
    while(l <= r){
      int mid = (l + r) / 2;
      if(nums[mid] <= nums[n - 1]){
        st = mid;
        r = mid - 1;
      }else{
        l = mid + 1;
      }
    }
    l = st, r = st + n - 1;
    while(l <= r){
      int mid = (l + r) / 2;
      if(nums[mid % n] == target)
        return mid % n;
      if(nums[mid % n] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return -1;
  }
};