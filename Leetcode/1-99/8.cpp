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
  int myAtoi(string str) {
    int cursor = 0;
    while(cursor < (int)str.size() && str[cursor] == ' ')
      cursor++;
    if(cursor >= (int)str.size())
      return 0;
    int sign = 1;
    if(str[cursor] == '+') cursor++;
    else if(str[cursor] == '-') cursor++, sign = -1;
    int value = 0;
    int min_lim = INT_MIN / 10;
    int max_lim = INT_MAX / 10;
    int d_min = -(INT_MIN % 10);
    int d_max = INT_MAX % 10;
    while(cursor < (int)str.size() && str[cursor] >= '0' && str[cursor] <= '9'){
      int d = str[cursor++] - '0';
      if(sign == 1){
        if(value < max_lim || (value == max_lim && d <= d_max)){
          value = value * 10 + d;
        }else{
          return INT_MAX;
        }
      }else{
        if(value > min_lim || (value == min_lim && d <= d_min)){
          value = value * 10 - d;
        }else{
          return INT_MIN;
        }
      }
    }
    return value;
  }
};

int main()
{
  Solution sol;
  cout << sol.myAtoi("-2147483648") << endl;
  cout << sol.myAtoi("-2147483649") << endl;
  cout << sol.myAtoi("2147483647aDSAD") << endl;
  cout << sol.myAtoi("2147483648aDSAD") << endl;
  cout << sol.myAtoi("-91283472332") << endl;
  cout << sol.myAtoi("words and 987") << endl;
  cout << sol.myAtoi("4193 with words") << endl;
  cout << sol.myAtoi("   -49  ") << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity