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
  int removeDuplicates(vector<int>& arr) {
    if(arr.size() <= 2) return arr.size();
    int len = 2;
    for(int i = 2 ; i < (int) arr.size() ; i++){
      if(arr[len - 1] == arr[len - 2] && arr[len - 1] == arr[i])
        continue;
      arr[len++] = arr[i];
    }
    return len;
  }
};

int main()
{
  vector<int> v = {1,1,1,2,2,3};
  int len = Solution().removeDuplicates(v);
  cout << len << endl;
  for(int i = 0 ; i < sz(v); i++)
    cout << v[i] << " ";
  cout << endl;
  return 0;
}
