// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class MountainArray {
public:
  int get(int index);
  int length();
};

class Solution {
  // O(1) calls
  unordered_map<int, int> cash;
  int get(MountainArray &mountainArr, int n, int idx) {
    if(idx < 0 || idx >= n)
      return -1;
    if(cash.find(idx) == cash.end())
      cash[idx] = mountainArr.get(idx);
    return cash[idx];
  }
  // O(log n) calls
  int getPeek(MountainArray &mountainArr, int n) {
    int l = 0, r = n - 1;
    while(l <= r) {
      int mid = l + (r - l) / 2;
      int midValue = get(mountainArr, n, mid);
      int left = get(mountainArr, n, mid - 1);
      int right = get(mountainArr, n, mid + 1);
      if(midValue > left && midValue > right)
        return mid;
      if(midValue > left) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return -1;
  }
  // O(log n) calls
  bool search(MountainArray &mountainArr, int n, int target, int left, int right, int& index) {
    int add = left <= right ? 1 : -1;
    while(left * add <= right * add) {
      int mid = left + add * (abs(right - left) / 2);
      int midValue = get(mountainArr, n, mid);
      if(midValue == target) {
        index = mid;
        return true;
      } else if(midValue > target) {
        right = mid - add;
      } else {
        left = mid + add;
      }
    }
    index = -1;
    return false;
  }
public:
  // O(log n) calls
  int findInMountainArray(int target, MountainArray &mountainArr) {
    cash.clear();
    int n = mountainArr.length();
    int peek = getPeek(mountainArr, n);
    if(peek == -1)
      return -1;
    int index = -1;
    if(peek > 0 && search(mountainArr, n, target, 0, peek - 1, index))
      return index;
    search(mountainArr, n, target, n - 1, peek, index);
    return index;
  }
};

int main() {

  return 0;
}
