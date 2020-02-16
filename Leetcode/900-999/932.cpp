#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define DEB(x) cout << #x << " = " << x << endl;

template<class T>
ostream& operator<<(ostream& cout, vector<T> v){
  for(int i = 0 ; i < (int)v.size() ; i++){
    if(i) cout << " ";
    cout << v[i];
  }
  return cout;
}

class Solution {
  unordered_map<int, vector<int>> ans;
public:
  Solution(){
    ans[0] = {};
    ans[1] = {1};
  }
  vector<int> beautifulArray(int N){
    if(ans.count(N))
      return ans[N];
    for(int x : beautifulArray(N / 2))
      ans[N].push_back(2 * x);
    for(int x : beautifulArray((N + 1) / 2))
      ans[N].push_back(2 * x - 1);
    return ans[N];
  }
};

int main()
{
  Solution sol = Solution();
  for(int i = 5 ; i < 10 ; i++)
    cout << sol.beautifulArray(i) << endl;
  return 0;
}
