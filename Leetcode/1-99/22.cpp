#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution {
  void solve(vector<string>& sol, string& cur, int sum, int n) {
    if((int)cur.size() >= n){
      if(sum == 0)
        sol.push_back(cur);
      return;
    }
    cur += '(';
    solve(sol, cur, sum + 1, n);
    if(sum > 0){
      cur.back() = ')';
      solve(sol, cur, sum - 1, n);
    }
    cur.pop_back();
  }
public:
  vector<string> generateParenthesis(int n) {
    vector<string> sol;
    string cur = "";
    solve(sol, cur, 0, 2 * n);
    return sol;
  }
};

int main()
{
  
  return 0;
}
