#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()



int main()
{
  int tests;
  cin >> tests;
  while(tests--){
    long long a, b;
    cin >> a >> b;
    if((2 * a - b) < 0 || (2 * a - b) % 3 != 0){
      cout << "NO" << endl;
      continue;
    }
    long long y = (2 * a - b) / 3;
    if(a - 2 * y < 0){
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
  }
  return 0;
}
