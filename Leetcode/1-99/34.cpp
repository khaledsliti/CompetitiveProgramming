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
    int first = lower_bound(begin(arr), end(arr), target) - begin(arr);
    int last = lower_bound(begin(arr), end(arr), target + 1) - begin(arr) - 1;
    if(first > last) return {-1, -1};
    return {first, last};
  }
};

int main()
{
  
  return 0;
}
