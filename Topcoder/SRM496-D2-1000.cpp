#include <bits/stdc++.h>
using namespace std;

class PalindromfulString{
  int n, m, k;
  long long solve(int cur, int sets, vector<int>& val){
    if(cur >= n){
      int pal = 0;
      for(int i = 0 ; i + m <= n ; i++){
        int l = i, r = i + m - 1;
        bool palindrom = true;
        while(l <= r && palindrom){
          if(val[l] != val[r])
            palindrom = false;
          l++, r--;
        }
        pal += palindrom;
      }
      if(pal < k)
        return 0LL;
      long long res = 1LL;
      for(int i = 0 ; i < sets ; i++)
        res *= 26LL - i;
      return res;
    }
    val[cur] = sets;
    long long res = solve(cur + 1, sets + 1, val);
    for(int s = 0 ; s < sets ; s++){
      val[cur] = s;
      res += solve(cur + 1, sets, val);
    }
    return res;
  }
public:
  long long count(int n, int m, int k){
    this->n = n;
    this->m = m;
    this->k = k;
    vector<int> val(n);
    val[0] = 0;
    return solve(1, 1, val);
  }
};

int main()
{
  PalindromfulString sol = PalindromfulString();
  cout << sol.count(2, 2, 1) << endl;
  cout << sol.count(2, 2, 0) << endl;
  cout << sol.count(3, 2, 1) << endl;
  cout << sol.count(4, 4, 1) << endl;
  cout << sol.count(7, 3, 3) << endl;
  cout << sol.count(11, 5, 2) << endl;
  return 0;
}