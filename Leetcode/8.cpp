#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    int i = 0;
    int n = str.size();
    while(i < n && str[i] == ' ')
      ++i;
    int sign = 1;
    if(i < n && str[i] == '-')
      ++i, sign = -1;
    else if(i < n && str[i] == '+')
      ++i;
    int result = 0;
    while(i < n && str[i] >= '0' && str[i] <= '9'){
      int c = str[i] - '0';
      if(result > INT_MAX / 10 || (result == INT_MAX / 10 && sign * c > INT_MAX % 10))
        return INT_MAX;
      if(result < INT_MIN / 10 || (result == INT_MIN / 10 && sign * c < INT_MIN % 10))
        return INT_MIN;
      result = result * 10 + sign * c;
      i++;
    }
    return result;
  }
};

int main(){
  return 0;
}