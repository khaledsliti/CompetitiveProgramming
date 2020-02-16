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
  string convert(string s, int rows) {
    rows = min(rows, (int)s.size());
    if(rows <= 1)
      return s;
    string res = "";
    for(int r = 0 ; r < rows ; r++){
      for(int p = r ; p < (int)s.size() ; p += 2 * (rows - 1)){
        res += s[p];
        if(r > 0 && r + 1 < rows && p + 2 * (rows - r -1) < (int)s.size())
          res += s[p + 2 * (rows - r -1)];
      }
    }
    return res;
  }
};

int main()
{
  Solution sol;
  cout << sol.convert("A", 1) << endl;
  cout << sol.convert("A", 2) << endl;
  cout << sol.convert("PAYPALISHIRING", 3) << endl;
  cout << sol.convert("PAYPALISHIRING", 4) << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity