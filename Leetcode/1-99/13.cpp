#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<pair<int, string>> values = {
    { 1, "I" },
    { 4, "IV" },
    { 5, "V" },
    { 9, "IX" },
    { 10, "X" },
    { 40, "XL" },
    { 50, "L" },
    { 90, "XC"},
    { 100, "C" },
    { 400, "CD" },
    { 500, "D" },
    { 900, "CM" },
    { 1000, "M" }
  };
public:
  int romanToInt(string s) {
    int result = 0;
    int j = values.size() - 1;
    for(int i = 0 ; i < (int)s.size() ; ){
      for( ; j >= 0 ; j--){
        int len = values[j].second.size();
        if(i + len <= (int)s.size() && values[j].second == s.substr(i, len)){
          result += values[j].first;
          i += len;
          break;
        }
      }
    }
    return result;
  }
};

int main(){
  Solution sol = Solution();
  vector<string> tests = { "LVIII", "MCMXCIV" };
  for(int i = 0 ; i < (int)tests.size(); i++)
    cout << sol.romanToInt(tests[i]) << endl;
  return 0;
}