#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution {
  vector<string> alp = {
    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
  };
  void solve(vector<string>& sol, string& cur, const string& digits, int pos) {
    if(pos >= (int)digits.size()){
      sol.push_back(cur);
      return;
    }
    int idx = digits[pos] - '2';
    for(int ch = 0 ; ch < (int)alp[idx].size(); ++ch) {
      cur.push_back(alp[idx][ch]);
      solve(sol, cur, digits, pos + 1);
      cur.pop_back();
    }
  }
public:
  vector<string> letterCombinations(string digits) {
    vector<string> sol;
    if(digits.size() == 0)
      return sol;
    string cur = "";
    solve(sol, cur, digits, 0);
    return sol;
  }
};

int main()
{
  Solution sol;
  auto ans = sol.letterCombinations("23");
  for(auto& s : ans)
    cout << s << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity