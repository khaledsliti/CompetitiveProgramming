#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while(T--){
    int n, a, b;
    cin >> a >> b >> n;
    int m = n % 3;
    if(m == 0) cout << a << endl;
    else if(m == 1) cout << b << endl;
    else cout << (a ^ b) << endl;
  }
  return 0;
}