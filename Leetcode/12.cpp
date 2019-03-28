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
  string intToRoman(int num) {
    string result = "";
    for(int i = (int)values.size() - 1;  i >= 0 ; i--){
      while(num >= values[i].first){
        num -= values[i].first;
        result += values[i].second;
      }
    }
    return result;
  }
};

int main(){
  Solution sol = Solution();
  vector<int> ints = { 3, 4, 9, 58, 1994 };
  for(int i = 0 ; i < (int)ints.size(); i++)
    cout << sol.intToRoman(ints[i]) << endl;
  return 0;
}