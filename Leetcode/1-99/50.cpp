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
  double myPow(double x, int n) {
    if(n == 0)
      return 1;
    if(n < 0)
      return 1 / (x * myPow(x, -(n + 1)));
    double r = myPow(x, n >> 1);
    r *= r;
    if(n & 1)
      r *= x;
    return r;
  }
};

int main()
{
  
  return 0;
}
