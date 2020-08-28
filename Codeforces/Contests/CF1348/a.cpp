#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    int a = (1 << n), b = (1 << (n >> 1));
    for(int i = 1 ; i < n / 2 ; i++) {
      a |= (1 << i);
      b |= (1 << (n / 2 + i));
    }
    cout << a - b << endl;
  }
  return 0;
}
