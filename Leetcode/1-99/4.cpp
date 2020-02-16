class Solution {
  int GetValue(vector<int>& A, int index){
    if(index < 0)
      return INT_MIN;
    if(index >= (int) A.size())
      return INT_MAX;
    return A[index];
  }
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    vector<int> A(nums1), B(nums2);
    int n = (int) A.size();
    int m = (int) B.size();
    int need = (n + m) / 2;
    int l = max(0, need - m), r = min(n, need);
    int ans = n;
    while(l <= r){
      int mid = (l + r) / 2;
      int i = n - mid;
      int j = m - need + mid;
      int v1 = GetValue(A, i);
      int v2 = GetValue(B, j - 1);
      if(v1 >= v2){
        ans = mid;
        l = mid + 1;
      }else{
        r = mid - 1;
      }
    }
    int i = n - ans;
    int j = m - need + ans;
    double median = max(GetValue(A, i - 1), GetValue(B, j - 1));
    if((n + m) % 2 == 0)
      median = ( median + min(GetValue(A, i), GetValue(B, j)) ) / 2.0;
    return median;
  }
};