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
  int threeSumClosest(vector<int>& arr, int target) {
    int sol = arr[0] + arr[1] + arr[2];
    sort(begin(arr), end(arr));
    int n = arr.size();
    for(int i = 0 ; i < n ; i++){
      if(i > 0 && arr[i - 1] == arr[i])
        continue;
      int need = target - arr[i];
      int j = i + 1, k = n - 1;
      while(j < k){
        if(j > i + 1 && arr[j] == arr[j - 1]){
          j++;
          continue;
        }
        if(k + 1 < n && arr[k + 1] == arr[k]){
          k--;
          continue;
        }
        int have = arr[j] + arr[k];
        int tot = arr[i] + have;
        if(abs(tot - target) < abs(sol - target))
          sol = tot;
        if(have >= need)
          k--;
        else
          j++;
      }
    }
    return sol;
  }
};

int main()
{
  
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity