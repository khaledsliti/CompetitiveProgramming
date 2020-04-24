#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    for(int v = 3 ; v <= n ; v = (v << 1) | 1) {
      if(n % v == 0) {
        cout << n / v << endl;
        break;
      }
    }
  }
  return 0;
}