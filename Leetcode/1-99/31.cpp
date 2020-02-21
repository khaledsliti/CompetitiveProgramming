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
  void nextPermutation(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1)
      return;
    for(int i = n - 2 ; i >= 0 ; i--){
      if(arr[i] < arr[i + 1]){
        for(int j = n - 1 ; j > i ; j--)
          if(arr[j] > arr[i]){
            swap(arr[i], arr[j]);
            break;
          }
        reverse(begin(arr) + i + 1, end(arr));
        return;
      }
    }
    reverse(begin(arr), end(arr));
  }
};

int main()
{
  vector<int> v = { 3, 2, 1 };
  Solution sol;
  sol.nextPermutation(v);
  for(auto x : v)
    cout << x << " ";
  cout << endl;
  return 0;
}
