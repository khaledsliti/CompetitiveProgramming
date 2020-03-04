// We only fail when we stop trying
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
  vector<int> prevPermOpt1(vector<int>& arr) {
    int n = arr.size();
    for(int i = n - 2 ; i >= 0 ; i--) {
      if(arr[i] > arr[i + 1]) {
        int j = i + 1;
        while(j < n && arr[j] < arr[i])
          j++;
        --j;
        while(arr[j - 1] == arr[j]) --j;
        swap(arr[i], arr[j]);
        break;
      }
    }
    return arr;
  }
};

int main()
{
  
  return 0;
}
